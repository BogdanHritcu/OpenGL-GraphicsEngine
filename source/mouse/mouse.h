#pragma once

#include "../defines/defines.h"

namespace pix
{
	class Window;

	class Mouse
	{
	private:
		static char m_ButtonState[16];
		static double m_PosX;
		static double m_PosY;
		static double m_OffsetX;
		static double m_OffsetY;

	private:
		Mouse();

	public:
		~Mouse();

		static bool isPressed(int button);
		static bool hasBeenPressed(int button);
		static bool hasBeenReleased(int button);
		static double getX();
		static double getY();
		static double getOffsetX();
		static double getOffsetY();

		friend class Window;
	};
}