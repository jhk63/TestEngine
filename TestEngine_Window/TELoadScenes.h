
#pragma once

#include "..\\TestEngine_SOURCE\\TESceneManager.h"

#include "TETitleScene.h"
#include "TEPlayScene.h"


namespace TestEngine
{
	void LoadScenes()
	{
		// SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}