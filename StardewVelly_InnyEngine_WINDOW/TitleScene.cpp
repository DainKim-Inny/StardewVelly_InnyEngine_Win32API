#include "TitleScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "FarmScene.h"
#include "Animator.h"
#include "buttonScript.h"
#include "BirdScript.h"

namespace in
{
	TitleScene::TitleScene()
		: mbg(nullptr), mlogo(nullptr)
		, mNewButton(nullptr), mLoadButton(nullptr)
		, mExitButton(nullptr)
		, mBird1(nullptr), mBird2(nullptr)
		, mTopLeaf(nullptr), mBottomLeaf(nullptr)
		, mQuestion(nullptr)
	{
	}

	TitleScene::~TitleScene()
	{
	}
	
	void TitleScene::Initialize()
	{
		// 배경 추가
		{
			mbg = Object::Instantiate<GameObject>(eLayerType::BackGround);

			SpriteRenderer* sr1 = mbg->AddComponent<SpriteRenderer>();
			Texture* bg = Resources::Find<Texture>(L"Intro_BG");
			sr1->SetTexture(bg);
			sr1->SetSize(SetVector(2.3f, 2.0f));
		}

		// StardewValley 로고 추가
		{
			mlogo = Object::Instantiate<GameObject>(eLayerType::Logo_Bottom, SetVector(370.0f, 100.0f));

			SpriteRenderer* sr2 = mlogo->AddComponent<SpriteRenderer>();
			Texture* logo = Resources::Find<Texture>(L"Intro_Logo");
			sr2->SetTexture(logo);
			sr2->SetSize(SetVector(1.8f, 1.8f));
		}

		// NewButton 추가
		{
			mNewButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(420.0f, 900.0f));

			mNewButton->AddComponent<buttonScript>();

			Texture* newButtomTexture = Resources::Find<Texture>(L"Intro_Button");
			Animator* newButtom_animator = mNewButton->AddComponent<Animator>();
			newButtom_animator->CreateAnimation(L"Intro_Newbutton", newButtomTexture
				, SetVector(0.0f, 0.0f), SetVector(73.5f, 57.67f), SetVector::Zero, 1, 0.1f);

			newButtom_animator->PlayeAnimation(L"Intro_Newbutton");

			mNewButton->GetComponent<Transform>()->SetScale(SetVector(2.2f, 2.2f));
		}

		// LoadButton 추가
		{
			mLoadButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(690.0f, 900.0f));

			mLoadButton->AddComponent<buttonScript>();

			Texture* loadButtomTexture = Resources::Find<Texture>(L"Intro_Button");
			Animator* loadButtom_animator = mLoadButton->AddComponent<Animator>();
			loadButtom_animator->CreateAnimation(L"Intro_Loadbutton", loadButtomTexture
				, SetVector(0.0f, 57.67f), SetVector(73.5f, 57.67f), SetVector::Zero, 1, 0.1f);

			loadButtom_animator->PlayeAnimation(L"Intro_Loadbutton");

