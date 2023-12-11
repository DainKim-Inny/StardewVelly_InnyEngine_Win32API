#include "Camera.h"
#include "Application.h"
#include "Transform.h"
#include "GameObject.h"

extern in::Application application;

namespace in
{
	Camera::Camera()
		: Component(eComponentType::Camera)
		, mDistance(SetVector::Zero)
		, mResolution(SetVector::Zero)
		, mLookPosition(SetVector::Zero)
		, mTarget(nullptr)
	{
	}

	Camera::~Camera()
	{
	}
	
	void Camera::Initialize()
	{
		// ī�޶� �ػ� = ���α׷� �ػ�
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}
	
	void Camera::Update()
	{
		if (mTarget)  // Target�� �ִ� ���, ī�޶� ����
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	
	void Camera::LateUpdate()
	{
	}
	
	void Camera::Render(HDC hdc)
	{
	}
}