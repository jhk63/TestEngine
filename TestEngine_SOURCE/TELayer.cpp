
#include "TELayer.h"


namespace TestEngine
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (!gameObject) continue;

			gameObject->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (!gameObject) continue;

			gameObject->Update();
		}
		
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (!gameObject) continue;

			gameObject->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObject : mGameObjects)
		{
			if (!gameObject) continue;

			gameObject->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (!gameObject) return;

		mGameObjects.push_back(gameObject);
	}
}
