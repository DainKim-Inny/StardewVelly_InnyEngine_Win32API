#include "FarmScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "Mine_B1_Scene.h"
#include "PlayerScript.h"
#include "BoxCollider2D.h"

using namespace std;

namespace in
{
	FarmScene::FarmScene()
		: mFarm_Bg(nullptr)
		, mFarm_Player(nullptr)
		, mFarm_Clock(nullptr)
		, mFarm_QuickSlot(nullptr)
		, mFarm_EnergyBar(nullptr)
		, mFarm_Stone1(nullptr)
		, mFarm_Stone2(nullptr)
	{
	}

	FarmScene::~FarmScene()
	{
	}
	
	void FarmScene::Initialize()
	{
		// main Camera
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, SetVector(700.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// BackGround 추가
		{
			mFarm_Bg = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(-10.0f, 0.0f));
			SpriteRenderer* bgSr = mFarm_Bg->AddComponent<SpriteRenderer>();

			Texture* bgTexture = Resources::Find<Texture>(L"Farm_BG");
			bgSr->SetTexture(bgTexture);
			bgSr->SetSize(SetVector(2.1f, 2.1f));
		}

		// Clock 추가
		{
			mFarm_Clock = Object::Instantiate<GameObject>(eLayerType::UI, SetVector(1170.0f, 80.0f));
			SpriteRenderer* clockSr = mFarm_Clock->AddComponent<SpriteRenderer>();

			Texture* clockTexture = Resources::Find<Texture>(L"Farm_Clock");
			clockSr->SetTexture(clockTexture);
		}

		// QuickSlot 추가
		{
			mFarm_QuickSlot = Object::Instantiate<GameObject>(eLayerType::UI, SetVector(415.0f, 680.0f));
			SpriteRenderer* slotSr = mFarm_QuickSlot->AddComponent<SpriteRenderer>();

			Texture* slotTexture = Resources::Find<Texture>(L"Farm_QuickSlot");
			slotSr->SetTexture(slotTexture);
		}

		// EnergyBar 추가
		{
			mFarm_EnergyBar = Object::Instantiate<GameObject>(eLayerType::UI, SetVector(1330.0f, 579.0f));
			SpriteRenderer* energybarSr = mFarm_EnergyBar->AddComponent<SpriteRenderer>();

			Texture* energybarTexture = Resources::Find<Texture>(L"Farm_EnergyBar");
			energybarSr->SetTexture(energybarTexture);
			energybarSr->SetSize(SetVector(0.9f, 0.9f));
		}

		// Player 추가
		{
			mFarm_Player = Object::Instantiate<Player>(eLayerType::Player, SetVector(500.0f, 500.0f));
			PlayerScript* plScript = mFarm_Player->AddComponent<PlayerScript>();

			BoxCollider2D* collider = mFarm_Player->AddComponent<BoxCollider2D>();
			collider->SetOffset(SetVector(-134.0f, -155.0f));

			//cameraComp->SetTarget(mFarm_Player);

			Texture* playerTexture = Resources::Find<Texture>(L"Farm_Player");
			Texture* playerTexture_Front = Resources::Find<Texture>(L"Farm_PlayerFront");
			Texture* playerTexture2 = Resources::Find<Texture>(L"Farm_Player2");
			
			Animator* player_animator = mFarm_Player->AddComponent<Animator>();

			// Idle
			{
				player_animator->CreateAnimation(L"Idle", playerTexture
					, SetVector(2000.0f, 250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 1, 0.1f);
			}

			// Walk
			{
				player_animator->CreateAnimation(L"RightWalk", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.08f);
				player_animator->CreateAnimation(L"RightWalkStop", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 1, 0.08f);

				player_animator->CreateAnimation(L"LeftWalk", playerTexture
					, SetVector(1500.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.08f);
				player_animator->CreateAnimation(L"LeftWalkStop", playerTexture
					, SetVector(1500.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 1, 0.08f);

				player_animator->CreateAnimation(L"UpWalk", playerTexture
					, SetVector(0.0f, 250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 8, 0.08f);
				player_animator->CreateAnimation(L"UpWalkStop", playerTexture
					, SetVector(0.0f, 250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 1, 0.08f);

				player_animator->CreateAnimation(L"DownWalk", playerTexture_Front
					, SetVector(0.0f, 1.0f), SetVector(250.0f, 281.0f), SetVector::Zero, 6, 0.08f);
				player_animator->CreateAnimation(L"DownWalkStop", playerTexture_Front
					, SetVector(0.0f, 1.0f), SetVector(250.0f, 281.0f), SetVector::Zero, 1, 0.08f);
			}

			// UsingAxes
			{
				player_animator->CreateAnimation(L"LeftUsingAxes", playerTexture
					, SetVector(500.0f, 750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"RightUsingAxes", playerTexture2
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"UpUsingAxes", playerTexture
					, SetVector(1750.0f, 750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 4, 0.1f);

				player_animator->CreateAnimation(L"DownUsingAxes", playerTexture
					, SetVector(750.0f, 500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);
			}

			// UsingHoes
			{
				player_animator->CreateAnimation(L"LeftUsingHoes", playerTexture
					, SetVector(0.0f, 1250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"RightUsingHoes", playerTexture
					, SetVector(1750.0f, 1000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"UpUsingHoes", playerTexture
					, SetVector(750.0f, 1000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 4, 0.1f);

				player_animator->CreateAnimation(L"DownUsingHoes", playerTexture
					, SetVector(0.0f, 1000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 3, 0.1f);
			}

			// UsingScythe
			{
				player_animator->CreateAnimation(L"LeftUsingScythe", playerTexture
					, SetVector(1500.0f, 1500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"RightUsingScythe", playerTexture
					, SetVector(0.0f, 1500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"UpUsingScythe", playerTexture
					, SetVector(0.0f, 1750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"DownUsingScythe", playerTexture
					, SetVector(1250.0f, 1250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);
			}

			// UsingPickaxes
			{
				player_animator->CreateAnimation(L"LeftUsingPickaxes", playerTexture2
					, SetVector(0.0f, 250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"RightUsingPickaxes", playerTexture
					, SetVector(0.0f, 3750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"UpUsingPickaxes", playerTexture
					, SetVector(1750.0f, 3500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"DownUsingPickaxes", playerTexture
					, SetVector(0.0f, 3500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 7, 0.1f);
			}

			// GiveWater
			{
				player_animator->CreateAnimation(L"LeftGiveWater", playerTexture
					, SetVector(0.0f, 2250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 4, 0.2f);

				player_animator->CreateAnimation(L"RightGiveWater", playerTexture
					, SetVector(1500.0f, 1750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.2f);

				player_animator->CreateAnimation(L"UpGiveWater", playerTexture
					, SetVector(1250.0f, 2250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 3, 0.3f);

				player_animator->CreateAnimation(L"DownGiveWater", playerTexture
					, SetVector(0.0f, 2000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 12, 0.1f);
			}

			// PickUpWalk
			{
				player_animator->CreateAnimation(L"LeftPickUpWalk", playerTexture
					, SetVector(0.0f, 2500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"RightPickUpWalk", playerTexture
					, SetVector(1250.0f, 2500.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"UpPickUpWalk", playerTexture
					, SetVector(0.0f, 2750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);

				player_animator->CreateAnimation(L"DownPickUpWalk", playerTexture
					, SetVector(1750.0f, 2750.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 5, 0.1f);
			}

			// Eatting
			{
				player_animator->CreateAnimation(L"Eatting", playerTexture
					, SetVector(0.0f, 4000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 10, 0.1f);
			}

			// Fishing -> 이미지 편집 필요
			{
				player_animator->CreateAnimation(L"LeftFishing", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"RightFishing", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"UpFishing", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"DownFishing", playerTexture
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);
			}

			// Hunting
			{
				player_animator->CreateAnimation(L"LeftHunting", playerTexture
					, SetVector(0.0f, 3250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"RightHunting", playerTexture
					, SetVector(1500.0f, 3000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);

				player_animator->CreateAnimation(L"UpHunting", playerTexture
					, SetVector(1500.0f, 3250.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 3, 0.1f);

				player_animator->CreateAnimation(L"DownHunting", playerTexture
					, SetVector(0.0f, 3000.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 6, 0.1f);
			}

			player_animator->PlayeAnimation(L"Idle", true);

			mFarm_Player->GetComponent<Transform>()->SetScale(SetVector(0.55f, 0.55f));
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

		SetVector mousePos = Input::GetMousePosition();

		if (Input::GetKeyDown(eKeyCode::MouseRB) 
			&& 1200.0f<= mousePos.x && mousePos.x<=1260.0f
			&& 550.0f<= mousePos.y && mousePos.y<=630.0f )
		{
			SceneManager::LoadScene(L"Mine_Lobby_Scene");
		}
	}
	
	void FarmScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"FarmScene";
		TextOut(hdc, 0, 0, str, 9);
	}
}