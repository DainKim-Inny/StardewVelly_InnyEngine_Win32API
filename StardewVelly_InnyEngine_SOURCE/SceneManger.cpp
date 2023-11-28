#include "SceneManger.h"

using namespace std;

namespace in
{
	map<wstring, Scene*> SceneManger::mScene = {};
	Scene* SceneManger::mActiveScene = nullptr;

	Scene* SceneManger::LoadScene(const wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		map<wstring, Scene*>::iterator iter = mScene.find(name);
	
		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

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