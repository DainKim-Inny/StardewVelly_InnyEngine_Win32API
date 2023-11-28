#include "Application.h"
#include "Input.h"
#include "Time.h"
#include "SceneManger.h"

namespace in
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		InitializeEtc();

		SceneManger::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		SceneManger::Update();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		clearRenderTarger();

		Time::Render(mBackHdc);
		SceneManger::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarger()
	{
		// clear
		Rectangle(mBackHdc, -10, -10, 1410, 710);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer�� �ִ� ���� ���� Buffer�� ����
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}


	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� ���۹�(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::InitializeEtc()
	{
		Input::Initialize();
		Time::Initailize();
	}
}
