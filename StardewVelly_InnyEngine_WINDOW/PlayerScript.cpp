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
		if (Input::GetKey(eKeyCode::D))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Right;

			mAnimator->PlayeAnimation(L"RightWalk");

			nextAction();
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

	// Effect Ãß°¡
	void PlayerScript::breakStone()
	{
		GameObject* mFarm_Stone = Object::Instantiate<GameObject>(eLayerType::Object);
		Texture* stoneTexture = Resources::Find<Texture>(L"Farm_Stone");

		Animator* stone_animator = mFarm_Stone->AddComponent<Animator>();

		stone_animator->CreateAnimation(L"BreakStone", stoneTexture
			, SetVector(0.0f, 0.0f), SetVector(15.0f, 15.0f), SetVector::Zero, 2, 0.1f);

		stone_animator->PlayeAnimation(L"BreakStone", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		mFarm_Stone->GetComponent<Transform>()->SetScale(SetVector(2.5f, 2.5f));

		if (mDirection == eDirection::Left)
		{
			mFarm_Stone->GetComponent<Transform>()->SetPos(SetVector(pos.x - 100.0f, pos.y - 30.0f));
		}
		else if (mDirection == eDirection::Right)
		{
			mFarm_Stone->GetComponent<Transform>()->SetPos(SetVector(pos.x, pos.y - 30.0f));
		}
		else if (mDirection == eDirection::Up)
		{
			mFarm_Stone->GetComponent<Transform>()->SetPos(SetVector(pos.x-50.0f, pos.y-60.0f));
		}
		else if (mDirection == eDirection::Down)
		{
			mFarm_Stone->GetComponent<Transform>()->SetPos(SetVector(pos.x-50.0f, pos.y+10.0f));
		}
	}

	void PlayerScript::diggingGround()
	{
		GameObject* mFarm_digging = Object::Instantiate<GameObject>(eLayerType::Object);
		Texture* diggingTexture = Resources::Find<Texture>(L"Farm_DiggingGround");

		Animator* digging_animator = mFarm_digging->AddComponent<Animator>();

		digging_animator->CreateAnimation(L"DiggingGorund", diggingTexture
			, SetVector(0.0f, 0.0f), SetVector(16.0f, 16.0f), SetVector::Zero, 1, 0.1f);

		digging_animator->PlayeAnimation(L"DiggingGorund", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		mFarm_digging->GetComponent<Transform>()->SetScale(SetVector(2.5f, 2.5f));

		if (mDirection == eDirection::Left)
		{
			mFarm_digging->GetComponent<Transform>()->SetPos(SetVector(pos.x - 80.0f, pos.y - 30.0f));
		}
		else if (mDirection == eDirection::Right)
		{
			mFarm_digging->GetComponent<Transform>()->SetPos(SetVector(pos.x - 10.0f, pos.y - 30.0f));
		}
		else if (mDirection == eDirection::Up)
		{
			mFarm_digging->GetComponent<Transform>()->SetPos(SetVector(pos.x - 50.0f, pos.y - 60.0f));
		}
		else if (mDirection == eDirection::Down)
		{
			mFarm_digging->GetComponent<Transform>()->SetPos(SetVector(pos.x - 50.0f, pos.y + 10.0f));
		}
	}

	void PlayerScript::wetGround()
	{
		GameObject* mFarm_wet = Object::Instantiate<GameObject>(eLayerType::Object);
		Texture* wetTexture = Resources::Find<Texture>(L"Farm_WetGround");

		Animator* wet_animator = mFarm_wet->AddComponent<Animator>();

		wet_animator->CreateAnimation(L"WetGround", wetTexture
			, SetVector(0.0f, 0.0f), SetVector(16.0f, 16.0f), SetVector::Zero, 2, 0.1f);

		wet_animator->PlayeAnimation(L"WetGround", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		mFarm_wet->GetComponent<Transform>()->SetScale(SetVector(2.5f, 2.5f));

		if (mDirection == eDirection::Left)
		{
			mFarm_wet->GetComponent<Transform>()->SetPos(SetVector(pos.x - 80.0f, pos.y - 30.0f));
		}
		else if (mDirection == eDirection::Right)
		{
			mFarm_wet->GetComponent<Transform>()->SetPos(SetVector(pos.x - 10.0f, pos.y - 30.0f));
		}
		else if (mDirection == eDirection::Up)
		{
			mFarm_wet->GetComponent<Transform>()->SetPos(SetVector(pos.x - 50.0f, pos.y - 60.0f));
		}
		else if (mDirection == eDirection::Down)
		{
			mFarm_wet->GetComponent<Transform>()->SetPos(SetVector(pos.x - 50.0f, pos.y + 10.0f));
		}
	}

	void PlayerScript::treeCollapse()
	{
		GameObject* mFarm_collaps = Object::Instantiate<GameObject>(eLayerType::Object);
		Texture* collapseLeftTexture = Resources::Find<Texture>(L"Farm_TreeCollapse_Left");
		Texture* collapseRightTexture = Resources::Find<Texture>(L"Farm_TreeCollapse_Right");

		Animator* collapse_animator = mFarm_collaps->AddComponent<Animator>();

		collapse_animator->CreateAnimation(L"TreeCollapseLeft", collapseLeftTexture
			, SetVector(0.0f, 0.0f), SetVector(164.0f, 110.0f), SetVector::Zero, 10, 0.1f);
		collapse_animator->CreateAnimation(L"TreeCollapseRight", collapseRightTexture
			, SetVector(0.0f, 0.0f), SetVector(164.0f, 112.0f), SetVector::Zero, 10, 0.1f);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		mFarm_collaps->GetComponent<Transform>()->SetScale(SetVector(2.0f, 2.0f));

		if (mDirection == eDirection::Left)
		{
			collapse_animator->PlayeAnimation(L"TreeCollapseLeft", false);
			mFarm_collaps->GetComponent<Transform>()->SetPos(SetVector(pos.x-160.0f, pos.y-120.0f));
		}
		else if (mDirection == eDirection::Right)
		{
			collapse_animator->PlayeAnimation(L"TreeCollapseRight", false);
			mFarm_collaps->GetComponent<Transform>()->SetPos(SetVector(pos.x-80.0f, pos.y-120.0f));
		}
		else if (mDirection == eDirection::Down)
		{
			collapse_animator->PlayeAnimation(L"TreeCollapseLeft", false);
			mFarm_collaps->GetComponent<Transform>()->SetPos(SetVector(pos.x - 116.0f, pos.y-80.0f));
		}
		else if (mDirection == eDirection::Up)
		{
			collapse_animator->PlayeAnimation(L"TreeCollapseRight", false);
			mFarm_collaps->GetComponent<Transform>()->SetPos(SetVector(pos.x - 116.0f, pos.y - 160.0f));
		}
	}



	void PlayerScript::nextAction()
	{
		if (mDirection == eDirection::Right)
			rightAction();

		if (mDirection == eDirection::Left)
			leftAction();

		if (mDirection == eDirection::Up)
			upAction();

		if (mDirection == eDirection::Down)
			downAction();
	}

	void PlayerScript::rightAction()
	{
		// GiveWater
		if (Input::GetKey(eKeyCode::ONE))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayeAnimation(L"RightGiveWater", false);
			// mAnimator->GetCompleteEvent(L"RightGiveWater") = bind(&PlayerScript::wetGround, this);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"RightUsingAxes", false);
			// mAnimator->GetCompleteEvent(L"RightUsingAxes") = std::bind(&PlayerScript::treeCollapse, this);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"RightUsingHoes", false);
			// mAnimator->GetCompleteEvent(L"RightUsingHoes") = bind(&PlayerScript::diggingGround, this);
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
			// mAnimator->GetCompleteEvent(L"RightUsingPickaxes") = bind(&PlayerScript::breakStone, this);
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
			// mAnimator->GetCompleteEvent(L"LeftGiveWater") = bind(&PlayerScript::wetGround, this);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"LeftUsingAxes", false);
			// mAnimator->GetCompleteEvent(L"LeftUsingAxes") = bind(&PlayerScript::treeCollapse, this);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"LeftUsingHoes", false);
			// mAnimator->GetCompleteEvent(L"LeftUsingHoes") = bind(&PlayerScript::diggingGround, this);
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
			// mAnimator->GetCompleteEvent(L"LeftUsingPickaxes") = bind(&PlayerScript::breakStone, this);
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
			// mAnimator->GetCompleteEvent(L"DownGiveWater") = bind(&PlayerScript::wetGround, this);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"DownUsingAxes", false);
			// mAnimator->GetCompleteEvent(L"DownUsingAxes") = std::bind(&PlayerScript::treeCollapse, this);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"DownUsingHoes", false);
			// mAnimator->GetCompleteEvent(L"DownUsingHoes") = bind(&PlayerScript::diggingGround, this);

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
			// mAnimator->GetCompleteEvent(L"DownUsingPickaxes") = bind(&PlayerScript::breakStone, this);
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
			// mAnimator->GetCompleteEvent(L"UpGiveWater") = bind(&PlayerScript::wetGround, this);
		}

		// UsingAxes
		if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::UsingAxes;
			mAnimator->PlayeAnimation(L"UpUsingAxes", false);
			// mAnimator->GetCompleteEvent(L"UpUsingAxes") = std::bind(&PlayerScript::treeCollapse, this);
		}

		// UsingHoes
		if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingHoes;
			mAnimator->PlayeAnimation(L"UpUsingHoes", false);
			// mAnimator->GetCompleteEvent(L"UpUsingHoes") = bind(&PlayerScript::diggingGround, this);
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
			// mAnimator->GetCompleteEvent(L"UpUsingPickaxes") = bind(&PlayerScript::breakStone, this);

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
