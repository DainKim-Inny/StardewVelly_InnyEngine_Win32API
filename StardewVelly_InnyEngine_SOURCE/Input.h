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
		MouseLB, MouseRB,
		ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO,
		PLUS, MIUS,
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

		// Ű���� state�� ���� �Լ�
		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::DOWN; };
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::UP; };
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::PRESSED; };

		// ���콺 Position 
		static SetVector GetMousePosition() { return mMousePosition; }

	private:
		static void getMousePositionByWindow();
		static void clearKeys();

	private:
		static vector<Key> mKeys; // ��� Ŭ���� �ȿ����� ������ �����ؾ��ϹǷ� ���� ������ ����
		static SetVector mMousePosition;
	};
}