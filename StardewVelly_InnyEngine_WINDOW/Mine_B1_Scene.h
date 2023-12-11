#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"

namespace in
{
	class Mine_B1_Scene : public Scene
	{
	public:
		Mine_B1_Scene();
		~Mine_B1_Scene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mMine_B1_Bg;
		class Monster* mMine_B1_Slime;

	};
}