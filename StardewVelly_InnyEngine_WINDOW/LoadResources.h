#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Resources.h"
#include "..\\StardewVelly_InnyEngine_SOURCE\\Texture.h"

namespace in
{
	void LoasdResources()
	{
		// IntroScene
		Resources::Load<Texture>(L"Intro_Charactor", L"..\\Resource\\1.IntroScene\\1.Texture\\Intro_Charactor.bmp");
		Resources::Load<Texture>(L"Intro_Creator", L"..\\Resource\\1.IntroScene\\1.Texture\\Intro_Creator.bmp");

		// TitleScene
		Resources::Load<Texture>(L"Intro_BG", L"..\\Resource\\2.TitleScene\\1.Texture\\StardewPanorama.png");
		Resources::Load<Texture>(L"Intro_Logo", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_LogoButton.png");
		Resources::Load<Texture>(L"Intro_NewButton", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_NewButton.png");
		Resources::Load<Texture>(L"Intro_LoadButton", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_LoadButton.png");
		Resources::Load<Texture>(L"Intro_ExitButton", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_ExitButton.png");

		// FarmScene
		Resources::Load<Texture>(L"Farm_BG", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Map.png");
		Resources::Load<Texture>(L"Farm_Player", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Player.bmp");
	}
}