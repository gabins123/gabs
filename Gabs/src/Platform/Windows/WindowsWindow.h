#pragma once

#include <Gabs/Window.h>

#include <GLFW/glfw3.h>

namespace GabsEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowPros& pros);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return data.width; };
		inline unsigned int GetHeight() const override { return data.height; };


		virtual void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; };
		virtual void SetVSync(bool enable) override;
		virtual bool IsVSync() const override;
	private:
		virtual void Init(const WindowPros& pros);
		virtual void Shutdown();
	private:
		GLFWwindow* window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool VSync = false;
			EventCallbackFn eventCallback;
		};

		WindowData data;
	};
}

