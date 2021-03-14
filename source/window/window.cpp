#include "window.h"

namespace pix
{
	Window::Window()
	{
		m_Window = NULL;
	}

	Window::Window(unsigned int width, unsigned int height, const char* title, unsigned int context_version_maj, unsigned int context_version_min)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, context_version_maj);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, context_version_min);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

		m_Width = width;
		m_Height = height;

		if (m_Window == NULL)
		{
			std::cout << "Failed to create window!" << std::endl;
			glfwTerminate();
		}
		else
		{
			glfwMakeContextCurrent(m_Window);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD!" << std::endl;
				glfwTerminate();
			}
			else
			{
				enableCallbacks();

				//
				Keyboard::setGLFWwindowPtr(m_Window);
			}
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::create(unsigned int width, unsigned int height, const char* title, unsigned int context_version_maj, unsigned int context_version_min)
	{
		if (m_Window == NULL)
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, context_version_maj);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, context_version_min);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

			m_Width = width;
			m_Height = height;

			if (m_Window == NULL)
			{
				std::cout << "Failed to create window!" << std::endl;
				glfwTerminate();
			}
			else
			{
				glfwMakeContextCurrent(m_Window);

				if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				{
					std::cout << "Failed to initialize GLAD!" << std::endl;
					glfwTerminate();
				}
				else
				{
					enableCallbacks();

					//
					Keyboard::setGLFWwindowPtr(m_Window);
				}
			}
		}
	}

	unsigned int Window::getWidth()
	{
		return m_Width;
	}

	unsigned int Window::getHeight()
	{
		return m_Height;
	}

	GLFWwindow* Window::getGLFWwindowPtr()
	{
		return m_Window;
	}

	void Window::enableVSync(bool value)
	{
		glfwSwapInterval((int)value);
	}

	void Window::enableCallbacks()
	{
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetCharCallback(m_Window, character_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		glfwSetCursorEnterCallback(m_Window, cursor_enter_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetScrollCallback(m_Window, scroll_callback);
		glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
		glfwSetWindowCloseCallback(m_Window, window_close_callback);
	}

	void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		{
			glfwSetWindowShouldClose(window , GLFW_TRUE);
		}

		Keyboard::m_KeyState[key] = action;
	}

	void Window::character_callback(GLFWwindow *window, unsigned int codepoint)
	{

	}

	void Window::cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
	{
		Mouse::m_PosX = xpos;
		Mouse::m_PosY = ypos;
	}

	void Window::cursor_enter_callback(GLFWwindow *window, int entered)
	{

	}

	void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
	{
		Mouse::m_ButtonState[button] = action;
	}

	void Window::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
	{
		Mouse::m_OffsetX = xoffset;
		Mouse::m_OffsetY = yoffset;
	}

	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::window_close_callback(GLFWwindow* window)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}