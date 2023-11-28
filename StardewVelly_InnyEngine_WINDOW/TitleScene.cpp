#include "TitleScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"
#include "Object.h"

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
			bg = Object::Instantiate<Player>(eLayerType::BackGround, SetVector(0.0f, 0.0f));

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"..\\Resource\\Texture\\TitleScene\\StardewPanorama.png");

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