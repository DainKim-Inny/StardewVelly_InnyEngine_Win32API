#include "FarmScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"

namespace in
{
	FarmScene::FarmScene()
		: mFarm_Bg(nullptr)
		, mFarm_Player(nullptr)
	{
	}

	FarmScene::~FarmScene()
	{
	}
	
	void FarmScene::Initialize()
	{
		// main Camera
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, SetVector(720.0f, 370.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// BackGround 추가
		{
			mFarm_Bg = Object::Instantiate<GameObject>(eLayerType::BackGround);
			SpriteRenderer* sr = mFarm_Bg->AddComponent<SpriteRenderer>();

			Texture* bgTexture = Resources::Find<Texture>(L"Farm_BG");
			sr->SetTexture(bgTexture);
			sr->SetSize(SetVector(1.11f, 0.66f));
		}

		// Player 추가
		{
			mFarm_Player = Object::Instantiate<Player>(eLayerType::Player, SetVector(200.0f, 200.0f));
			SpriteRenderer* sr = mFarm_Player->AddComponent<SpriteRenderer>();

			mFarm_Player->AddComponent<PlayerScript>();

			Texture* playerTexture = Resources::Find<Texture>(L"Farm_Player");
			sr->SetTexture(playerTexture);
			sr->SetSize(SetVector(0.3f, 0.3f));
		}

		Scene::Initialize();
	}
	
	void FarmScene::Update()
	{
		Scene::Update();
	}
	
	void FarmScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	
	void FarmScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"FarmScene";
		TextOut(hdc, 0, 0, str, 9);
	}
}