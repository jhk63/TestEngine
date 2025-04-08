
#include "TESceneManager.h"


namespace TestEngine
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	bool TestEngine::SceneManager::Initialize()
	{
		return true;
	}

	void TestEngine::SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void TestEngine::SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void TestEngine::SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}
