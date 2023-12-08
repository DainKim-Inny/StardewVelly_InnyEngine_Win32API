#pragma once
#include "CommonHeader.h"

using namespace std;

namespace in
{
	enum class eKeyState
	{
		DOWN,
		PRESSED,
		UP,
		NONE
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		RIGHT, LEFT, UP, DOWN, SPACE, ENTER,
		ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ZERO, MINUS, PLUS,
		LButton, RButton,
		End
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

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::DOWN; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::UP; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::PRESSED; }

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);

	private:
		static vector<Key> mKeys;
		static SetVector mMousePosition;
	};
}