#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\SceneManger.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "FarmScene.h"
#include "Mine_B1_Scene.h"
#include "Mine_Lobby_Scene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManger::CreateScene<IntroScene>(L"IntroScene");
		SceneManger::CreateScene<TitleScene>(L"TitleScene");
		SceneManger::CreateScene<FarmScene>(L"FarmScene");
		SceneManger::CreateScene<Mine_Lobby_Scene>(L"Mine_Lobby_Scene");
		SceneManger::CreateScene<Mine_B1_Scene>(L"Mine_B1_Scene");

		SceneManger::LoadScene(L"TitleScene");
	}
}