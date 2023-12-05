#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"
#include "Renderer.h"

using namespace std;

namespace in
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(Texture* texture) { mTexture = texture; }
		void SetSize(SetVector size) { mSize = size; }

	private:
		Texture* mTexture;
		SetVector mSize;
	};
}