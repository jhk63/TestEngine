
#pragma once

#include "CommonInclude.h"

#include "TEComponent.h"


namespace TestEngine
{
	// Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetComponentType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* targetComp = nullptr;
			for (Component* comp : mComponents)
			{
				// RTTI
				targetComp = dynamic_cast<T*>(comp);
				if (targetComp)
				{
					break;
				}
			}

			return targetComp;
		}

	private:
		void InitializeTransform();

	private:
		std::vector<Component*> mComponents;
	};
}
