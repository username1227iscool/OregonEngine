#pragma once

#include "Core.h"
#include "Events/Events.h"

namespace Orgeng {
	class ORGENG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}