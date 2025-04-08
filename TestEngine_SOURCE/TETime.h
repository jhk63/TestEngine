
#pragma once

#include "CommonInclude.h"


namespace TestEngine
{
	class Time
	{
	public:
		static bool Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return mDeltaTime; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;

		static float mDeltaTime;
	};
}
