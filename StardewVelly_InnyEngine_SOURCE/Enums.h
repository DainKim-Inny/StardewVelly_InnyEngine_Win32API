#pragma once

namespace in
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
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
		Logo,
		Button,
		Player,
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}