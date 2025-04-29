
#include "TEComponent.h"


namespace TestEngine
{
    Component::Component(Enums::eComponentType ComponentType)
		: mComponentType(ComponentType)
    {
    }

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}