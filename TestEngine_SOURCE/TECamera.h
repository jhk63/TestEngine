
#pragma once

#include "TEComponent.h"


namespace TestEngine
{
	using namespace Math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		// std::vector<GameObject*> mGameObjects;

		Vector2 mDistance;
		Vector2 mPosition;
		Vector2 mResolution;
		Vector2 mLookPosition;

		class GameObject* mTarget;
	};
}
