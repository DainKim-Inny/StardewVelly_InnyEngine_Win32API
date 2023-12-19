#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Script.h"
#include "..\\StardewVelly_InnyEngine_SOURCE\\Transform.h"

namespace in
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}

