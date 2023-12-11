#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Resources.h"

//#define _DAIN_DEBUG_TEST

namespace in
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
		, mDirection(PlayerScript::eDirection::Down)
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
		case in::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case in::PlayerScript::eState::UsingAxes:
			usingAxes();
			break;
		case in::PlayerScript::eState::UsingHoes:
			usingHose();
			break;
		case in::PlayerScript::eState::UsingScythe:
			usingScythe();
			break;
		case in::PlayerScript::eState::UsingPickaxes:
			usingPickaxes();
			break;
		case in::PlayerScript::eState::PickUpWalk:
			pickUpWalk();
			break;
		case in::PlayerScript::eState::Fishing:
			pickUpWalk();
			break;
		case in::PlayerScript::eState::Hunting:
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
				mDirection = PlayerScript::eDirection::Right;

				mAnimator->PlayeAnimation(L"RightWalk");
			}
			if (Input::GetKey(eKeyCode::A))
			{
				mState = PlayerScript::eState::Walk;
				mDirection = PlayerScript::eDirection::Left;

				mAnimator->PlayeAnimation(L"LeftWalk");
			}
			if (Input::GetKey(eKeyCode::W))
			{
				mState = PlayerScript::eState::Walk;
				mDirection = PlayerScript::eDirection::Up;

				mAnimator->PlayeAnimation(L"UpWalk");
			}
			if (Input::GetKey(eKeyCode::S))
			{
				mState = PlayerScript::eState::Walk;
				mDirection = PlayerScript::eDirection::Down;

				mAnimator->PlayeAnimation(L"DownWalk");
			}
		}

		nextAction();
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
			mDirection = PlayerScript::eDirection::Right;
			mAnimator->PlayeAnimation(L"RightWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::A))
		{
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Left;
			mAnimator->PlayeAnimation(L"LeftWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::W))
		{
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Up;
			mAnimator->PlayeAnimation(L"UpWalkStop", true);
		}

		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Down;
			mAnimator->PlayeAnimation(L"DownWalkStop", true);
		}
	}
	
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}
	
	void PlayerScript::usingAxes()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}

	void PlayerScript::usingHose()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}
	
	void PlayerScript::usingScythe()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}
	
	void PlayerScript::usingPickaxes()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}
	
	void PlayerScript::pickUpWalk()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}
	
	void PlayerScript::eattingReady()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}

	void PlayerScript::eattingGo()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}

	void PlayerScript::fishing()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}

	void PlayerScript::hunting()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			endingAction();
		}
	}

	void PlayerScript::breakStone()
	{
		GameObject* mFarm_Stone1 = Object::Instantiate<GameObject>(eLayerType::Object, SetVector(500.0f, 500.0f));

		Texture* stoneTexture1 = Resources::Find<Texture>(L"Farm_Stone1");

		Animator* stone_animator1 = mFarm_Stone1->AddComponent<Animator>();

		stone_animator1->CreateAnimation(L"BreakStone1", stoneTexture1
			, SetVector(0.0f, 0.0f), SetVector(16.0f, 17.0f), SetVector::Zero, 2, 0.1f);

		stone_animator1->PlayeAnimation(L"BreakStone1", false);

		mFarm_Stone1->GetComponent<Transform>()->SetScale(SetVector(2.5f, 2.5f));
	}

	void PlayerScript::nextAction()
	{
		if (mDirection == PlayerScript::eDirection::Right)
			rightAction();

		if (mDirection == PlayerScript::eDirection::Left)
			leftAction();

		if (mDirection == PlayerScript::eDirection::Up)
			upAction();

		if (mDirection == PlayerScript::eDirection::Down)
			downAction();
	}

	void PlayerScript::rightAction()
	{
		// GiveWater
		if (Input::GetKey(eKeyCode::ONE))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayeAnimation(L"RightGiveWater", false);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"RightUsingAxes", false);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"RightUsingHoes", false);
		}

		// UsingScythe
		if (Input::GetKey(eKeyCode::FOUR))
		{
			mState = PlayerScript::eState::UsingScythe;
			mAnimator->PlayeAnimation(L"RightUsingScythe", false);
		}

		// UsingPickaxes
		if (Input::GetKey(eKeyCode::FIVE))
		{
			mState = PlayerScript::eState::UsingPickaxes;
			mAnimator->PlayeAnimation(L"RightUsingPickaxes", false);
		}

		// PickUpWalk
		if (Input::GetKey(eKeyCode::SIX))
		{
			mState = PlayerScript::eState::PickUpWalk;
			mAnimator->PlayeAnimation(L"RightPickUpWalk", false);
		}

		// Fishing
		if (Input::GetKey(eKeyCode::SEVEN))
		{
			mState = PlayerScript::eState::Fishing;
			mAnimator->PlayeAnimation(L"Fishing", false);
		}

		// Hunting
		if (Input::GetKey(eKeyCode::EIGHT))
		{
			mState = PlayerScript::eState::Hunting;
			mAnimator->PlayeAnimation(L"RightHunting", false);
		}

		// Eatting_Ready
		if (Input::GetKey(eKeyCode::NINE))
		{
			mState = PlayerScript::eState::Eatting_Ready;
			mAnimator->PlayeAnimation(L"Eatting_Ready", false);
		}

		// Eatting_Go
		if (Input::GetKey(eKeyCode::ZERO))
		{
			mState = PlayerScript::eState::Eatting_Go;
			mAnimator->PlayeAnimation(L"Eatting_Go", false);
		}
	}

	void PlayerScript::leftAction()
	{
		// GiveWater
		if (Input::GetKey(eKeyCode::ONE))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayeAnimation(L"LeftGiveWater", false);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"LeftUsingAxes", false);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"LeftUsingHoes", false);
		}

		// UsingScythe
		if (Input::GetKey(eKeyCode::FOUR))
		{
			mState = PlayerScript::eState::UsingScythe;
			mAnimator->PlayeAnimation(L"LeftUsingScythe", false);
		}

		// UsingPickaxes
		if (Input::GetKey(eKeyCode::FIVE))
		{
			mState = PlayerScript::eState::UsingPickaxes;
			mAnimator->PlayeAnimation(L"LeftUsingPickaxes", false);
		}

		// PickUpWalk
		if (Input::GetKey(eKeyCode::SIX))
		{
			mState = PlayerScript::eState::PickUpWalk;
			mAnimator->PlayeAnimation(L"LeftPickUpWalk", false);
		}

		// Fishing
		if (Input::GetKey(eKeyCode::SEVEN))
		{
			mState = PlayerScript::eState::Fishing;
			mAnimator->PlayeAnimation(L"Fishing", false);
		}

		// Hunting
		if (Input::GetKey(eKeyCode::EIGHT))
		{
			mState = PlayerScript::eState::Hunting;
			mAnimator->PlayeAnimation(L"LeftHunting", false);
		}

		// Eatting_Ready
		if (Input::GetKey(eKeyCode::NINE))
		{
			mState = PlayerScript::eState::Eatting_Ready;
			mAnimator->PlayeAnimation(L"Eatting_Ready", false);
		}

		// Eatting_Go
		if (Input::GetKey(eKeyCode::ZERO))
		{
			mState = PlayerScript::eState::Eatting_Go;
			mAnimator->PlayeAnimation(L"Eatting_Go", false);
		}
	}

	void PlayerScript::downAction()
	{
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
		}

		// Eatting_Go
		if (Input::GetKey(eKeyCode::ZERO))
		{
			mState = PlayerScript::eState::Eatting_Go;
			mAnimator->PlayeAnimation(L"Eatting_Go", false);
		}
	}

	void PlayerScript::upAction()
	{
		// GiveWater
		if (Input::GetKey(eKeyCode::ONE))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayeAnimation(L"UpGiveWater", false);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"UpUsingAxes", false);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"UpUsingHoes", false);
		}

		// UsingScythe
		if (Input::GetKey(eKeyCode::FOUR))
		{
			mState = PlayerScript::eState::UsingScythe;
			mAnimator->PlayeAnimation(L"UpUsingScythe", false);
		}

		// UsingPickaxes
		if (Input::GetKey(eKeyCode::FIVE))
		{
			mState = PlayerScript::eState::UsingPickaxes;
			mAnimator->PlayeAnimation(L"UpUsingPickaxes", false);
		}

		// PickUpWalk
		if (Input::GetKey(eKeyCode::SIX))
		{
			mState = PlayerScript::eState::PickUpWalk;
			mAnimator->PlayeAnimation(L"UpPickUpWalk", false);
		}

		// Fishing
		if (Input::GetKey(eKeyCode::SEVEN))
		{
			mState = PlayerScript::eState::Fishing;
			mAnimator->PlayeAnimation(L"Fishing", false);
		}

		// Hunting
		if (Input::GetKey(eKeyCode::EIGHT))
		{
			mState = PlayerScript::eState::Hunting;
			mAnimator->PlayeAnimation(L"UpHunting", false);
		}

		// Eatting_Ready
		if (Input::GetKey(eKeyCode::NINE))
		{
			mState = PlayerScript::eState::Eatting_Ready;
			mAnimator->PlayeAnimation(L"Eatting_Ready", false);
		}

		// Eatting_Go
		if (Input::GetKey(eKeyCode::ZERO))
		{
			mState = PlayerScript::eState::Eatting_Go;
			mAnimator->PlayeAnimation(L"Eatting_Go", false);
		}
	}

	void PlayerScript::endingAction()
	{
		if (mDirection == PlayerScript::eDirection::Right)
			mAnimator->PlayeAnimation(L"RightWalkStop", false);

		if (mDirection == PlayerScript::eDirection::Left)
			mAnimator->PlayeAnimation(L"LeftWalkStop", false);

		if (mDirection == PlayerScript::eDirection::Up)
			mAnimator->PlayeAnimation(L"UpWalkStop", false);

		if (mDirection == PlayerScript::eDirection::Down)
			mAnimator->PlayeAnimation(L"DownWalkStop", false);
	}
}
