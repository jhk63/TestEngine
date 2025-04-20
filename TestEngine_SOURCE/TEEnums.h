
#pragma once


namespace TestEngine::Enums
{
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
		Prefab,
		End,
	};
}