#include "CollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Collider.h"

using namespace std;

namespace in
{
	bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};

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
		// 충돌 로직 작성
	}
}