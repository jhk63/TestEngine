
#include "TEPlayScene.h"

#include "TEGameObject.h"
#include "TEPlayer.h"
#include "TETransform.h"
#include "TESpriteRenderer.h"
#include "TEObject.h"
#include "TETexture.h"
#include "TEResources.h"
#include "TECamera.h"
#include "TEPlayerScript.h"
#include "TERenderer.h"


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
		// Main Camera
		GameObject* camera = Object::Instantiate<GameObject>(Enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComp;
		camera->AddComponent<PlayerScript>();

		// 게임 오브젝트를 만들기 전에 먼저 리소스들을 전부 Load 해두면 좋다.
		player = Object::Instantiate<Player>(Enums::eLayerType::Player, Vector2(100, 100));
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRenderer");
		sr->SetTexture(Resources::Find<Texture>(L"FlameDemon"));
		sr->SetSize(Vector2(3, 3));

		background = Object::Instantiate<Player>(Enums::eLayerType::Background, Vector2(0, 0));
		SpriteRenderer* bgSr = background->AddComponent<SpriteRenderer>();
		bgSr->SetName(L"SpriteRenderer");
		bgSr->SetTexture(Resources::Find<Texture>(L"Background"));

		AddGameObject(player, Enums::eLayerType::Player);
		AddGameObject(background, Enums::eLayerType::Background);

		Scene::Initialize();

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