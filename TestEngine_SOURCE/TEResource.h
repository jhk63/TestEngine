
#pragma once

#include "TEEntity.h"


namespace TestEngine
{
	class Resource abstract : public Entity
	{
	public:
		Resource(Enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const Enums::eResourceType mType;
		std::wstring mPath;
	};
}
