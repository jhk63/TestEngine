
#include "TETexture.h"

#include "TEApplication.h"


extern TestEngine::Application application;

namespace TestEngine
{
	Texture::Texture()
		: Resource(Enums::eResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		
		// Bmp
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 
											0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			if (!mBitmap) return S_FALSE;

			BITMAP bmp = {};
			GetObject(mBitmap, sizeof(BITMAP), &bmp);

			mWidth = bmp.bmWidth;
			mHeight = bmp.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);
			HBITMAP prevBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(prevBitmap);
		}
		// Png
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (!mImage) return S_FALSE;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}
}
