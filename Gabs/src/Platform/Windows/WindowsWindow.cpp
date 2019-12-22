#include "gpch.h"
#include "WindowsWindow.h"

namespace GabsEngine
{
	static bool isGLFWInit = false;

	Window* Window::Create(const WindowPros& pros)
	{
		return new WindowsWindow(pros);
	}

	WindowsWindow::WindowsWindow(const WindowPros& pros)
	{
		Init(pros);
	}
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowPros& pros)
	{
		data.title = pros.title;
		data.width = pros.width;
		data.height = pros.height;

		CORE_LOG("Create Window {0} ({1} ,  {2})", pros.title, pros.width, pros.height);

		if (!isGLFWInit)
		{
			int success = glfwInit();
			GABS_CORE_ASSERT(success, "Coundn't Init GLFW");

			isGLFWInit = true;
		}

		window = glfwCreateWindow((int)pros.width, (int)pros.height, pros.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	void WindowsWindow::SetVSync(bool enable)
	{
		if (enable)
		{
			glfwSwapInterval(1);
		}
		else
			glfwSwapInterval(0);
		data.VSync = enable;
	}


	bool WindowsWindow::IsVSync() const
	{
		return data.VSync;
	}
}
