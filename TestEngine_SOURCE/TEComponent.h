
#pragma once

#include "TEEntity.h"


namespace TestEngine
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(Enums::eComponentType ComponentType);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }
		Enums::eComponentType GetComponentType() { return mComponentType; }

	private:
		GameObject* mOwner = 0;
		Enums::eComponentType mComponentType;
	};
}
