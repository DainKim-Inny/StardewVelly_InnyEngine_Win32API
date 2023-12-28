#include "Collider.h"
#include "GameObject.h"
#include "Script.h"

namespace in
{
	UINT Collider::CollisionID = 1;

	Collider::Collider()
		: Component(eComponentType::Colider)
		, mID(CollisionID++)
		, mSize(SetVector::One)
	{
	}

	Collider::~Collider()
	{
	}
	
	void Collider::Initialize()
	{
	}
	
	void Collider::Update()
	{
	}
	
	void Collider::LateUpdate()
	{
	}
	
	void Collider::Render(HDC hdc)
	{
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}
	
	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}
	
	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}
}