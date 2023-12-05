#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManger.h"
#include "Transform.h"
#include "Layer.h"

namespace in
{
	class Object
	{
	public:
		template<typename T>
		static T* Instantiate(eLayerType type)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManger::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template<typename T>
		static T* Instantiate(eLayerType type, SetVector position)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManger::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPos(position);

			return gameObject;
		}
	};
}