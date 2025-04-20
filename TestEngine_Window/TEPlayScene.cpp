
#include "TEPlayScene.h"

#include "TEGameObject.h"
#include "TEPlayer.h"
#include "TETransform.h"
#include "TESpriteRenderer.h"
#include "TEObject.h"
#include "TETexture.h"
#include "TEResources.h"


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
		// 게임 오브젝트를 만들기 전에 먼저 리소스들을 전부 Load 해두면 좋다.

		player = Object::Instantiate<Player>(Enums::eLayerType::Player, Vector2(100, 0));

		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRenderer");
		sr->SetTexture(Resources::Find<Texture>(L"Background"));
		// sr->ImageLoad(L"..\\Resources\\bg.png");

		// Texture* texture = new Texture();
		// texture->Load(L"..\\Resources\\bg.png");

		AddGameObject(player, Enums::eLayerType::Player);

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

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
	}
}