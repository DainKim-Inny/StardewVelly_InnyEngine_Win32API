#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"

namespace in
{
	PlayerScript::PlayerScript()
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
		if (Input::GetKey(eKeyCode::D))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			SetVector pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();

			tr->SetPos(pos);
		}

		if (Input::GetKey(eKeyCode::A))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			SetVector pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(pos);
		}

		if (Input::GetKey(eKeyCode::W))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			SetVector pos = tr->GetPosition();
			pos.y -= 100.0f * Time::DeltaTime();

			tr->SetPos(pos);
		}

		if (Input::GetKey(eKeyCode::S))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			SetVector pos = tr->GetPosition();
			pos.y += 100.0f * Time::DeltaTime();

			tr->SetPos(pos);
		}
	}
	
	void PlayerScript::LateUpdate()
	{
	}
	
	void PlayerScript::Render(HDC hdc)
	{
	}
}
