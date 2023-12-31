#include "Application.h"
#include "Input.h"
#include "Time.h"
#include "SceneManager.h"
#include "Resources.h"
#include "CollisionManager.h"

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

		CollisionManager::Initailize();
		SceneManager::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void Application::clearRenderTarget()
	{
		// clear
		Rectangle(mBackHdc, -10, -10, 1500, 800);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer에 있는 것을 원본 Buffer에 복사
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백퍼버(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가리킬 DC 생성
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
