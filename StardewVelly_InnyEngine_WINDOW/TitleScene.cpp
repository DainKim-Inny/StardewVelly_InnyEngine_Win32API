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

namespace in
{
	TitleScene::TitleScene()
		: mbg(nullptr), mlogo(nullptr)
		, mNewButton(nullptr), mLoadButton(nullptr)
		, mExitButton(nullptr)
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
			mlogo = Object::Instantiate<GameObject>(eLayerType::Logo, SetVector(370.0f, 90.0f));

			SpriteRenderer* sr2 = mlogo->AddComponent<SpriteRenderer>();
			Texture* logo = Resources::Find<Texture>(L"Intro_Logo");
			sr2->SetTexture(logo);
			sr2->SetSize(SetVector(1.7f, 1.7f));
		}

		// NewButton 추가
		{
			mNewButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(370.0f, 450.0f));

			SpriteRenderer* sr3 = mNewButton->AddComponent<SpriteRenderer>();
			Texture* NewButton = Resources::Find<Texture>(L"Intro_NewButton");
			sr3->SetTexture(NewButton);
			sr3->SetSize(SetVector(2.5f, 2.5f));
		}

		// LoadButton 추가
		{
			mLoadButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(620.0f, 450.0f));

			SpriteRenderer* sr4 = mLoadButton->AddComponent<SpriteRenderer>();
			Texture* LoadButton = Resources::Find<Texture>(L"Intro_LoadButton");
			sr4->SetTexture(LoadButton);
			sr4->SetSize(SetVector(2.5f, 2.5f));
		}

		// ExitButton 추가
		{
			mExitButton = Object::Instantiate<GameObject>(eLayerType::Button, SetVector(860.0f, 450.0f));

			SpriteRenderer* sr5 = mExitButton->AddComponent<SpriteRenderer>();
			Texture* ExitButton = Resources::Find<Texture>(L"Intro_ExitButton");
			sr5->SetTexture(ExitButton);
			sr5->SetSize(SetVector(2.5f, 2.5f));
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