#pragma once
#include "CommonHeader.h"
#include "BoxCollider2D.h"

using namespace std;

namespace in
{
	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initailize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Clear();

		// Layer���� �浹 Check -> �浹 ���� True / False Check ����
		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);

		// Active Scene �� �浹 Check
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		
		// �浹 ���� �Լ�
		static void ColliderCollision(Collider* left, Collider* right);

		// �浹�� �ϴ����� ���� �������� ǥ���ϱ� ���� �Լ� ����
		static bool Intersect(Collider* left, Collider* right);

	private:
		// (eLayerType::Max ũ�� * eLayerType::Max) ��ŭ�� �迭 ����
		static bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];

		// ������ �浹 ������ �ľ��� ���� unordered_map(hash table ó�� ���) ����
		static unordered_map<UINT64, bool> mCollisionMap;
	};
}