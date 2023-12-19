#include "Tile.h"
#include "Transform.h"
#include "TileMapRenderer.h"

namespace in
{
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}

	void Tile::Update()
	{
		GameObject::Update();
	}
	
	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	
	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Tile::SetIndexPosition(int x, int y)
	{
		Transform* tr = GetComponent<Transform>();
		SetVector pos;
		pos.x = x * TileMapRenderer::TileSize.x;
		pos.y = y * TileMapRenderer::TileSize.y;
		tr->SetPos(pos);
	}
}