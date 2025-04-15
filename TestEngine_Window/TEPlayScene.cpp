
#include "TEPlayScene.h"

#include "TEGameObject.h"
#include "TEPlayer.h"
#include "TETransform.h"
#include "TESpriteRenderer.h"


namespace TestEngine
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	bool PlayScene::Initialize()
	{
		Player* player = new Player();
		Transform* tr = player->AddComponent<Transform>();
		tr->SetPos(600, 450);
		tr->SetName(L"Transform");
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRenderer");

		AddGameObject(player);

		return true;
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}