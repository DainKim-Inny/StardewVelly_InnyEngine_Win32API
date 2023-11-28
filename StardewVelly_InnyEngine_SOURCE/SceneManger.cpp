#include "SceneManger.h"

using namespace std;

namespace in
{
	map<wstring, Scene*> SceneManger::mScene = {};
	Scene* SceneManger::mActiveScene = nullptr;

	void SceneManger::Initailize()
	{
	}

	void SceneManger::Update()
	{
		mActiveScene->Update();
	}
	
	void SceneManger::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	
	void SceneManger::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}