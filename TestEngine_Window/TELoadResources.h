
#pragma once

#include "..\\TestEngine_SOURCE\\TEResources.h"
#include "..\\TestEngine_SOURCE\\TETexture.h"


namespace TestEngine
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"Background", L"..\\Resources\\bg.png");
	}
}