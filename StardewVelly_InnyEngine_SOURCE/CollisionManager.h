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

		// Layer���� �浹 Check -> �浹 ���� True / False Check ����
		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enalbe);

		// Active Scene �� �浹 Check
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		
		// �浹 ���� �Լ�
		static void ColliderCollision(Collider* left, Collider* right);

	private:
		// (eLayerType::Max ũ�� * eLayerType::Max) ��ŭ�� �迭 ����
		static bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
	};
}
