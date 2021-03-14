#pragma once

#ifndef _GLAD_GLFW_
#define _GLAD_GLFW_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "../keyboard/keyboard.h"
#include "../mouse/mouse.h"

namespace pix
{
	class Window
	{
	private:
		GLFWwindow * m_Window;
		unsigned int m_Width;
		unsigned int m_Height;

	public:
		Window();
		Window(unsigned int width, unsigned int height, const char* title, unsigned int context_version_maj, unsigned int context_version_min);
		~Window();

		void create(unsigned int width, unsigned int height, const char* title, unsigned int context_version_maj, unsigned int context_version_min);

		unsigned int getWidth();
		unsigned int getHeight();
		GLFWwindow* getGLFWwindowPtr();

		void clear();
		void display();
		void pollEvents();
		void enableVSync(bool value = true);

	private:
		void enableCallbacks();

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void character_callback(GLFWwindow* window, unsigned int codepoint);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void cursor_enter_callback(GLFWwindow* window, int entered);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void window_close_callback(GLFWwindow* window);
	};
}