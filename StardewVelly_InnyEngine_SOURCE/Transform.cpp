#include "Transform.h"

namespace in
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mPosition{}
		, mScale(SetVector::One)
	{
	}

	Transform::~Transform()
	{
	}
	
	void Transform::Initialize()
	{
	}
	
	void Transform::Update()
	{
	}
	
	void Transform::LateUpdate()
	{
	}
	
	void Transform::Render(HDC hdc)
	{
	}
}