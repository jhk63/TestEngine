
#pragma once

#include "..\\TestEngine_SOURCE\\TEScript.h"


namespace TestEngine
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		class Transform* tr;

		float speed = 100.f;
	};
}
