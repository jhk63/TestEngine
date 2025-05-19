
#include "TEAnimation.h"

#include "TETime.h"
#include "TETransform.h"
#include "TEAnimator.h"
#include "TEGameObject.h"
#include "TERenderer.h"
#include "TECamera.h"


namespace TestEngine
{
	Animation::Animation()
		: Resource(Enums::eResourceType::Animation),
		mAnimator(nullptr),
		mTexture(nullptr),
		mAnimationSheet{},
		mIndex(-1),
		mTime(0.f),
		mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete) return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
		}
	}

	void Animation::Render(HDC hdc)
	{
		// ���ĺ��带 �� �� �ִ� ���� : �ش� �̹����� ���� ä���� �־���Ѵ�.

		if (mTexture == nullptr) { return; }

		GameObject* gameObject = mAnimator->GetOwner();
		Transform* tr = gameObject->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Renderer::mainCamera)
		{
			pos = Renderer::mainCamera->CalculatePosition(pos);
		}

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // (0(����) - 255(������))

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		AlphaBlend(hdc, 
			pos.x, pos.y, 
			sprite.size.x * 5, sprite.size.y * 5, 
			imgHdc, 
			sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, 
			func);
	}

	void Animation::CreateAnimation(const std::wstring& name, Texture* spriteSheet, 
		Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.f;
		mIndex = 0;
		mbComplete = false;
	}
}
