#include "PlayerScript.h"
#include "Object.h"
#include "Input.h"
#include "Transform.h"
#include "GameObject.h"
#include "Animator.h"
#include "Resources.h"
#include "Time.h"

namespace in
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mEquipment(PlayerScript::eEquipment::Attack)
		, mDirection(PlayerScript::eDirection::Down)
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
			Idle();
			break;
		case in::PlayerScript::eState::Walk:
			Walk();
			break;
		case in::PlayerScript::eState::Eatting:
			Eatting();
			break;
		case in::PlayerScript::eState::PickUp:
			Pickup();
			break;	
		case in::PlayerScript::eState::UsingEquipment:
			UsingEquipment();
			break;
		}
	}
	
	void PlayerScript::LateUpdate()
	{
	}
	
	void PlayerScript::Render(HDC hdc)
	{
	}

	wstring PlayerScript::GetDirection()
	{
		wstring dirStr = L"";

		if (mDirection == eDirection::Right)
		{
			dirStr = L"Right";
		}
		else if (mDirection == eDirection::Left)
		{
			dirStr = L"Left";
		}
		else if (mDirection == eDirection::Up)
		{
			dirStr = L"Up";
		}
		else if (mDirection == eDirection::Down)
		{
			dirStr = L"Down";
		}

		return dirStr;
	}

	void PlayerScript::ActionByDirection()
	{
		wstring dirStr = GetDirection();

		if (Input::GetKey(eKeyCode::ONE))
		{
			mState = PlayerScript::eState::Eatting;
			mAnimator->PlayeAnimation(L"Eatting", false);
		}
		else if (Input::GetKey(eKeyCode::TWO))
		{
			mState = PlayerScript::eState::PickUp;
			mAnimator->PlayeAnimation(dirStr + L"PickUpWalk", false);
		}
		else if (Input::GetKey(eKeyCode::THREE))
		{
			mState = PlayerScript::eState::UsingEquipment;

			if (mEquipment == PlayerScript::eEquipment::GiveWater)
			{
				mAnimator->PlayeAnimation(dirStr + L"GiveWater", false);
			}
			else if (mEquipment == PlayerScript::eEquipment::UsingAxes)
			{
				mEquipment = PlayerScript::eEquipment::UsingAxes;
				mAnimator->PlayeAnimation(dirStr + L"UsingAxes", false);
			}
			else if (mEquipment == PlayerScript::eEquipment::UsingHoes)
			{
				mEquipment = PlayerScript::eEquipment::UsingHoes;
				mAnimator->PlayeAnimation(dirStr + L"UsingHoes", false);
			}
			else if (mEquipment == PlayerScript::eEquipment::UsingScythe)
			{
				mEquipment = PlayerScript::eEquipment::UsingScythe;
				mAnimator->PlayeAnimation(dirStr + L"UsingScythe", false);
			}
			else if (mEquipment == PlayerScript::eEquipment::Attack)
			{
				mEquipment = PlayerScript::eEquipment::Attack;
				mAnimator->PlayeAnimation(dirStr + L"Hunting", false);
			}
		}
	}

	void PlayerScript::CompleteCheckAndStopAnimation()
	{
		if (mAnimator->IsComplete())
		{
			mState = PlayerScript::eState::Idle;
			wstring dir = GetDirection();
			mAnimator->PlayeAnimation(dir + L"WalkStop", true);
		}
	}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(eKeyCode::D))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Right;

			mAnimator->PlayeAnimation(L"RightWalk");
		}
		else if(Input::GetKey(eKeyCode::A))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Left;

			mAnimator->PlayeAnimation(L"LeftWalk");
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Up;

			mAnimator->PlayeAnimation(L"UpWalk");
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Down;

			mAnimator->PlayeAnimation(L"DownWalk");
		}
		else
		{
			ActionByDirection();
		}
	}

	void PlayerScript::Walk()
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
				
		if (Input::GetKeyUp(eKeyCode::A) || Input::GetKeyUp(eKeyCode::D)
			|| Input::GetKeyUp(eKeyCode::S) || Input::GetKeyUp(eKeyCode::W))
		{
			mState = PlayerScript::eState::Idle;
			wstring dir = GetDirection();
			mAnimator->PlayeAnimation(dir + L"WalkStop", true);
		}

		tr->SetPos(pos);
	}

	void PlayerScript::Eatting()
	{
		CompleteCheckAndStopAnimation();
	}

	void PlayerScript::Pickup()
	{
		CompleteCheckAndStopAnimation();
	}

	void PlayerScript::UsingEquipment()
	{
		CompleteCheckAndStopAnimation();
	}

	/* Effect Ãß°¡
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
	} */
}