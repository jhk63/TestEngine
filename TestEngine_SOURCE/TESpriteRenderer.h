
#pragma once

#include "TEComponent.h"
#include "TETexture.h"


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

		void SetTexture(Texture* texture) { mTexture = texture; }
		void SetSize(Math::Vector2 size) { mSize = size; }

	private:
		Texture* mTexture;
		Math::Vector2 mSize = Math::Vector2::One;
	};
}
