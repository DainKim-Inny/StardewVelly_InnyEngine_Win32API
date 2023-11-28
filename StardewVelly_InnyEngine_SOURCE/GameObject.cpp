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
	}
}