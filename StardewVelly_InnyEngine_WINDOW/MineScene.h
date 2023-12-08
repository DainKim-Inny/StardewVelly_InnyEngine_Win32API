#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class MineScene : public Scene
	{
	public:
		MineScene();
		~MineScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mMine_Bg;
		class Monster* mMine_Slime;

	};
}