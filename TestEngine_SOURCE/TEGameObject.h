
#pragma once

#include "CommonInclude.h"


namespace TestEngine
{
	// Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC);

		void SetPosition(float x, float y) { mX = x; mY = y; }

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX = 0;
		float mY = 0;
	};
}
