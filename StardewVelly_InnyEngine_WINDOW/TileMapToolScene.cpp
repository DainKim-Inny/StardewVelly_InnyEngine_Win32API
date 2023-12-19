#include "TileMapToolScene.h"
#include "Object.h"
#include "Resources.h"
#include "Texture.h"
#include "Camera.h"
#include "Renderer.h"
#include "Tile.h"
#include "TileMapRenderer.h"
#include "Input.h"

namespace in
{
	TileMapToolScene::TileMapToolScene()
	{
	}

	TileMapToolScene::~TileMapToolScene()
	{
	}
	
	void TileMapToolScene::Initialize()
	{
		//GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, SetVector(0.0f, 0.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;

		Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
		TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();

		tmr->SetTexture(Resources::Find<Texture>(L"TileMap_SpringFarm"));

		Scene::Initialize();
	}
	
	void TileMapToolScene::Update()
	{
		Scene::Update();
	}
	
	void TileMapToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::MouseLB))
		{
			SetVector pos = Input::GetMousePosition();

			int idxX = pos.x / TileMapRenderer::TileSize.x;
			int idyY = pos.y / TileMapRenderer::TileSize.y;

			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();

			tmr->SetTexture(Resources::Find<Texture>(L"TileMap_SpringFarm"));
			tmr->SetIndex(TileMapRenderer::SelectedIndex);

			tile->SetPoistion(idxX, idyY);
		}
	}
	
	void TileMapToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// 격자 무늬 추가 (기존 size에서 2배 키운 크기로 격자 생성)
		for (int i = 0; i < 50; i++)
		{
			MoveToEx(hdc, TileMapRenderer::TileSize.x * i, 0, NULL);
			LineTo(hdc, TileMapRenderer::TileSize.x * i, 5000);
		}

		for (int i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, TileMapRenderer::TileSize.y * i, NULL);
			LineTo(hdc, 5000, TileMapRenderer::TileSize.y * i);
		}
	}
	
	void TileMapToolScene::OnEnter()
	{
		Scene::Update();
	}
	
	void TileMapToolScene::OnExit()
	{
		Scene::Update();
	}
}

// MapToolWindows 창 메시지 출력
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		in::SetVector mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / in::TileMapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / in::TileMapRenderer::OriginTileSize.y;

		in::TileMapRenderer::SelectedIndex = in::SetVector(idxX, idxY);
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		in::Texture* texture = in::Resources::Find<in::Texture>(L"TileMap_SpringFarm");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}