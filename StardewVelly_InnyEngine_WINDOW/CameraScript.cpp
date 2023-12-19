#include "CameraScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"
#include "Animator.h"
#include "Object.h"

namespace in
{
	CameraScript::CameraScript()
	{
	}

	CameraScript::~CameraScript()
	{
	}
	
	void CameraScript::Initialize()
	{
	}
	
	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::RIGHT))
			pos.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::LEFT))
			pos.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::UP))
			pos.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::DOWN))
			pos.y += 100.0f * Time::DeltaTime();

		tr->SetPos(pos);
	}
	
	void CameraScript::LateUpdate()
	{
	}
	
	void CameraScript::Render(HDC hdc)
	{
	}
}