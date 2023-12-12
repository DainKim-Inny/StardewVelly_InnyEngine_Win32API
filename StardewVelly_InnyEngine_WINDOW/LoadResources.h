#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Resources.h"
#include "..\\StardewVelly_InnyEngine_SOURCE\\Texture.h"

namespace in
{
	void LoadResources()
	{
		// IntroScene Resources Load
		{
			Resources::Load<Texture>(L"Intro_Charactor", L"..\\Resource\\1.IntroScene\\1.Texture\\Intro_Charactor.bmp");
			Resources::Load<Texture>(L"Intro_Creator", L"..\\Resource\\1.IntroScene\\1.Texture\\Intro_Creator.bmp");
		}

		// TitleScene Resources Load
		{
			Resources::Load<Texture>(L"Intro_BG", L"..\\Resource\\2.TitleScene\\1.Texture\\stardewPanorama.bmp");
			Resources::Load<Texture>(L"Intro_Logo", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_LogoButton.bmp");
			Resources::Load<Texture>(L"Intro_Button", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_Button.bmp");
			Resources::Load<Texture>(L"Intro_ButtomLeaf", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_BottomLeaf.bmp");
			Resources::Load<Texture>(L"Intro_TopLeaf", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_TopLeaf.bmp");
			Resources::Load<Texture>(L"Intro_Bird", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_Bird.bmp");
			Resources::Load<Texture>(L"Intro_Question", L"..\\Resource\\2.TitleScene\\1.Texture\\Title_Question.bmp");
		}

		// FarmScene Resources Load
		{
			Resources::Load<Texture>(L"Farm_BG", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Map.bmp");
			Resources::Load<Texture>(L"Farm_Player", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Player.bmp");
			Resources::Load<Texture>(L"Farm_Player2", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Player2.bmp");
			Resources::Load<Texture>(L"Farm_PlayerFront", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_PlayerFront.bmp");
			Resources::Load<Texture>(L"Farm_Clock", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Clock.bmp");
			Resources::Load<Texture>(L"Farm_QuickSlot", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_QuickSlot.bmp");
			Resources::Load<Texture>(L"Farm_EnergyBar", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_EnergyBar.bmp");
			Resources::Load<Texture>(L"Farm_Stone", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_Stone.bmp");
			Resources::Load<Texture>(L"Farm_TreeCollapse_Left", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_TreeCollapse_Left.bmp");
			Resources::Load<Texture>(L"Farm_TreeCollapse_Right", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_TreeCollapse_Right.bmp");
			Resources::Load<Texture>(L"Farm_DiggingGround", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_WetGroung.bmp");
			Resources::Load<Texture>(L"Farm_WetGround", L"..\\Resource\\4.PlayScene\\1.FarmScene\\1.Texture\\Farm_WetGroung.bmp");
		}

		// MineScene Resources Load
		{
			Resources::Load<Texture>(L"Mine_B1_BG", L"..\\Resource\\4.PlayScene\\2.MineScene\\1.Texture\\Mine_BG.bmp");
			Resources::Load<Texture>(L"Mine_B1_Slime", L"..\\Resource\\4.PlayScene\\2.MineScene\\1.Texture\\Mine_Slime.bmp");
			Resources::Load<Texture>(L"Mine_Lobby_BG", L"..\\Resource\\4.PlayScene\\2.MineScene\\1.Texture\\Mine_Looby.bmp");
		}
	}
}