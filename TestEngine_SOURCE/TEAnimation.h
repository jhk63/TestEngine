
#pragma once

#include "TEResource.h"
#include "TETexture.h"


using namespace TestEngine::Math;
namespace TestEngine
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero),
				size(Vector2::Zero),
				offset(Vector2::Zero),
				duration(0.f)
			{

			}
		};
		
		Animation();
		~Animation();

		virtual HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(
			const std::wstring& name,
			Texture* spriteSheet,
			Vector2 leftTop, Vector2 size, Vector2 offset,
			UINT spriteLength,
			float duration);

		void Reset();

		bool IsComplete() { return mbComplete;  }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }

	private:
		class Animator* mAnimator;
		Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}
