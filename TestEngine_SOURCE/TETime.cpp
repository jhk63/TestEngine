
#include "TETime.h"


namespace TestEngine
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};

	float Time::mDeltaTime = 0.f;

	bool Time::Initialize()
	{
		// CPU�� ���� ���� ��
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� ���� ���� �� ���� ���� ��
		QueryPerformanceCounter(&PrevFrequency);

		return true;
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency 
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		mDeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.f;

		time += mDeltaTime;
		float fps = 1.f / mDeltaTime;

		wchar_t str[50] = L"";
		// swprintf_s(str, 50, L"Time: %f", time);
		swprintf_s(str, 50, L"Fps: %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 10, 10, str, len);
	}
}