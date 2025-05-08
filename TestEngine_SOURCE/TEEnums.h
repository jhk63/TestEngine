
#pragma once


namespace TestEngine::Enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		Animator,
		End,
	};

	enum class eLayerType
	{
		None,
		Background,
		// Character,
		Player,
		Max = 16,
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