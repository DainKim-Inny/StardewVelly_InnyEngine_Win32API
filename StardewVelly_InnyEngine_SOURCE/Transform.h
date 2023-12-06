#pragma once
#include "Entity.h"
#include "Component.h"

namespace in
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(SetVector pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		SetVector GetPosition() { return mPosition; }
		SetVector GetScale() { return mScale; }
		void SetScale(SetVector scale) { mScale = scale; }

		// 회전 함수 추가
		// float GetRoation() { return mRotation; }
		// void SetRotation(float rotate) { mRotation = rotate; }
	private:
		SetVector mPosition;
		SetVector mScale;
		// float mRotation;
	};
}