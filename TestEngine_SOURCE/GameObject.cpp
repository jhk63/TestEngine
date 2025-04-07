
#include "GameObject.h"
#include "Input.h"


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
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH prevBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, 500 + mX, 500 + mY, 600 + mX, 600 + mY);

		SelectObject(hdc, prevBrush);
		DeleteObject(brush);
	}
}
