#include "MonsterScript.h"
#include "GameObject.h"
#include "Animator.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"

namespace in
{
	MonsterScript::MonsterScript()
		: mAnimator(nullptr)
		, mDirection(MonsterScript::eDirection::Left)
		, mTime1(0.0f)
		, mTime2(0.0f)
	{
	}

	MonsterScript::~MonsterScript()
	{
	}
	
	void MonsterScript::Initialize()
	{
	}
	
	void MonsterScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		move();
	}
	
	void MonsterScript::LateUpdate()
	{
	}
	
	void MonsterScript::Render(HDC hdc)
	{
	}
	
	void MonsterScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		mTime2 = Time::DeltaTime();
		mTime1 = mTime1 + mTime2;

		if (mTime1 > 1.0f)
		{
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;

			// 에러 확인 -> 출력창 이용
			char buff[100];
			::sprintf_s(buff, " Direction : %d \n", mDirection);
			::OutputDebugStringA(buff);

			mTime1 = 0.0f;
		}
		else
		{
			switch (mDirection)
			{
			case MonsterScript::eDirection::Left:
				pos.x += 50.0f * mTime2;
				break;
			case MonsterScript::eDirection::Right:
				pos.x += 50.0f * mTime2;
				break;
			case MonsterScript::eDirection::Up:
				pos.y -= 50.0f * mTime2;
				break;
			case MonsterScript::eDirection::Down:
				pos.y += 50.0f * mTime2;
				break;
			}
		}

		tr->SetPos(pos);
	}
}
