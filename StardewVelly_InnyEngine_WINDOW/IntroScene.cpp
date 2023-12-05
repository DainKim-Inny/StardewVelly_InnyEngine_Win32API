#include "IntroScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"

namespace in
{
	IntroScene::IntroScene()
		: mTitle_Charactor(nullptr)
		, mTitle_Creator(nullptr)
	{
	}

	IntroScene::~IntroScene()
	{
	}
	
	void IntroScene::Initialize()
	{

		// Logo 추가
		{
			mTitle_Charactor = Object::Instantiate<Player>(eLayerType::BackGround, SetVector(500.0f, 250.0f));

			SpriteRenderer* sr1 = mTitle_Charactor->AddComponent<SpriteRenderer>();
			Texture* Title_Charactor = Resources::Find<Texture>(L"Intro_Charactor");
			sr1->SetTexture(Title_Charactor);
			sr1->SetSize(SetVector(2.0f, 2.0f));
		}

		// Creator 추가
		{
			mTitle_Creator = Object::Instantiate<Player>(eLayerType::BackGround, SetVector(680.0f, 260.0f));

			SpriteRenderer* sr2 = mTitle_Creator->AddComponent<SpriteRenderer>();
			Texture* Title_Creator = Resources::Find<Texture>(L"Intro_Creator");
			sr2->SetTexture(Title_Creator);
			sr2->SetSize(SetVector(2.0f, 2.0f));
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

		if (Input::GetKeyDown(eKeyCode::N))
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
