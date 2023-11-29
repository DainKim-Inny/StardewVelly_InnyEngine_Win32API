#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Resources.h"
#include "..\\StardewVelly_InnyEngine_SOURCE\\Texture.h"

namespace in
{
	void LoasdResources()
	{
		Resources::Load<Texture>(L"BackGround", L"..\\Resource\\Texture\\TitleScene\\StardewPanorama.png");
	}
}