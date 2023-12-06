#pragma once
#include "Script.h"

namespace in
{
	class BirdScript : public Script
	{
	public:
		BirdScript();
		~BirdScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};	
}