
#include "TECamera.h"

#include "TEGameObject.h"
#include "TETransform.h"


namespace TestEngine
{
	Camera::Camera()
		: Component(Enums::eComponentType::Camera),
		mDistance(Vector2::Zero),
		mResolution(1600.f, 900.f),
		mLookPosition(Vector2::Zero),
		mTarget(nullptr)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Initialize()
	{
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		mDistance = mLookPosition - (mResolution / 2.f);
	}

	void Camera::LateUpdate()
	{
	}

	void Camera::Render(HDC hdc)
	{
	}
}