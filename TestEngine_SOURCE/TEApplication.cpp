
#include "TEApplication.h"


namespace TestEngine
{
	Application::Application()
	{
		mHwnd = nullptr;
		mHdc = nullptr;
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();

		Render();
	}

	void Application::Update()
	{
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}
