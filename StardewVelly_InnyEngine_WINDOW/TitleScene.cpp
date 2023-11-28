#include "TitleScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManger.h"

namespace in
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}
	
	void TitleScene::Initialize()
	{
		{
			bg = new Player();

			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(SetVector(0, 0));
			tr->SetName(L"Title");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"p1_SR");
			sr->ImageLoad(L"..\\Resource\\Texture\\TitleScene\\StardewPanorama.png");

			AddGameObject(bg, eLayerType::BackGround);
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
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(SetVector(0, 0));
	}
}