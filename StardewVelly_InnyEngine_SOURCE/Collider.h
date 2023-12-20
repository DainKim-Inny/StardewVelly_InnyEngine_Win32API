#pragma once
#include "Component.h"

namespace in
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		SetVector GetOffset() { return mOffset; }
		void SetOffset(SetVector offset) { mOffset = offset; }

	private:
		SetVector mOffset;
	};
}