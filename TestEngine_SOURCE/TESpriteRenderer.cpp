
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
		if (!mTexture) assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetTextureType() == Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc,
				pos.x, pos.y,
				mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y,
				mTexture->GetHdc(), 0, 0, 
				mTexture->GetWidth(), mTexture->GetHeight(), 
				RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), 
				Gdiplus::Rect(
					pos.x, pos.y, 
					mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				));
		} 
		
	}

}
