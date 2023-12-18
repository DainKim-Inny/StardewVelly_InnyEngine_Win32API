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
			Eatting,
			PickUp,
			UsingEquipment,
		};

		enum class eEquipment
		{
			None,
			GiveWater,
			UsingAxes,
			UsingHoes,
			UsingScythe,
			Attack,
			//Fishing -> Animation sprite 구현 후 다시 작성 필요
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

	private:
		wstring GetDirection();
		void ActionByDirection();
		void CompleteCheckAndStopAnimation();

	private:
		void Idle();
		void Walk();
		void Eatting();
		void Pickup();
		void UsingEquipment();

	private:
		eState mState;
		eEquipment mEquipment;
		eDirection mDirection;
		class Animator* mAnimator;
	};
}