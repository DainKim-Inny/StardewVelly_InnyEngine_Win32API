#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"

using namespace std;

namespace in
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, const eLayerType type);

	private:
		void CreateLayers();

	private:
		vector<Layer*> mLayers;
	};
}