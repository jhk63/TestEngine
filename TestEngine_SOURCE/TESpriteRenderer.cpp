
#include "TESpriteRenderer.h"

#include "TEGameObject.h"
#include "TETransform.h"


namespace TestEngine
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
		Transform* tr = GetOwner()->GetComponent<Transform>();

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH prevBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

		SelectObject(hdc, prevBrush);
		DeleteObject(brush);
	}
}
