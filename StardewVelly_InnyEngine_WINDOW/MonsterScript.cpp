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
		, mTime(0.0f)
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

		relex();
	}
	
	void MonsterScript::LateUpdate()
	{
	}
	
	void MonsterScript::Render(HDC hdc)
	{
	}

	void MonsterScript::relex()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		mTime += Time::DeltaTime();

		if (mTime > 3.0f)
		{
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			PlayMoveAnimationByDirection(mDirection);

			mTime = 0.0f;
		}
	}
	
	void MonsterScript::move()
	{
	}
	
	void MonsterScript::PlayMoveAnimationByDirection(eDirection dir)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		if (mTime < 10.0f)
		{
			switch (mDirection)
			{
			case in::MonsterScript::eDirection::Left:
				pos.x -= 1000.0f * Time::DeltaTime();
				break;
			case in::MonsterScript::eDirection::Right:
				pos.x += 1000.0f * Time::DeltaTime();
				break;
			case in::MonsterScript::eDirection::Up:
				pos.y -= 1000.0f * Time::DeltaTime();
				break;
			case in::MonsterScript::eDirection::Down:
				pos.y += 1000.0f * Time::DeltaTime();
				break;
			default:
				break;
			}
			tr->SetPos(pos);
		}
	}
}
