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
			PickUp,  // ä��
			Eatting  // ������ �Ա�
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
		void pickUp();
		void eatting();

	private:
		eState mState;
		class Animator* mAnimator;

	};
}