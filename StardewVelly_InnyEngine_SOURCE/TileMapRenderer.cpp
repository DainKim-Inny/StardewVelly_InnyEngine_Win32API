#include "TileMapRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace in
{
	SetVector TileMapRenderer::TileSize = SetVector::One;
	SetVector TileMapRenderer::OriginTileSize = SetVector::One;
	SetVector TileMapRenderer::SelectedIndex = SetVector::One;

	TileMapRenderer::TileMapRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(2.0f, 2.0f)
		, mIndex(0, 0)
		, mTileSize(16.0f, 16.0f)
	{
		TileSize = mTileSize * mSize;
		OriginTileSize = mTileSize;
	}

	TileMapRenderer::~TileMapRenderer()
	{
	}
	
	void TileMapRenderer::Initialize()
	{
	}
	
	void TileMapRenderer::Update()
	{
	}
	
	void TileMapRenderer::LateUpdate()
	{
	}
	
	void TileMapRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();
		SetVector scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextrueType() == Texture::eTextureType::Bmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc
				, pos.x, pos.y 
				, mTileSize.x * mSize.x * scale.x
				, mTileSize.y * mSize.y * scale.y
				, mTexture->GetHdc()
				, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
				, mTileSize.x
				, mTileSize.y
				, func);
		}
	}
}
