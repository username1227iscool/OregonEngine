#include "ogpch.h"

#pragma once

#include "Core.h"
#include "Events/Events.h"
#include "window.h"
#include "Events/ApplicationEvent.h"

namespace Orgeng {
	class ORGENG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	Application* CreateApplication();
}