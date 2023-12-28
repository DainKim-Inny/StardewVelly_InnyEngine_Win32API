#include "CollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Collider.h"
#include "Transform.h"
#include "Application.h"

using namespace std;

namespace in
{
	bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initailize()
	{
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();  // Active Scene 호출

		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);  // 해당 Scene 내 충돌 Check
				}
			}
		}
	}
	
	void CollisionManager::LateUpdate()
	{
	}
	
	void CollisionManager::Render(HDC hdc)
	{
	}
	
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			
			Collider* leftcol = left->GetComponent<Collider>();
			if (leftcol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;

				Collider* rightcol = right->GetComponent<Collider>();

				if (rightcol == nullptr)
					continue;

				if (left == right)
					continue;

				ColliderCollision(leftcol, rightcol);
			}
		}
	}
	
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		// 두 충돌체 번호로 가져온 ID 확인하여 CollisionID Setting
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌 정보 검색 -> 충돌 정보가 없는 상태라면 충돌 정보 생성
		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 Check
		if (Intersect(left, right))
		{
			// 최초 충돌 시
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else  // 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// 충돌을 하지 않은 상태
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		SetVector leftPos = leftTr->GetPosition() + left->GetOffset();
		SetVector rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1,1 일 때 기본크기가 100 픽셀
		SetVector leftSize = left->GetSize() * 50.0f;
		SetVector rightSize = right->GetSize() * 50.0f;

		// AABB 충돌
		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}

		return false;
	}
}