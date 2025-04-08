
#include "TEGameObject.h"

#include "TEInput.h"
#include "TETime.h"


namespace TestEngine
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 200.f;

		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HBRUSH prevBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, 500 + mX, 500 + mY, 600 + mX, 600 + mY);

		SelectObject(hdc, prevBrush);
		DeleteObject(brush);
	}
}
