#pragma once
#include "Component.h"

namespace in
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		SetVector CalculatePosition(SetVector pos) { return pos - mDistance; }

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mTarget;
		SetVector mDistance;
		SetVector mResolution;
		SetVector mLookPosition;

	};

}