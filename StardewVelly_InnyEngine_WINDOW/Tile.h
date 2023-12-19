#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\GameObject.h"

namespace in
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetIndexPosition(int x, int y);

	private:

	};
}