#pragma once
#include "CommonHeader.h"
#include "Component.h"
#include "Animation.h"
#include "Texture.h"

using namespace std;

namespace in
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(function<void()> func)
			{
				mEvent = move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			function<void()> mEvent;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

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

		Events* FindEvents(const wstring& name);
		function<void()>& GetStartEvent(const wstring& name);
		function<void()>& GetCompleteEvent(const wstring& name);
		function<void()>& GetEndEvent(const wstring& name);

		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private:
		map<wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		map<wstring, Events*> mEvents;
	};
}