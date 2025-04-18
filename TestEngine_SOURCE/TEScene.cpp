
#include "TEScene.h"

#include "TEGameObject.h"


namespace TestEngine
{
	Scene::Scene()
	{
		// Create Layer
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	Scene::~Scene()
	{
	}

	bool Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (!layer) continue;

			layer->Initialize();
		}

		return true;
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (!layer) continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (!layer) continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (!layer) continue;

			layer->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* gameObject, eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}
}