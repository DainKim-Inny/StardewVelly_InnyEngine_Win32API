#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\GameObject.h"

namespace in
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}