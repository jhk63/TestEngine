
#pragma once

#include "CommonInclude.h"


namespace TestEngine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mX = 0;
		float mY = 0;
	};
}
