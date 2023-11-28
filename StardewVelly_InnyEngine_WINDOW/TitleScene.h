#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
