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