#include "mouse.h"

namespace pix
{
	Mouse::~Mouse()
	{

	}

	bool Mouse::isPressed(int button)
	{
		return Mouse::m_ButtonState[button] == GLFW_PRESS || Mouse::m_ButtonState[button] == GLFW_REPEAT;
	}

	bool Mouse::hasBeenPressed(int button)
	{
		bool state = Mouse::m_ButtonState[button] == GLFW_PRESS;

		if (state)
		{
			Mouse::m_ButtonState[button] = -1;
		}

		return state;
	}

	bool Mouse::hasBeenReleased(int button)
	{
		bool state = Mouse::m_ButtonState[button] == GLFW_RELEASE;

		if (state)
		{
			Mouse::m_ButtonState[button] = -1;
		}

		return state;
	}

	double Mouse::getX()
	{
		return Mouse::m_PosX;
	}

	double Mouse::getY()
	{
		return Mouse::m_PosY;
	}

	double Mouse::getOffsetX()
	{
		return Mouse::m_OffsetX;
	}

	double Mouse::getOffsetY()
	{
		return Mouse::m_OffsetY;
	}

	char Mouse::m_ButtonState[pixBUTTON_COUNT];
	double Mouse::m_PosX = 0.0;
	double Mouse::m_PosY = 0.0;
	double Mouse::m_OffsetX = 0.0;
	double Mouse::m_OffsetY = 0.0;
}
