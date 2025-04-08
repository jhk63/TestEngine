
#include "TEApplication.h"

#include "TEGameObject.h"
#include "TEInput.h"
#include "TETime.h"


namespace TestEngine
{
	Application::Application()
	{
		//mGameObjects = {};
	}

	Application::~Application()
	{
	}

	bool Application::Initialize(HWND hWnd, UINT width, UINT height)
	{
		bool result;

		mHwnd = hWnd;
		if (!mHwnd) { return false; }

		mHdc = GetDC(hWnd);
		if (!mHdc) { return false; }

		InitializeWindows(width, height);
		InitializeBackBuffer(width, height);

		if (!Input::Initialize()) { return false; }
		if (!Time::Initialize()) { return false; }

		GameObject* mPlayer = new GameObject;
		if (!mPlayer) { return false; }

		mGameObjects.push_back(mPlayer);

		return true;
	}

	void Application::Shutdown()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			delete gameObj;
		}

		mGameObjects.clear();
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

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		ClearRenderTarget(mBackHdc);
		
		Time::Render(mBackHdc);

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(mBackHdc);
		}

		CopyRenderTarget(mBackHdc, mHdc);
	}

	void Application::InitializeWindows(UINT width, UINT height)
	{
		int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
		int posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, posX, posY, mWidth, mHeight, 0);

		ShowWindow(mHwnd, true);
	}

	bool Application::InitializeBackBuffer(UINT width, UINT height)
	{
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		if (!mBackBitmap) { return false; }

		mBackHdc = CreateCompatibleDC(mHdc);
		if (!mBackHdc) { return false; }

		HBITMAP prevBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(prevBitmap);

		return false;
	}

	void Application::ClearRenderTarget(HDC target)
	{
		Rectangle(target, -1, -1, mWidth + 1, mHeight + 1);
	}

	void Application::CopyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}
