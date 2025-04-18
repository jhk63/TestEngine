
#pragma once

#include "CommonInclude.h"
#include "TEEntity.h"
#include "TEGameObject.h"


namespace TestEngine
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects = {};
	};
}
