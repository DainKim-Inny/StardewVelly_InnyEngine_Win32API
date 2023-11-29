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
		: bg(nullptr), logo(nullptr)
	{
	}

	TitleScene::~TitleScene()
	{
	}
	
	void TitleScene::Initialize()
	{
		{
			bg = Object::Instantiate<Player>(eLayerType::BackGround);

			SpriteRenderer* sr1 = bg->AddComponent<SpriteRenderer>();
			Texture* bg = Resources::Find<Texture>(L"BackGround");
			sr1->SetTexture(bg);
			sr1->SetSize(SetVector(2.2f, 1.7f));
		}

		{
			logo = Object::Instantiate<Player>(eLayerType::Logo, SetVector(370.0f, 90.0f));

			SpriteRenderer* sr2 = logo->AddComponent<SpriteRenderer>();
			Texture* logo = Resources::Find<Texture>(L"Logo");
			sr2->SetTexture(logo);
			sr2->SetSize(SetVector(1.7f, 1.7f));
		}

		{
			NewButton = Object::Instantiate<Player>(eLayerType::Button, SetVector(370.0f, 450.0f));

			SpriteRenderer* sr3 = NewButton->AddComponent<SpriteRenderer>();
			Texture* NewButton = Resources::Find<Texture>(L"NewButton");
			sr3->SetTexture(NewButton);
			sr3->SetSize(SetVector(2.5f, 2.5f));
		}

		{
			LoadButton = Object::Instantiate<Player>(eLayerType::Button, SetVector(620.0f, 450.0f));

			SpriteRenderer* sr4 = LoadButton->AddComponent<SpriteRenderer>();
			Texture* LoadButton = Resources::Find<Texture>(L"LoadButton");
			sr4->SetTexture(LoadButton);
			sr4->SetSize(SetVector(2.5f, 2.5f));
		}

		{
			ExitButton = Object::Instantiate<Player>(eLayerType::Button, SetVector(860.0f, 450.0f));

			SpriteRenderer* sr5 = ExitButton->AddComponent<SpriteRenderer>();
			Texture* ExitButton = Resources::Find<Texture>(L"ExitButton");
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