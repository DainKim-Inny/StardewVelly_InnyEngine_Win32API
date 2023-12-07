#include "Animation.h"
#include "Time.h"
#include "Transform.h"
#include "GameObject.h"
#include "Animator.h"
#include "Renderer.h"
#include "Camera.h"

namespace in
{
	Animation::Animation()
		: Resource(eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}
	
	HRESULT Animation::Load(const wstring& path)
	{
		return E_NOTIMPL;
	}
	
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}
	
	void Animation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();
		SetVector scale = tr->GetScale();
		
		// 회전 추가 시, 변수 추가
		// float rot = tr->GetRotation();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Sprite sprite = mAnimationSheet[mIndex];
		Texture::eTextureType type = mTexture->GetTextrueType();

		if (type == Texture::eTextureType::Bmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc
				, pos.x - (sprite.size.x / 2.0f)
				, pos.y - (sprite.size.y / 2.0f)
				, sprite.size.x * scale.x
				, sprite.size.y * scale.y
				, imgHdc
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, func);
		}
		else if (type == Texture::eTextureType::Png)
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
					pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, nullptr);	
		}
	}
	
	void Animation::CreateAnimation(const wstring& name, Texture* spriteSheet
		, SetVector leftTop, SetVector size, SetVector offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (int i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}