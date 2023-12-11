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

			Events* events
				= FindEvents(mActiveAnimation->GetName());

			if(mActiveAnimation->IsComplete() == true)
			{
				if(events)  // ActiveAnimation에 이어지는 Event 있는 경우
					events->completeEvent();

				if(mbLoop == true)
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
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimation(this);

		Events* events = new Events();
		mEvents.insert(make_pair(name, events));

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

		if (mActiveAnimation)
		{
			Events* currentEvents
				= FindEvents(mActiveAnimation->GetName());

			if (currentEvents)
				currentEvents->endEvent();
		}

		Events* nextEvents
			= FindEvents(animation->GetName());

		if (nextEvents)
			nextEvents->startEvent();

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}

	Animator::Events* Animator::FindEvents(const wstring& name)
	{
		auto iter = mEvents.find(name);
		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}

	function<void()>& Animator::GetStartEvent(const wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}

	function<void()>& Animator::GetCompleteEvent(const wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}

	function<void()>& Animator::GetEndEvent(const wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}