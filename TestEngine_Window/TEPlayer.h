
#pragma once

#include "..\\TestEngine_SOURCE\\TEGameObject.h"


namespace TestEngine
{
	class Player : public GameObject
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;
	};
}
