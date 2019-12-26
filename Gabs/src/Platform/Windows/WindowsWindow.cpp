
#include "gpch.h"
#include "WindowsWindow.h"
#include "Gabs/Event/ApplicationEvent.h"
#include "Gabs/Event/MouseEvent.h"
#include "Gabs/Event/KeyEvent.h"
#include "glad/glad.h"


namespace GabsEngine
{
	static bool isGLFWInit = false;
	static void GLFWErrorCallback(int error, const char* description)
	{
		CORE_LOGERROR("GLFW error {0}: {1}", error, description);
	}
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
			glfwSetErrorCallback(GLFWErrorCallback);
			isGLFWInit = true;
		}

		window = glfwCreateWindow((int)pros.width, (int)pros.height, pros.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GABS_ASSERT(status, "Failed to init glad");

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
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key, 0);
					data.eventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasdEvent e(key);
					data.eventCallback(e);
					break;

				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key, 1);
					data.eventCallback(e);
					break;
				}
			}
		});
		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button,  int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					data.eventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.eventCallback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float)xOffset, (float)yOffset);
			data.eventCallback(e);

		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent e((float)xPos, (float)yPos);
			data.eventCallback(e);
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
