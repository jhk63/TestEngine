
#pragma once

#include "..\\TestEngine_SOURCE\\TESceneManager.h"
#include "TEPlayScene.h"


namespace TestEngine
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}