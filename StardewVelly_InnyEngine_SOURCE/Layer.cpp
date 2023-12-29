#include "Layer.h"

namespace in
{
	Layer::Layer()
		: mGameObjects{}
	{
	}

	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}
	
	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}
	
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			if(gameObj->IsActive() == false)
				continue;

			gameObj->Update();
		}
	}
	
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			if (gameObj->IsActive() == false)
				continue;

			gameObj->LateUpdate();
		}
	}
	
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		vector<GameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteGameObjects(deleteObjects);
	}
	
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}

	void Layer::EraseGameObject(GameObject* eraseGameObj)
	{
		erase_if(mGameObjects,
			[=](GameObject* gameObj)
			{
				return gameObj == eraseGameObj;
			});
	}

	void Layer::findDeadGameObjects(vector<GameObject*>& gameObjs)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			GameObject::eState active = gameObj->GetState();
			if (active == GameObject::eState::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void Layer::deleteGameObjects(vector<GameObject*> deleteObjs)
	{
		for (GameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void Layer::eraseDeadGameObject()
	{
		erase_if(mGameObjects,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}