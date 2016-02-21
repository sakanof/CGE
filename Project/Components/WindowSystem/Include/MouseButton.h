#ifndef WindowSystem_Input_Mouse_MouseButton_H
#define WindowSystem_Input_Mouse_MouseButton_H

namespace WindowSystem
{
	namespace Input
	{
		namespace Mouse
		{
			enum class MouseButton
			{
				Button1 = 0, /** < Left button. */
				Button2 = 1, /** < Right button. */
				Button3 = 2, /** < Middle or scroll button. */
				Button4 = 3, /** < Fourth button. */
				Button5 = 4, /** < Fifth button. */
				Button6 = 5, /** < Sixth button. */
				Button7 = 6, /** < Seventh button. */
				Button8 = 7, /** < Eighth button. */
				Button9 = 8  /** < Ninth button. */
			};

			enum class MouseButtonState
			{
				Click   = 0, 
				Hold    = 1, 
				Release = 2
			};
		};
	};
};

#endif // WindowSystem_Input_Mouse_MouseButton_H