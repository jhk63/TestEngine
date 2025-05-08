
#include "TEAnimator.h"


namespace TestEngine
{
	Animator::Animator()
		: Component(Enums::eComponentType::Animator),
		mAnimations{},
		mActiveAnimation(nullptr),
		mbLoop(false)
	{
	}

	Animator::~Animator()
	{
	}

	void Animator::Initialize()
	{
	}

	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() == true && mbLoop == true)
			{
				mActiveAnimation->Reset();
			}
		}
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC hdc)
	{
	}

	void Animator::CreateAnimation(const std::wstring& name, Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		return nullptr;
	}

	void Animator::PlayerAnimation(const std::wstring& name, bool loop)
	{
	}
}
