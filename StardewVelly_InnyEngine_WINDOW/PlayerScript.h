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
			GiveWater,  // ���ֱ�(ONE)
			UsingAxes,  // ������(TWO)
			UsingHoes,  // ȣ����(THREE)
			UsingScythe,  // ����(FOUR)
			UsingPickaxes,  // �����(FIVE)
			PickUpWalk,  // ä��(SIX)
			Fishing,  // ����(SEVEN)
			Hunting,  // ���(EIGHT)
			Eatting_Ready,  // ������ �Ա� �غ�(NINE)
			Eatting_Go,  // ������ �Ա�(ZERO)
		};

		enum class eDirection
		{
			Right,
			Left,
			Up,
			Down
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void breakStone();

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

		void nextAction();

		void rightAction();
		void leftAction();
		void downAction();
		void upAction();
		void endingAction();

	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
	};
}