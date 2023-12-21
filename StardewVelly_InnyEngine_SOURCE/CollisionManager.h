#pragma once
#include "CommonHeader.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"

using namespace std;

namespace in
{
	class CollisionManager
	{
	public:
		static void Initailize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		// Layer끼리 충돌 Check -> 충돌 여부 True / False Check 가능
		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enalbe);

		// Active Scene 내 충돌 Check
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		
		// 충돌 로직 함수
		static void ColliderCollision(Collider* left, Collider* right);

	private:
		// (eLayerType::Max 크기 * eLayerType::Max) 만큼의 배열 생성
		static bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
	};
}
