
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

		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}

	void SpriteRenderer::ExamplePrintRectangle(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();

		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH prevBrush = (HBRUSH)SelectObject(hdc, brush);

		// Rectangle(hdc, tr->GetX(), tr->GetY(), tr->GetX() + 100, tr->GetY() + 100);

		SelectObject(hdc, prevBrush);
		DeleteObject(brush);
	}
}
