#include "TitleScene.h"
#include "GameObject.h"
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
	TitleScene::TitleScene()
		: bg(nullptr)
	{
	}

	TitleScene::~TitleScene()
	{
	}
	
	void TitleScene::Initialize()
	{
		{
			bg = Object::Instantiate<Player>(eLayerType::BackGround);

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			Texture* bg = Resources::Find<Texture>(L"BackGround");
			sr->SetTexture(bg);

			Scene::Initialize();
		}
	}
	
	void TitleScene::Update()
	{
		Scene::Update();
	}
	
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"TitleScene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void TitleScene::OnEnter()
	{
	}

	void TitleScene::OnExit()
	{
	}
}