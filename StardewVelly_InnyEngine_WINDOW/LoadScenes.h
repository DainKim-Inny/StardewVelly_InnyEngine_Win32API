#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\SceneManger.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "FarmScene.h"
#include "MineScene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManger::CreateScene<IntroScene>(L"IntroScene");
		SceneManger::CreateScene<TitleScene>(L"TitleScene");
		SceneManger::CreateScene<FarmScene>(L"FarmScene");
		SceneManger::CreateScene<MineScene>(L"MineScene");

		SceneManger::LoadScene(L"FarmScene");
	}
}