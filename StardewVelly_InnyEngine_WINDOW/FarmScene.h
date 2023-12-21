#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class FarmScene : public Scene
	{
	public:
		FarmScene();
		~FarmScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mFarm_Bg;
		class GameObject* mFarm_Clock;
		class GameObject* mFarm_QuickSlot;
		class GameObject* mFarm_EnergyBar;
		class Player* mFarm_Player;
		class GameObject* mFarm_Stone;
	};
}