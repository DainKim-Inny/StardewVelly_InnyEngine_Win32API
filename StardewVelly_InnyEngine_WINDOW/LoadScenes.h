#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\SceneManger.h"
#include "TitleScene.h"
#include "IntroScene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManger::CreateScene<TitleScene>(L"TitleScene");
		SceneManger::CreateScene<IntroScene>(L"IntroScene");

		SceneManger::LoadScene(L"TitleScene");
	}
}