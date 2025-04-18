
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

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* player;
	};
}
