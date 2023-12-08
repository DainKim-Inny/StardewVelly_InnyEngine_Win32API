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

		// Walk
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

		// GiveWater
		if (Input::GetKey(eKeyCode::ONE))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayeAnimation(L"DownGiveWater", false);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"DownUsingAxes", false);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"DownUsingHoes", false);
		}

		// UsingScythe
		if (Input::GetKey(eKeyCode::FOUR))
		{
			mState = PlayerScript::eState::UsingScythe;
			mAnimator->PlayeAnimation(L"DownUsingScythe", false);
		}

		// UsingPickaxes
		if (Input::GetKey(eKeyCode::FIVE))
		{
			mState = PlayerScript::eState::UsingPickaxes;
			mAnimator->PlayeAnimation(L"DownUsingPickaxes", false);
		}

		// PickUpWalk
		if (Input::GetKey(eKeyCode::SIX))
		{
			mState = PlayerScript::eState::PickUpWalk;
			mAnimator->PlayeAnimation(L"DownPickUpWalk", false);
		}

		// Fishing
		if (Input::GetKey(eKeyCode::SEVEN))
		{
			mState = PlayerScript::eState::Fishing;
			mAnimator->PlayeAnimation(L"Fishing", false);

			SetVector mousePos = Input::GetMousePosition();
		}

		// Hunting
		if (Input::GetKey(eKeyCode::EIGHT))
		{
			mState = PlayerScript::eState::Hunting;
			mAnimator->PlayeAnimation(L"DownHunting", false);
		}

		// Eatting_Ready
		if (Input::GetKey(eKeyCode::NINE))
		{
			mState = PlayerScript::eState::Eatting_Ready;
			mAnimator->PlayeAnimation(L"Eatting_Ready", false);

			SetVector mousePos = Input::GetMousePosition();
		}

		// Eatting_Go
		if (Input::GetKey(eKeyCode::ZERO))
		{
			mState = PlayerScript::eState::Eatting_Go;
			mAnimator->PlayeAnimation(L"Eatting_Go", false);

			SetVector mousePos = Input::GetMousePosition();
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

		tr->SetPos(pos);

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
	}
	
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}
	
	void PlayerScript::usingAxes()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}

	void PlayerScript::usingHose()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}
	
	void PlayerScript::usingScythe()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}
	
	void PlayerScript::usingPickaxes()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}
	
	void PlayerScript::pickUpWalk()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}
	
	void PlayerScript::eattingReady()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}

	void PlayerScript::eattingGo()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}

	void PlayerScript::fishing()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}

	void PlayerScript::hunting()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayeAnimation(L"Idle", false);
		}
	}
}
