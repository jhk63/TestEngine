
#pragma once

#include "CommonInclude.h"

#include "TEScene.h"


namespace TestEngine
{
	class SceneManager
	{
	public:
		
		static bool Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;

			scene->Initialize();
			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			if (mActiveScene != nullptr)
			{
				mActiveScene->OnExit();
			}
			
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);

			if (iter == mScene.end())
			{
				return nullptr;
			}

			mActiveScene = iter->second;
			mActiveScene->OnEnter();

			return iter->second;
		}

		static Scene* GetActiveScene() { return mActiveScene; }
	
	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}
