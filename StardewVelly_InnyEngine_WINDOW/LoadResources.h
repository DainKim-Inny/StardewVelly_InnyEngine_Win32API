#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Resources.h"
#include "..\\StardewVelly_InnyEngine_SOURCE\\Texture.h"

namespace in
{
	void LoasdResources()
	{
		// IntroScene
		Resources::Load<Texture>(L"TitleCharactor", L"..\\Resource\\Texture\\IntroScene\\TitleCharactor.png");
		Resources::Load<Texture>(L"TitleCreator", L"..\\Resource\\Texture\\IntroScene\\TitleCreator.png");

		// TitleScene
		Resources::Load<Texture>(L"BackGround", L"..\\Resource\\Texture\\TitleScene\\StardewPanorama.png");
		Resources::Load<Texture>(L"Logo", L"..\\Resource\\Texture\\TitleScene\\Logo.png");
		Resources::Load<Texture>(L"NewButton", L"..\\Resource\\Texture\\TitleScene\\New.png");
		Resources::Load<Texture>(L"LoadButton", L"..\\Resource\\Texture\\TitleScene\\Load.png");
		Resources::Load<Texture>(L"ExitButton", L"..\\Resource\\Texture\\TitleScene\\Exit.png");
	}
}