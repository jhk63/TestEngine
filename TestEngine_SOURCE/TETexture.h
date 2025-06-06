
#pragma once

#include "TEResource.h"


namespace TestEngine
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType = eTextureType::None;
		Gdiplus::Image* mImage = nullptr;
		HBITMAP mBitmap = nullptr;

		HDC mHdc = nullptr;

		UINT mWidth = 0;
		UINT mHeight = 0;
	};
}
