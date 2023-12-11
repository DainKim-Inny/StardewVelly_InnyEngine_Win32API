#include "Animator.h"

using namespace std;

namespace in
{
	Animator::Animator()
		: Component(eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
	{
	}

	Animator::~Animator()
	{
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	
	void Animator::Initialize()
	{
	}
	
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if(mActiveAnimation->IsComplete() == true
				&& mbLoop == true)
			{
				mActiveAnimation->Reset();
			}
		}
	}
	
	void Animator::LateUpdate()
	{
	}
	
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}
	
	void Animator::CreateAnimation(const wstring& name, Texture* spriteSheet
		, SetVector leftTop, SetVector size, SetVector offset, UINT spriteLength, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimation(this);

		mAnimations.insert(make_pair(name, animation));
	}
	
	Animation* Animator::FindAnimation(const wstring& name)
	{
		auto iter = mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	
	void Animator::PlayeAnimation(const wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);

		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
}