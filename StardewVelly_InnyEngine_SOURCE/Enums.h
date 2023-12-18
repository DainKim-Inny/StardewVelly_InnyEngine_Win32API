#pragma once

namespace in
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End
	};

	enum class eLayerType
	{
		None,
		BackGround,
		BackGroundObject_Bottom,
		BackGroundObject_Middle,
		BackGroundObject_Top,
		Logo_Bottom,
		Logo_Top,
		Button, 
		Tile,
		Object,
		Player,
		UI,
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}