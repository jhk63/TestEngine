
#pragma once

#include "CommonInclude.h"


namespace TestEngine
{
	class Application
	{
	public:
		Application();
		~Application();

		bool Initialize(HWND hWnd, UINT width, UINT height);
		void Shutdown();
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		void InitializeWindows(UINT width, UINT height);
		bool InitializeBackBuffer(UINT width, UINT height);

		void ClearRenderTarget(HDC target);
		void CopyRenderTarget(HDC source, HDC dest);

	private:
		HWND mHwnd = nullptr;
		HDC mHdc = nullptr;

		HDC mBackHdc = nullptr;
		HBITMAP mBackBitmap = nullptr;

		UINT mWidth = 0;
		UINT mHeight = 0;

	};
}
