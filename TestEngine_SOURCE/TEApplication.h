
#pragma once

#include "CommonInclude.h"
#include "TEGameObject.h"


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

		GameObject mPlayer;
	};
}
