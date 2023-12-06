#include "buttonScript.h"
#include "Time.h"
#include "GameObject.h"
#include "Transform.h"
#include "Input.h"

namespace in
{
	buttonScript::buttonScript()
		: mSpeed(0.0f)
	{
	}

	buttonScript::~buttonScript()
	{
	}
	
	void buttonScript::Initialize()
	{
	}
	
	void buttonScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();
		pos.y -= mSpeed * Time::DeltaTime();

		if (pos.y > 450.0f)
			mSpeed = 100.0f;
		else
			mSpeed = 0.0f;

		if (Input::GetKey(eKeyCode::SPACE))
			pos.y = 450.0f;

		tr->SetPos(pos);
	}
	
	void buttonScript::LateUpdate()
	{
	}
	
	void buttonScript::Render(HDC hdc)
	{
	}
}