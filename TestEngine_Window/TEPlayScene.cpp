
#include "TEPlayScene.h"

#include "TEGameObject.h"


namespace TestEngine
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	bool PlayScene::Initialize()
	{
		//GameObject* obj = new GameObject;
		//AddGameObject(obj);

		for (int i = 0; i < 20; i++)
		{
			GameObject* obj = new GameObject;
			obj->SetPosition(rand() % 800, rand() % 450);
			AddGameObject(obj);
		}

		return true;
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}