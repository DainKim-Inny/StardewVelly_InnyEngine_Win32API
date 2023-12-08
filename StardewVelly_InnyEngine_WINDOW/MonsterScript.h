#pragma once
#include "Script.h"
#include "Transform.h"

namespace in
{
	class MonsterScript : public Script
	{
	public:
		enum class eDirection
		{
			Left,
			Right,
			Up,
			Down,
			End
		};

		MonsterScript();
		~MonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void relex();
		void move();

		void PlayMoveAnimationByDirection(eDirection dir);

	private:
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}