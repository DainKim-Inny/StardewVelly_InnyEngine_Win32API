#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Resources.h"
#include "..\\StardewVelly_InnyEngine_SOURCE\\Texture.h"

namespace in
{
	void LoadResources()
	{
		// IntroScene Load
		{
			Resources::Load<Texture>(L"Intro_Charactor", L"..\\Resource\\1.IntroScene\\1.Texture\\Intro_Charactor.bmp");
			Resources::Load<Texture>(L"Intro_Creator", L"..\\Resource\\1.IntroScene\\1.Texture\\Intro_Creator.bmp");
		}

		// TitleScene Load
		{
			Resources::Load<Texture>(L"Intro_BG", L"..\\Resource\\2.TitleScene\\1.Texture\\stardewPanorama.bmp");
			Resources::Load<Texture>(L"Intro_Logo", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_LogoButton.bmp");
			Resources::Load<Texture>(L"Intro_Button", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_Button.bmp");
			Resources::Load<Texture>(L"Intro_ButtomLeaf", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_BottomLeaf.bmp");
			Resources::Load<Texture>(L"Intro_TopLeaf", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_TopLeaf.bmp");
			Resources::Load<Texture>(L"Intro_Bird", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_Bird.bmp");
			Resources::Load<Texture>(L"Intro_Question", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_Question.bmp");
		}

		// FarmScene Load
		{
			Resources::Load<Texture>(L"Farm_BG", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Map.png");
			Resources::Load<Texture>(L"Farm_Player", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Player.bmp");
		}
	}
}