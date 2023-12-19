#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

namespace in
{
	class TileMapRenderer : public Component
	{
	public:
		TileMapRenderer();
		~TileMapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(Texture* texture) { mTexture = texture; }
		void SetSize(SetVector size) { mSize = size; }
		SetVector GetIndex() { return mIndex; }
		void SetIndex(SetVector index) { mIndex = index; }

	public:
		static SetVector TileSize;
		static SetVector OriginTileSize;
		static SetVector SelectedIndex;

	private:
		SetVector mTileSize;
		Texture* mTexture;
		SetVector mSize;
		SetVector mIndex;
	};
}