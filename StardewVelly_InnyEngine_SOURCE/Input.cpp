#include "Input.h"
#include "Application.h"

extern in::Application application;

using namespace std;

namespace in
{
	vector<Input::Key> Input::mKeys = {};
	SetVector Input::mMousePosition = SetVector::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_SPACE, VK_RETURN,
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 
		VK_OEM_MINUS, VK_OEM_PLUS,
		VK_LBUTTON, VK_RBUTTON
	};

	void Input::Initialize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
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

	void Input::UpdateKeys()
	{
		for_each(mKeys.begin(), mKeys.end(),
			[](Key& key)->void
		{
			UpdateKey(key);
		});
	}

	void Input::UpdateKey(Input::Key& key)
	{
		if (IsKeyDown(key.keyCode))
			UpdateKeyDown(key);
		else
			UpdateKeyUp(key);
	}

	bool Input::IsKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::UpdateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::PRESSED;
		else
			key.state = eKeyState::DOWN;

		key.bPressed = true;
	}

	void Input::UpdateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::UP;
		else
			key.state = eKeyState::NONE;

		key.bPressed = false;
	}
}