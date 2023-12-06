#include "TitleScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "IntroScene.h"
#include "Animator.h"

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
			sr1->SetSize(SetVector(2.2f, 1.7f));
		}

		// StardewValley 로고 추가
		{
			mlogo = Object::Instantiate<GameObject>(eLayerType::Logo_Bottom, SetVector(370.0f, 90.0f));

			SpriteRenderer* sr2 = mlogo->AddComponent<SpriteRenderer>();
			Texture* logo = Resources::Find<Texture>(L"Intro_Logo");
			sr2->SetTexture(logo);
			sr2->SetSize(SetVector(1.7f, 1.7f));
		}

		// NewButton 추가
		{
			mNewButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(370.0f, 450.0f));

			Texture* newButtomTexture = Resources::Find<Texture>(L"Intro_Button");
			Animator* newButtom_animator = mNewButton->AddComponent<Animator>();
			newButtom_animator->CreateAnimation(L"Intro_Newbutton", newButtomTexture
				, SetVector(0.0f, 0.0f), SetVector(73.5f, 57.67f), SetVector::Zero, 2, 0.1f);

			newButtom_animator->PlayeAnimation(L"Intro_Newbutton");

			//SpriteRenderer* sr3 = mNewButton->AddComponent<SpriteRenderer>();
			//Texture* NewButton = Resources::Find<Texture>(L"Intro_NewButton");
			//sr3->SetTexture(NewButton);
			//sr3->SetSize(SetVector(2.5f, 2.5f));
		}

		// LoadButton 추가
		{
			mLoadButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(620.0f, 450.0f));

			Texture* loadButtomTexture = Resources::Find<Texture>(L"Intro_Button");
			Animator* loadButtom_animator = mLoadButton->AddComponent<Animator>();
			loadButtom_animator->CreateAnimation(L"Intro_Loadbutton", loadButtomTexture
				, SetVector(0.0f, 57.67f), SetVector(73.5f, 57.67f), SetVector::Zero, 2, 0.1f);

			loadButtom_animator->PlayeAnimation(L"Intro_Loadbutton");
		}

		// ExitButton 추가
		{
			mExitButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(860.0f, 450.0f));

			Texture* exitButtomTexture = Resources::Find<Texture>(L"Intro_Button");
			Animator* exitButtom_animator = mExitButton->AddComponent<Animator>();
			exitButtom_animator->CreateAnimation(L"Intro_Exitbutton", exitButtomTexture
				, SetVector(0.0f, 57.67f), SetVector(73.5f, 57.67f), SetVector::Zero, 2, 0.1f);

			exitButtom_animator->PlayeAnimation(L"Intro_Exitbutton");
		}

		// Bird1 추가
		{
			mBird1 = Object::Instantiate<GameObject>(eLayerType::BackGroundObject_Middle, SetVector(1150.0f, 350.0f));

			Texture* bird1Texture = Resources::Find<Texture>(L"Intro_Bird");
			Animator* bird1_animator = mBird1->AddComponent<Animator>();
			bird1_animator->CreateAnimation(L"Intro_Bird1", bird1Texture
				, SetVector(0.0f, 0.0f), SetVector(26.0f, 18.0f), SetVector::Zero, 4, 0.1f);

			bird1_animator->PlayeAnimation(L"Intro_Bird1", true);
		}

		// Bird2 추가
		{
			mBird2 = Object::Instantiate<GameObject>(eLayerType::BackGroundObject_Middle, SetVector(1250.0f, 450.0f));

			Texture* bird2Texture = Resources::Find<Texture>(L"Intro_Bird");
			Animator* bird2_animator = mBird2->AddComponent<Animator>();
			bird2_animator->CreateAnimation(L"Intro_Bird2", bird2Texture
				, SetVector(26.0f, 0.0f), SetVector(26.0f,18.0f), SetVector::Zero, 3, 0.1f);

			bird2_animator->PlayeAnimation(L"Intro_Bird2", true);
		}

		// TopLeaf 추가
		{
			mTopLeaf = Object::Instantiate<GameObject>(eLayerType::Logo_Top, SetVector(410.0f, 115.0f));

			Texture* topleafTexture = Resources::Find<Texture>(L"Intro_TopLeaf");
			Animator* topleaf_animator = mTopLeaf->AddComponent<Animator>();
			topleaf_animator->CreateAnimation(L"Intro_TopLeaf", topleafTexture
				, SetVector(0.0f, 0.0f), SetVector(22.0f, 18.0f), SetVector::Zero, 3, 0.3f);

			topleaf_animator->PlayeAnimation(L"Intro_TopLeaf", true);
		}

		// BottomLeaf 추가
		{
			mBottomLeaf = Object::Instantiate<GameObject>(eLayerType::Logo_Top, SetVector(940.0f, 300.0f));

			Texture* bottomleafTexture = Resources::Find<Texture>(L"Intro_ButtomLeaf");
			Animator* bottomleaf_animator = mBottomLeaf->AddComponent<Animator>();
			bottomleaf_animator->CreateAnimation(L"Intro_ButtomLeaf", bottomleafTexture
				, SetVector(0.0f, 0.0f), SetVector(27.0f, 21.0f), SetVector::Zero, 3, 0.3f);

			bottomleaf_animator->PlayeAnimation(L"Intro_ButtomLeaf", true);
		}

		// Question Logo 추가
		{
			mQuestion = Object::Instantiate<GameObject>(eLayerType::Logo_Top, SetVector(1000.0f, 600.0f));

			Texture* questionTexture = Resources::Find<Texture>(L"Intro_Question");
			Animator* question_animator = mQuestion->AddComponent<Animator>();
			question_animator->CreateAnimation(L"Intro_Question", questionTexture
				, SetVector(0.0f, 0.0f), SetVector(22.5f, 25.0f), SetVector::Zero, 2, 0.1f);

			question_animator->PlayeAnimation(L"Intro_Question");
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

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManger::LoadScene(L"IntroScene");
		}
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"TitleScene";
		TextOut(hdc, 0, 0, str, 10);
	}
}