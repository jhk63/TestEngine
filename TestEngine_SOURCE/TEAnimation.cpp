
#include "TEAnimation.h"

#include "TETime.h"


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
		if (!mbComplete) return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
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
	}

	void Animation::CreateAnimation(const std::wstring& name, Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
	}

	void Animation::Reset()
	{
		mTime = 0.f;
		mIndex = 0;
		mbComplete = false;
	}
}
