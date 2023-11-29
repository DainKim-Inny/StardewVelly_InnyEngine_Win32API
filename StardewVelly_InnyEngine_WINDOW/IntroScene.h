#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class IntroScene : public Scene
	{
	public:
		IntroScene();
		~IntroScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class Player* Title_Charactor;
		class Player* Title_Creator;
	};
}