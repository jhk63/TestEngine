
#pragma once

#include "CommonInclude.h"
#include "GameObject.h"


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
