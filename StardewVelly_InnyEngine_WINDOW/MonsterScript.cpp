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
		
		mTime += Time::DeltaTime();

		if (mTime > 1.0f)
		{
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			
			switch (mDirection)
			{
			case MonsterScript::eDirection::Left:
				pos.x += 100.0f * Time::DeltaTime();
				break;
			case MonsterScript::eDirection::Right:
				pos.x += 100.0f * Time::DeltaTime();
				break;
			case MonsterScript::eDirection::Up:
				pos.y -= 100.0f * Time::DeltaTime();
				break;
			case MonsterScript::eDirection::Down:
				pos.y += 100.0f * Time::DeltaTime();
				break;
			}
		}

		tr->SetPos(pos);
	}
}
