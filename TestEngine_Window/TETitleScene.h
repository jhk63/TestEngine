
#pragma once

#include "..\\TestEngine_SOURCE\\TEScene.h"


namespace TestEngine
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();
		bool Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}
