#pragma once
#include "..\\StardewVelly_InnyEngine_SOURCE\\Scene.h"
#include "Tile.h"

using namespace std;

namespace in
{
	class TileMapToolScene : public Scene
	{
	public:
		TileMapToolScene();
		~TileMapToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		void Save();
		void Load();

	private:
		void renderGreed(HDC hdc);
		void createTileObject();

	private:
		vector<Tile*> mTiles;
	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);