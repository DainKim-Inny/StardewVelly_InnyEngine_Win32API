#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

namespace in
{
	SpriteRenderer::SpriteRenderer()
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}
	
	void SpriteRenderer::Initialize()
	{
	}
	
	void SpriteRenderer::Update()
	{
	}
	
	void SpriteRenderer::LateUpdate()
	{
	}
	
	void SpriteRenderer::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Ellipse(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
	}
}