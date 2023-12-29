#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
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
			gameObject->SetLayerType(type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template<typename T>
		static T* Instantiate(eLayerType type, SetVector position)
		{
			T* gameObject = new T();
			gameObject->SetLayerType(type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPos(position);

			return gameObject;
		}

		static void Destroy(GameObject* gameObj)
		{
			if (gameObj == nullptr)
				return;

			gameObj->Death();
		}

		static void DontDestroyOnLoad(GameObject* gameObjects)
		{
			Scene* activeScene = SceneManager::GetActiveScene();
			// ���� ������, ���� ������Ʈ �����ش�
			activeScene->EraseGameObjects(gameObjects);

			// �ش� ���� ������Ʈ�� DontDestroyObjectOnLoae Scene���� �־��ش�
			Scene* dontDstroyOnLoad = SceneManager::GetDontDestroyOnLoad();
			dontDstroyOnLoad->AddGameObject(gameObjects, gameObjects->GetLayerType());
		}
	};
}