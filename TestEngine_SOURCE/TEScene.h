
#pragma once

#include "TEEntity.h"
#include "TELayer.h"


namespace TestEngine
{
	class GameObject;
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual bool Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, eLayerType type);

		Layer* GetLayer(eLayerType Type) { return mLayers[(UINT)Type]; }

	private:
		std::vector<Layer*> mLayers;
	};
}
