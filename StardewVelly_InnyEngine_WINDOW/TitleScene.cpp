#include "TitleScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

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
		Player* bg = new Player();
		
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(SetVector(0, 0));
		tr->SetName(L"Title");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"p1_SR");
		sr->ImageLoad(L"..\\Resource\\Texture\\TitleScene\\StardewPanorama.png");

		AddGameObject(bg);
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
	}
}