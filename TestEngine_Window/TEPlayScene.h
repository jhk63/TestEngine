
#pragma once

#include "..\\TestEngine_SOURCE\\TEScene.h"


namespace TestEngine
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		bool Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
