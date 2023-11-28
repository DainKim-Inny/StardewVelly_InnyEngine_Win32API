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
		Player* p1 = new Player();
		
		Transform* tr = p1->AddComponent<Transform>();
		tr->SetPos(500, 500);
		tr->SetName(L"p1_TR");

		SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();
		sr->SetName(L"p1_SR");

		AddGameObject(p1);
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