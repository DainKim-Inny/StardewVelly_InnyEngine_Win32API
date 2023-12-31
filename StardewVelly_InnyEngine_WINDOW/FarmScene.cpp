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
#include "Monster.h"
#include "Mine_B1_Scene.h"
#include "PlayerScript.h"
#include "BoxCollider2D.h"
#include "CollisionManager.h"
#include "MonsterScript.h"

using namespace std;

namespace in
{
	FarmScene::FarmScene()
		: mFarm_Bg(nullptr)
		, mFarm_Player(nullptr)
		, mFarm_Monster(nullptr)
	{
	}

	FarmScene::~FarmScene()
	{
	}
	
	void FarmScene::Initialize()
	{
		// Layer끼리 충돌 Check 등록
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

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
			bgSr->SetSize(SetVector(2.5f, 2.5f));
		}

		// Player 추가
		{
			mFarm_Player = Object::Instantiate<Player>(eLayerType::Player, SetVector(400.0f, 400.0f));
			Object::DontDestroyOnLoad(mFarm_Player);
			
			PlayerScript* plScript = mFarm_Player->AddComponent<PlayerScript>();

			BoxCollider2D* playerCollider = mFarm_Player->AddComponent<BoxCollider2D>();
			playerCollider->SetOffset(SetVector(-70.0f, -60.0f));

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
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 7, 0.08f);
				player_animator->CreateAnimation(L"DownWalkStop", playerTexture_Front
					, SetVector(0.0f, 0.0f), SetVector(250.0f, 250.0f), SetVector::Zero, 1, 0.08f);
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

			mFarm_Player->GetComponent<Transform>()->SetScale(SetVector(0.6f, 0.6f));
		}

		// Slime 추가
		{
			mFarm_Monster = Object::Instantiate<Monster>(eLayerType::Monster, SetVector(500.0f, 500.0f));
			mFarm_Monster->AddComponent<MonsterScript>();

			BoxCollider2D* monsterCollider = mFarm_Monster->AddComponent<BoxCollider2D>();
			monsterCollider->SetOffset(SetVector(-30.0f, -30.0f));

			Texture* slimeTexture = Resources::Find<Texture>(L"Mine_B1_Slime");

			Animator* slime_animator = mFarm_Monster->AddComponent<Animator>();
			slime_animator->CreateAnimation(L"SlimeMove", slimeTexture
				, SetVector(0.0f, 0.0f), SetVector(64.0f, 64.0f), SetVector::Zero, 7, 0.25f);

			slime_animator->PlayeAnimation(L"SlimeMove", true);

			mFarm_Monster->GetComponent<Transform>()->SetScale(SetVector(0.7f, 0.7f));
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

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TileMapToolScene");
		}
	}
	
	void FarmScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"FarmScene";
		TextOut(hdc, 0, 0, str, 9);
	}
}