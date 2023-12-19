#include "TileMapToolScene.h"
#include "Object.h"
#include "Resources.h"
#include "Texture.h"
#include "Camera.h"
#include "Renderer.h"
#include "Tile.h"
#include "TileMapRenderer.h"
#include "Input.h"
#include "CameraScript.h"

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
		GameObject* camera = Object::Instantiate<GameObject>(eLayerType::None, SetVector(709.0f, 490.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();

		renderer::mainCamera = cameraComp;

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
			pos = renderer::mainCamera->CalculateTilePosition(pos);

			if (pos.x >= 0.0f && pos.y >= 0.0f)
			{
				int idxX = pos.x / TileMapRenderer::TileSize.x;
				int idxY = pos.y / TileMapRenderer::TileSize.y;

				Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile);
				TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();

				tmr->SetTexture(Resources::Find<Texture>(L"TileMap_SpringFarm"));
				tmr->SetIndex(TileMapRenderer::SelectedIndex);

				tile->SetIndexPosition(idxX, idxY);
				mTiles.push_back(tile);
			}
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			Load();
		}
	}
	
	void TileMapToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// 격자 무늬 추가 (기존 size에서 2배 키운 크기로 격자 생성)
		for (int i = 0; i < 100; i++)
		{
			SetVector pos = renderer::mainCamera->CalculatePosition
			(
				SetVector(TileMapRenderer::TileSize.x * i, 0.0f)
			);

			MoveToEx(hdc, pos.x, 0, NULL);
			LineTo(hdc, pos.x, 5000);
		}

		for (int i = 0; i < 100; i++)
		{
			SetVector pos = renderer::mainCamera->CalculatePosition
			(
				SetVector(0.0f, TileMapRenderer::TileSize.y * i)
			);

			MoveToEx(hdc, 0, pos.y, NULL);
			LineTo(hdc, 5000, pos.y);
		}
	}
	
	void TileMapToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	
	void TileMapToolScene::OnExit()
	{
		Scene::OnExit();
	}

	void TileMapToolScene::Save()
	{
		// Open a file name
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (Tile* tile : mTiles)
		{
			TileMapRenderer* tmr = tile->GetComponent<TileMapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();

			SetVector sourceIndex = tmr->GetIndex();
			SetVector position = tr->GetPosition();

			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);

			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);

			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}
	
	void TileMapToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = Object::Instantiate <Tile>(eLayerType::Tile, SetVector(posX, posY));
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<Texture>(L"TileMap_SpringFarm"));
			tmr->SetIndex(SetVector(idxX, idxY));

			tile->SetIndexPosition(posX, posY);
			mTiles.push_back(tile);
		}

		fclose(pFile);
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