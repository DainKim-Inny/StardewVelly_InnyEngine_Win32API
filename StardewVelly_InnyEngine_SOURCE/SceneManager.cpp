#include "SceneManager.h"

using namespace std;

namespace in
{
	map<wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const wstring& name)
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

	void SceneManager::Initailize()
	{
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}