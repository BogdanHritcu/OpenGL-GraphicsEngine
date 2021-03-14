#pragma once

#include <GLFW/glfw3.h>
#include "../defines/defines.h"

//
#include <iostream>

namespace pix
{
	class Window;

	class Keyboard
	{
	private:
		static GLFWwindow *m_GLFWwindowPtr;
		static bool m_PrevKeyState[pixKEY_COUNT];
		static bool m_CurrKeyState[pixKEY_COUNT];
		static char m_KeyState[pixKEY_COUNT];

	private:
		Keyboard();
		 
	public:
		~Keyboard();
	
		static void setGLFWwindowPtr(GLFWwindow *m_GLFWwindow);
		static bool isPressed(int key);
		static bool hasBeenPressed(int key);
		static bool hasBeenReleased(int key);
		static void setStickyKeys(bool value);

		friend class Window;
	};
}