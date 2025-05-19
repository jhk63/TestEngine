
#pragma once

#include "..\\TestEngine_SOURCE\\TEResources.h"
#include "..\\TestEngine_SOURCE\\TETexture.h"


namespace TestEngine
{
	void LoadResources()
	{
		Resources::Load<Texture>(L"Background", L"..\\Resources\\FlappyBird\\Background\\Background2.png");
		Resources::Load<Texture>(L"FlameDemon", L"..\\Resources\\FlameDemon.png");
		//Resources::Load<Texture>(L"Player", L"..\\Resources\\FlappyBird\\Player\\StyleBird1\\AllBird1.png");
		Resources::Load<Texture>(L"Player", L"..\\Resources\\FlappyBird\\Player\\StyleBird1\\Test.bmp");
	}
}