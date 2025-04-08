
#pragma once

#include "TEEntity.h"


namespace TestEngine
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual bool Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(class GameObject* gameObject);

	private:
		std::vector<class GameObject*> mGameObjects = {};
	};
}
