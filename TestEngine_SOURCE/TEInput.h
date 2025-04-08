
#pragma once

#include "CommonInclude.h"


namespace TestEngine
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKey(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::Pressed; }
		static bool GetKeyDown(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::Down; }
		static bool GetkeyUp(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::Up; }

	private:
		static void CreateKeys();

	private:
		//eKeyState mState[] = eKeyState::Down;
		static std::vector<Key> mKeys;
	};
}