			mLoadButton->GetComponent<Transform>()->SetScale(SetVector(2.2f, 2.2f));
		}

		// ExitButton 추가
		{
			mExitButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(950.0f, 900.0f));

			mExitButton->AddComponent<buttonScript>();

			Texture* exitButtomTexture = Resources::Find<Texture>(L"Intro_Button");
			Animator* exitButtom_animator = mExitButton->AddComponent<Animator>();
			exitButtom_animator->CreateAnimation(L"Intro_Exitbutton", exitButtomTexture
				, SetVector(0.0f, 115.34f), SetVector(73.5f, 57.67f), SetVector::Zero, 1, 0.1f);

			exitButtom_animator->PlayeAnimation(L"Intro_Exitbutton");

			mExitButton->GetComponent<Transform>()->SetScale(SetVector(2.2f, 2.2f));
		}

		// Bird1 추가
		{
			mBird1 = Object::Instantiate<GameObject>(eLayerType::BackGroundObject_Middle, SetVector(1150.0f, 350.0f));

			mBird1->AddComponent<BirdScript>();

			Texture* bird1Texture = Resources::Find<Texture>(L"Intro_Bird");
			Animator* bird1_animator = mBird1->AddComponent<Animator>();
			bird1_animator->CreateAnimation(L"Intro_Bird1", bird1Texture
				, SetVector(0.0f, 0.0f), SetVector(26.0f, 18.0f), SetVector::Zero, 4, 0.2f);

			bird1_animator->PlayeAnimation(L"Intro_Bird1", true);

			mBird1->GetComponent<Transform>()->SetScale(SetVector(2.0f, 2.0f));
		}

		// Bird2 추가
		{
			mBird2 = Object::Instantiate<GameObject>(eLayerType::BackGroundObject_Middle, SetVector(1250.0f, 450.0f));

			mBird2->AddComponent<BirdScript>();

			Texture* bird2Texture = Resources::Find<Texture>(L"Intro_Bird");
			Animator* bird2_animator = mBird2->AddComponent<Animator>();
			bird2_animator->CreateAnimation(L"Intro_Bird2", bird2Texture
				, SetVector(26.0f, 0.0f), SetVector(26.0f,18.0f), SetVector::Zero, 3, 0.2f);

			bird2_animator->PlayeAnimation(L"Intro_Bird2", true);

			mBird2->GetComponent<Transform>()->SetScale(SetVector(2.0f, 2.0f));
		}

		// TopLeaf 추가
		{
			mTopLeaf = Object::Instantiate<GameObject>(eLayerType::Logo_Top, SetVector(411.0f, 134.0f));

			Texture* topleafTexture = Resources::Find<Texture>(L"Intro_TopLeaf");
			Animator* topleaf_animator = mTopLeaf->AddComponent<Animator>();
			topleaf_animator->CreateAnimation(L"Intro_TopLeaf", topleafTexture
				, SetVector(0.0f, 0.0f), SetVector(22.0f, 18.0f), SetVector::Zero, 3, 0.3f);

			topleaf_animator->PlayeAnimation(L"Intro_TopLeaf", true);

			mTopLeaf->GetComponent<Transform>()->SetScale(SetVector(1.6f, 1.6f));
		}

		// BottomLeaf 추가
		{
			mBottomLeaf = Object::Instantiate<GameObject>(eLayerType::Logo_Top, SetVector(971.0f, 296.0f));

			Texture* bottomleafTexture = Resources::Find<Texture>(L"Intro_ButtomLeaf");
			Animator* bottomleaf_animator = mBottomLeaf->AddComponent<Animator>();
			bottomleaf_animator->CreateAnimation(L"Intro_ButtomLeaf", bottomleafTexture
				, SetVector(0.0f, 0.0f), SetVector(27.0f, 21.0f), SetVector::Zero, 3, 0.3f);

			bottomleaf_animator->PlayeAnimation(L"Intro_ButtomLeaf", true);

			mBottomLeaf->GetComponent<Transform>()->SetScale(SetVector(2.0f, 2.0f));
		}

		// Question Logo 추가
		{
			mQuestion = Object::Instantiate<GameObject>(eLayerType::Logo_Top, SetVector(1300.0f, 650.0f));

			Texture* questionTexture = Resources::Find<Texture>(L"Intro_Question");
			Animator* question_animator = mQuestion->AddComponent<Animator>();
			question_animator->CreateAnimation(L"Intro_Question", questionTexture
				, SetVector(0.0f, 0.0f), SetVector(22.5f, 25.0f), SetVector::Zero, 1, 0.1f);

			question_animator->PlayeAnimation(L"Intro_Question");

			mQuestion->GetComponent<Transform>()->SetScale(SetVector(2.0f, 2.0f));
		}


		Scene::Initialize();
	}
	
	void TitleScene::Update()
	{
		Scene::Update();
	}
	
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		SetVector mousePos = Input::GetMousePosition();

		if (Input::GetKeyDown(eKeyCode::MouseRB))
		{
			SceneManager::LoadScene(L"FarmScene");
		}
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"TitleScene";
		TextOut(hdc, 0, 0, str, 10);
	}
}