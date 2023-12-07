#pragma once
#include "Script.h"

namespace in
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			GiveWater,  // 물주기
			UsingAxes,  // 도끼질
			UsingHoes,  // 호미질
			UsingScythe,  // 낫질
			UsingPickaxes,  // 곡괭이질
			PickUpWalk,  // 채집
			Eatting_Ready,  // 아이템 먹기 준비
			Eatting_Go,  // 아이템 먹기
			Fishing,  // 낚시
			Hunting  // 사냥
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void walk();
		void giveWater();
		void usingAxes();
		void usingHose();
		void usingScythe();
		void usingPickaxes();
		void pickUpWalk();
		void eattingReady();
		void eattingGo();
		void fishing();
		void hunting();

	private:
		eState mState;
		class Animator* mAnimator;

	};
}