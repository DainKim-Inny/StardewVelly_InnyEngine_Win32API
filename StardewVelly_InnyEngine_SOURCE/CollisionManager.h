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

		// Layer끼리 충돌 Check -> 충돌 여부 True / False Check 가능
		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);

		// Active Scene 내 충돌 Check
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		
		// 충돌 로직 함수
		static void ColliderCollision(Collider* left, Collider* right);

		// 충돌을 하는지에 대한 연산결과를 표현하기 위한 함수 생성
		static bool Intersect(Collider* left, Collider* right);

	private:
		// (eLayerType::Max 크기 * eLayerType::Max) 만큼의 배열 생성
		static bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];

		// 누구랑 충돌 중인지 파악을 위한 unordered_map(hash table 처럼 사용) 생성
		static unordered_map<UINT64, bool> mCollisionMap;
	};
}