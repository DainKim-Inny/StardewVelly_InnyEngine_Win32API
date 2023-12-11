#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\SceneManager.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "FarmScene.h"
#include "Mine_B1_Scene.h"
#include "Mine_Lobby_Scene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManager::CreateScene<IntroScene>(L"IntroScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<FarmScene>(L"FarmScene");
		SceneManager::CreateScene<Mine_Lobby_Scene>(L"Mine_Lobby_Scene");
		SceneManager::CreateScene<Mine_B1_Scene>(L"Mine_B1_Scene");

		SceneManager::LoadScene(L"FarmScene");
	}
}