
#include "TETitleScene.h"


namespace TestEngine
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	bool TitleScene::Initialize()
	{
		Scene::Initialize();

		return true;
	}

	void TitleScene::Update()
	{
		Scene::Update();

		
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 10, 30, str, wcslen(str));
	}
}