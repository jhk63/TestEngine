
#include "TEApplication.h"

#include "TEInput.h"
#include "TETime.h"


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

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();

		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Time::Render(mHdc);

		mPlayer.Render(mHdc);
	}
}
