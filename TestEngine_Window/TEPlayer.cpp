
#include "TEPlayer.h"

#include "TETransform.h"


namespace TestEngine
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		Transform* tr = GetComponent<Transform>();

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH prevBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

		SelectObject(hdc, prevBrush);
		DeleteObject(brush);

		GameObject::Render(hdc);
	}
}
