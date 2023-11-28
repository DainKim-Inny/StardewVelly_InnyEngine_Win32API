#include "GameObject.h"
#include "Input.h"
#include "Time.h"

namespace in
{
	GameObject::GameObject()
		: mX(0.0f), mY(0.0f)
	{
	}

	GameObject::~GameObject()
	{
	}
	
	void GameObject::Update()
	{
		float speed = 0.0f;

		if(Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}
	}
	
	void GameObject::LateUpdate()
	{
	}
	
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
	}
}