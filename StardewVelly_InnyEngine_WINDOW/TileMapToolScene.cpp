#include "TileMapToolScene.h"
#include "Object.h"
#include "Resources.h"
#include "Texture.h"
#include "Camera.h"
#include "Renderer.h"
#include "Tile.h"
#include "TileMapRenderer.h"

namespace in
{
	TileMapToolScene::TileMapToolScene()
	{
	}

	TileMapToolScene::~TileMapToolScene()
	{
	}
	
	void TileMapToolScene::Initialize()
	{
		//GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, SetVector(0.0f, 0.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;

		Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
		TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();

		tmr->SetTexture(Resources::Find<Texture>(L"TileMap_SpringFarm"));

		Scene::Initialize();
	}
	
	void TileMapToolScene::Update()
	{
		Scene::Update();
	}
	
	void TileMapToolScene::LateUpdate()
	{
		Scene::Update();
	}
	
	void TileMapToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// 격자 무늬 추가 (기존 size에서 2배 키운 크기로 격자 생성)
		for (int i = 0; i < 50; i++)
		{
			MoveToEx(hdc, (16*2) * i, 0, NULL);
			LineTo(hdc, (16 * 2) * i, 5000);
		}

		for (int i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, (16 * 2) * i, NULL);
			LineTo(hdc, 5000, (16 * 2) * i);
		}
	}
	
	void TileMapToolScene::OnEnter()
	{
		Scene::Update();
	}
	
	void TileMapToolScene::OnExit()
	{
		Scene::Update();
	}
}