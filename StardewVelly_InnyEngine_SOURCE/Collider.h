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

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		SetVector GetOffset() { return mOffset; }
		void SetOffset(SetVector offset) { mOffset = offset; }

		UINT32 GetID() { return mID; }
		SetVector GetSize() { return mSize; }
		void SetSize(SetVector size) { mSize = size; }

	private:
		static UINT CollisionID;

		UINT32 mID;
		SetVector mOffset;
		SetVector mSize;
	};
}