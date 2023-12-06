#pragma once
#include "Script.h"

namespace in
{
	class buttonScript : public Script
	{
	public:
		buttonScript();
		~buttonScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		float mSpeed;
	};
}