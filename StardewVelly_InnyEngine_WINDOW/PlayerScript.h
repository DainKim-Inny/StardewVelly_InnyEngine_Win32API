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
			GiveWater,  // 물주기(ONE)
			UsingAxes,  // 도끼질(TWO)
			UsingHoes,  // 호미질(THREE)
			UsingScythe,  // 낫질(FOUR)
			UsingPickaxes,  // 곡괭이질(FIVE)
			PickUpWalk,  // 채집(SIX)
			Fishing,  // 낚시(SEVEN)
			Hunting,  // 사냥(EIGHT)
			Eatting_Ready,  // 아이템 먹기 준비(NINE)
			Eatting_Go,  // 아이템 먹기(ZERO)
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