#include "Input.h"

using namespace std;

namespace in
{
	vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_SPACE, VK_RETURN,
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 
		VK_OEM_MINUS, VK_OEM_PLUS
	};

	void Input::Initialize()
	{
		for (int i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::NONE;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (int i = 0; i < mKeys.size(); i++)
		{
			if ((GetAsyncKeyState(ASCII[i]) & 0x8000))  // 키가 눌렸을 때
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::PRESSED;
				else
					mKeys[i].state = eKeyState::DOWN;

				mKeys[i].bPressed = true;
			}
			else  // 키가 안 눌렸을 때
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::UP;
				else
					mKeys[i].state = eKeyState::NONE;

				mKeys[i].bPressed = false;
			}
		}
	}
}