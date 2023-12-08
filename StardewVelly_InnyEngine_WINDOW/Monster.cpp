#include "Monster.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"

namespace in
{
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	
	void Monster::Update()
	{
		GameObject::Update();
	}
	
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	
	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
