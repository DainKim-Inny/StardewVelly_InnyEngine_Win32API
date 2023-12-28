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
		SetVector scale = tr->GetScale();
		// 회전 함수 추가 시, 회전 각도 전달 : float rot = tr->GetRotation() 


		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextrueType() 
			== Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc(), 0, 0
				, mTexture->GetWidth()
				, mTexture->GetHeight()
				, RGB(255, 0, 255));

			Rectangle(hdc, pos.x+5, pos.y+5, pos.x+15, pos.y+15);
		}
		else if (mTexture->GetTextrueType() 
			== Texture::eTextureType::Png)
		{
			// 투명화 시킬 픽셀의 색 범위
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀 색의 범위 지정
			imgAtt.SetColorKey(Gdiplus::Color(255, 255, 255), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			// 회전 시 추가, 함수
			//graphics.TranslateTransform(pos.x, pos.y);
			//graphics.RotateTransform(rot);
			//graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y
					, mTexture->GetWidth() * mSize.x *scale.x
					,mTexture->GetHeight() *mSize.y*scale.y
				)
				, 0, 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr);
		}
	}
}