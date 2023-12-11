#pragma once
#include "Scene.h"

using namespace std;

namespace in
{
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(make_pair(name, scene));

			return scene;
		}


		static Scene* LoadScene(const wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initailize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Release();

	private:
		static map<wstring, Scene*> mScene;
		static Scene* mActiveScene;

	};
}