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

	private:
		SetVector mPosition;
	};
}