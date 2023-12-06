#pragma once
#include "CommonHeader.h"
#include "Component.h"
#include "Animation.h"
#include "Texture.h"

namespace in
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const wstring& name
			, Texture* spriteSheet
			, SetVector leftTop
			, SetVector size
			, SetVector offset
			, UINT spriteLength
			, float duration);

		Animation* FindAnimation(const wstring& name);
		void PlayeAnimation(const wstring& name, bool loop = true);

	private:
		map<wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
	};
}