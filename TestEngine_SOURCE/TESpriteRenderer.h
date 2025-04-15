
#pragma once

#include "TEComponent.h"


namespace TestEngine
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

		void ExamplePrintRectangle(HDC hdc);

	private:
		Gdiplus::Image* mImage = nullptr;
		UINT mWidth = 0;
		UINT mHeight = 0;
	};
}
