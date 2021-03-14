#include "keyboard.h"

namespace pix
{
	Keyboard::~Keyboard()
	{
		
	}

	void Keyboard::setGLFWwindowPtr(GLFWwindow *m_GLFWwindow)
	{
		Keyboard::m_GLFWwindowPtr = m_GLFWwindow;
	}

	bool Keyboard::isPressed(int key)
	{	
		return Keyboard::m_KeyState[key] == GLFW_PRESS || Keyboard::m_KeyState[key] == GLFW_REPEAT;
	}
	
	bool Keyboard::hasBeenPressed(int key)
	{
		bool state = Keyboard::m_KeyState[key] == GLFW_PRESS;

		if (state)
		{
			Keyboard::m_KeyState[key] = -1;
		}

		return state;
	}

	bool Keyboard::hasBeenReleased(int key)
	{
		bool state = Keyboard::m_KeyState[key] == GLFW_RELEASE;

		if (state)
		{
			Keyboard::m_KeyState[key] = -1;
		}

		return state;
	}

	void Keyboard::setStickyKeys(bool value)
	{
		glfwSetInputMode(Keyboard::m_GLFWwindowPtr, GLFW_STICKY_KEYS, value ? GLFW_TRUE : GLFW_FALSE);
	}

	GLFWwindow *Keyboard::m_GLFWwindowPtr = NULL;
	char Keyboard::m_KeyState[pixKEY_COUNT];
}