
#pragma once

#include "TELayer.h"
#include "TEGameObject.h"
#include "TEComponent.h"
#include "TESceneManager.h"
#include "TEScene.h"


namespace TestEngine::Object
{
	template <typename T>
	static T* Instantiate(TestEngine::Enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(TestEngine::Enums::eLayerType type, Math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}