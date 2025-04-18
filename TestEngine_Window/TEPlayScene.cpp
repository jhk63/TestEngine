
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
		player = new Player();

		Transform* tr = player->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"Transform");

		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRenderer");
		sr->ImageLoad(L"..\\Resources\\bg.png");

		 AddGameObject(player, eLayerType::Player);

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

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 10, 30, str, wcslen(str));
	}
}