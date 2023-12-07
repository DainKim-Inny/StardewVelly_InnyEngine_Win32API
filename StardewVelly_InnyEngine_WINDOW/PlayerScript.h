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
			GiveWater,  // ���ֱ�
			UsingAxes,  // ������
			UsingHoes,  // ȣ����
			UsingScythe,  // ����
			UsingPickaxes,  // �����
			PickUpWalk,  // ä��
			Eatting_Ready,  // ������ �Ա� �غ�
			Eatting_Go,  // ������ �Ա�
			Fishing,  // ����
			Hunting  // ���
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