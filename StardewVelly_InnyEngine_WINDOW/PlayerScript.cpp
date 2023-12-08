#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"
#include "Animator.h"

namespace in
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}
	
	void PlayerScript::Initialize()
	{
	}
	
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case in::PlayerScript::eState::Idle:
			idle();
			break;
		case in::PlayerScript::eState::Walk:
			walk();
			break;
		case in::PlayerScript::eState::UsingAxes:
			usingAxes();
			break;
		case in::PlayerScript::eState::UsingHoes:
			usingHose();
			break;
		case in::PlayerScript::eState::UsingPickaxes:
			usingPickaxes();
			break;
		case in::PlayerScript::eState::UsingScythe:
			usingScythe();
			break;
		case in::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case in::PlayerScript::eState::PickUpWalk:
			pickUpWalk();
			break;
		case in::PlayerScript::eState::Eatting_Ready:
			eattingReady();
			break;
		case in::PlayerScript::eState::Eatting_Go:
			eattingGo();
			break;
		default:
			break;
		}
	}
	
	void PlayerScript::LateUpdate()
	{
	}
	
	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::D))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayeAnimation(L"RightWalk");
		}

		if (Input::GetKey(eKeyCode::A))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayeAnimation(L"LeftWalk");
		}
		
		if (Input::GetKey(eKeyCode::W))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayeAnimation(L"UpWalk");
		}
		
		if (Input::GetKey(eKeyCode::S))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayeAnimation(L"DownWalk");
		}
	}
	
	void PlayerScript::walk()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
			pos.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::A))
			pos.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::W))
			pos.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::S))
			pos.y += 100.0f * Time::DeltaTime();

		if (Input::GetKeyUp(eKeyCode::D))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayeAnimation(L"RightWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::A))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayeAnimation(L"LeftWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::W))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayeAnimation(L"UpWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayeAnimation(L"DownWalkStop", true);
		}

		tr->SetPos(pos);
	}
	
	void PlayerScript::giveWater()
	{
		mState = PlayerScript::eState::GiveWater;
	}
	
	void PlayerScript::usingAxes()
	{
		mState = PlayerScript::eState::UsingAxes;
	}

	void PlayerScript::usingHose()
	{
		mState = PlayerScript::eState::UsingHoes;
	}
	
	void PlayerScript::usingScythe()
	{
		mState = PlayerScript::eState::UsingScythe;
	}
	
	void PlayerScript::usingPickaxes()
	{
		mState = PlayerScript::eState::UsingPickaxes;
	}
	
	void PlayerScript::pickUpWalk()
	{
		mState = PlayerScript::eState::PickUpWalk;
	}
	
	void PlayerScript::eattingReady()
	{
		mState = PlayerScript::eState::Eatting_Ready;
	}

	void PlayerScript::eattingGo()
	{
		mState = PlayerScript::eState::Eatting_Go;
	}

	void PlayerScript::fishing()
	{
		mState = PlayerScript::eState::Fishing;
	}

	void PlayerScript::hunting()
	{
		mState = PlayerScript::eState::Hunting;
	}
}
