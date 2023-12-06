#include "BirdScript.h"
#include "Time.h"
#include "Transform.h"
#include "GameObject.h"

namespace in
{
	BirdScript::BirdScript()
	{
	}

	BirdScript::~BirdScript()
	{
	}
	
	void BirdScript::Initialize()
	{
	}
	
	void BirdScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		SetVector pos = tr->GetPosition();
		pos.x -= 2.0f;

		if (pos.x < -10.0f)
			pos.x = 1420.0;

		tr->SetPos(pos);
	}
	
	void BirdScript::LateUpdate()
	{
	}
	
	void BirdScript::Render(HDC hdc)
	{
	}
}