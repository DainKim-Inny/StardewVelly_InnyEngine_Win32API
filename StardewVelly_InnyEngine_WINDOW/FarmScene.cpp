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
#include "Animator.h"

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
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, SetVector(900.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// BackGround 추가
		{
			mFarm_Bg = Object::Instantiate<GameObject>(eLayerType::BackGround);
			SpriteRenderer* sr = mFarm_Bg->AddComponent<SpriteRenderer>();

			Texture* bgTexture = Resources::Find<Texture>(L"Farm_BG");
			sr->SetTexture(bgTexture);
			sr->SetSize(SetVector(2.7f, 2.7f));
		}

		// Player 추가
		{
			mFarm_Player = Object::Instantiate<Player>(eLayerType::Player, SetVector(920.0f, 500.0f));
			mFarm_Player->AddComponent<PlayerScript>();

			Texture* playerTexture = Resources::Find<Texture>(L"Farm_Player");
			
			Animator* player_animator = mFarm_Player->AddComponent<Animator>();

			// Idle
			player_animator->CreateAnimation(L"Idle", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			// Walk
			{
				player_animator->CreateAnimation(L"RightWalk", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"LeftWalk", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"UpWalk", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"DownWalk", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);
			}

			// UsingAxes
			player_animator->CreateAnimation(L"UsingAxes", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			// UsingHoes
			player_animator->CreateAnimation(L"UsingHoes", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			// UsingScythe
			player_animator->CreateAnimation(L"UsingScythe", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			// GiveWater
			player_animator->CreateAnimation(L"GiveWater", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			// PickUp
			player_animator->CreateAnimation(L"PickUp", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			// Eatting
			player_animator->CreateAnimation(L"Eatting", playerTexture
				, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

			player_animator->PlayeAnimation(L"Idle", false);

			mFarm_Player->GetComponent<Transform>()->SetScale(SetVector(0.8f, 0.8f));
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