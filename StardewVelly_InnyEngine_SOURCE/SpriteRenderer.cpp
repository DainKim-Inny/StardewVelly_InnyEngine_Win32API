#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace in
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(SetVector::One)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}
	
	void SpriteRenderer::Initialize()
	{
	}
	
	void SpriteRenderer::Update()
	{
	}
	
	void SpriteRenderer::LateUpdate()
	{
	}
	
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		if (renderer::mainCamera)
		{
			pos = renderer::mainCamera->CalculatePosition(pos);
		}

		if (mTexture->GetTextrueType() 
			== Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x
				, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0
				, mTexture->GetWidth()
				, mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextrueType() 
			== Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y
				, mTexture->GetWidth() * mSize.x
				, mTexture->GetHeight() * mSize.y));
		}
	}
}