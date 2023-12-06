#include "IntroScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "Time.h"
#include "Animator.h"

namespace in
{
	IntroScene::IntroScene()
		: mTitle_Charactor(nullptr)
		, mTitle_Creator(nullptr)
		, mTime(0.0f)
	{
	}

	IntroScene::~IntroScene()
	{
	}
	
	void IntroScene::Initialize()
	{

		// Logo 추가
		{
			mTitle_Charactor = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(530.0f, 250.0f));

			Texture* charactorTexture = Resources::Find<Texture>(L"Intro_Charactor");
			Animator* charactor_animator = mTitle_Charactor->AddComponent<Animator>();
			charactor_animator->CreateAnimation(L"mTitle_Charactor", charactorTexture
				, SetVector(0.0f, 0.0f), SetVector(85.5f, 65.0f), SetVector::Zero, 2, 0.15f);

			charactor_animator->PlayeAnimation(L"mTitle_Charactor", true);

			mTitle_Charactor->GetComponent<Transform>()->SetScale(SetVector(2.5f, 2.5f));

			//SpriteRenderer* sr1 = mTitle_Charactor->AddComponent<SpriteRenderer>();
			//Texture* Title_Charactor = Resources::Find<Texture>(L"Intro_Charactor");
			//sr1->SetTexture(Title_Charactor);
			//sr1->SetSize(SetVector(2.0f, 2.0f));
		}

		// Creator 추가
		{
			mTitle_Creator = Object::Instantiate<GameObject>(eLayerType::BackGround, SetVector(780.0f, 260.0f));

			Texture* creatorTexture = Resources::Find<Texture>(L"Intro_Creator");
			Animator* creator_animator = mTitle_Creator->AddComponent<Animator>();
			creator_animator->CreateAnimation(L"Intro_Creator", creatorTexture
				, SetVector(0.0f, 0.0f), SetVector(108.0f, 57.0f), SetVector::Zero, 2, 0.15f);

			creator_animator->PlayeAnimation(L"Intro_Creator", true);

			mTitle_Creator->GetComponent<Transform>()->SetScale(SetVector(2.5f, 2.5f));

			//SpriteRenderer* sr2 = mTitle_Creator->AddComponent<SpriteRenderer>();
			//Texture* Title_Creator = Resources::Find<Texture>(L"Intro_Creator");
			//sr2->SetTexture(Title_Creator);
			//sr2->SetSize(SetVector(2.0f, 2.0f));
		}

		Scene::Initialize();
	}
	
	void IntroScene::Update()
	{
		Scene::Update();
	}
	
	void IntroScene::LateUpdate()
	{
		Scene::LateUpdate();

		mTime += Time::DeltaTime();

		if (mTime > 3.0f)
		{
			SceneManger::LoadScene(L"TitleScene");
		}
	}
	
	void IntroScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"IntroScene";
		TextOut(hdc, 0, 0, str, 10);
	}
}
