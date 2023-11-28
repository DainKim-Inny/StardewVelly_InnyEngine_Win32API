#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\SceneManger.h"
#include "TitleScene.h"

namespace in
{
	void LoadScenes()
	{
		SceneManger::CreateScene<TitleScene>(L"TitleScene");

		SceneManger::LoadScene(L"TitleScene");
	}
}