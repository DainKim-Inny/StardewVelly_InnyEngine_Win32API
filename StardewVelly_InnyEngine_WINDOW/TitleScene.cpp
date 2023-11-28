#include "TitleScene.h"

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
		GameObject* obj = new GameObject();
		obj->SetPosition(100, 100);
		AddGameObject(obj);
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