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
		// 카메라 해상도 = 프로그램 해상도
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}
	
	void Camera::Update()
	{
		if (mTarget)  // Target이 있는 경우, 카메라 셋팅
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