#include "ogpch.h"

#pragma once

#include "Core.h"
#include "Events/Events.h"
#include "Events/ApplicationEvent.h"
#include "window.h"
#include "LayerStack.h"

namespace Orgeng {
	class ORGENG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	Application* CreateApplication();
}