#pragma once
#include "Resource.h"
#include "Texture.h"

namespace in
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			SetVector leftTop;
			SetVector size;
			SetVector offset;
			float duration;

			Sprite()
				: leftTop(SetVector::Zero)
				, size(SetVector::Zero)
				, offset(SetVector::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		HRESULT Load(const wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const wstring& name
			, Texture* spriteSheet
			, SetVector leftTop
			, SetVector size
			, SetVector offset
			, UINT spriteLength
			, float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimation(class Animator* animator) { mAnimator = animator; }

	private:
		class Animator* mAnimator;
		Texture* mTexture;

		vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}