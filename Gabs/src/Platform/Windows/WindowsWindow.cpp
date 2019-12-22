#include "gpch.h"
#include "WindowsWindow.h"
#include "Gabs/Event/ApplicationEvent.h"
#include "Gabs/Event/MouseEvent.h"
#include "Gabs/Event/KeyEvent.h"


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

//Set GLFW callback
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int _width, int _height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			data.width = _width;
			data.height = _height;

			WindowsResizeEvent event(_width, _height);
			data.eventCallback(event);
		});
		
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowsCloseEvent event;
			data.eventCallback(event);
		});
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
