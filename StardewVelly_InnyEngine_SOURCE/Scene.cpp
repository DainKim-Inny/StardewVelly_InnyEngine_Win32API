#include "Scene.h"
#include "CollisionManager.h"

namespace in
{
	Scene::Scene()
		: mLayers{}
	{
		CreateLayers();
	}

	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}
	
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}
	
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}
	
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}
	
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}
	
	void Scene::AddGameObject(GameObject* gameObject, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}

	void Scene::EraseGameObjects(GameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameObj);
	}

	void Scene::CreateLayers()
	{
		mLayers.resize((UINT)eLayerType::Max);

		for (int i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{
		CollisionManager::Clear();
	}
}