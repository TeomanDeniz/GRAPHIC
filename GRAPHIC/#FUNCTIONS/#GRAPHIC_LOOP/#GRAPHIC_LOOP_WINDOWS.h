/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP_WINDOWS    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/03/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <winuser.h> /*
#	 define PeekMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg)
#	 define PM_REMOVE
#	 define WM_QUIT
#	 define DispatchMessage(lpMsg)
#	typedef MSG;
#	typedef LARGE_INTEGER;
#	   BOOL TranslateMessage(MSG *);
#	   BOOL InvalidateRect(HWND, LPCRECT, BOOL);
#	   BOOL QueryPerformanceFrequency(LARGE_INTEGER *);
#	   BOOL QueryPerformanceCounter(LARGE_INTEGER *);
#	   BOOL UpdateWindow(HWND);
#	        */
#	include <windef.h> /*
#	 define TRUE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	MSG				EVENT_MSG = {0};
	LARGE_INTEGER	FREQUENCY;
	LARGE_INTEGER	START;
	double			DELTA_FPS_LIMIT;

	QueryPerformanceFrequency(&FREQUENCY);
	QueryPerformanceCounter(&START);
	DELTA_FPS_LIMIT = (1.0 / (double)GRAPHIC->FPS);

	if (!!GRAPHIC->FUNCTION_LOOP)
	{
		if (GRAPHIC->WINDOW_STYLE.TRANSPARENCY)
		{
			while (PeekMessage(&EVENT_MSG, ((void *)0), 0, 0, PM_REMOVE) || 1)
			{
				LARGE_INTEGER	END;
				register double	ELAPSED_TIME;

				if (EVENT_MSG.message == WM_QUIT)
					return (1);

				TranslateMessage(&EVENT_MSG);
				DispatchMessage(&EVENT_MSG);

				QueryPerformanceCounter(&END);
				ELAPSED_TIME = (double)(
					(double)(
						END.QuadPart - START.QuadPart
					) / FREQUENCY.QuadPart
				);

				if (ELAPSED_TIME >= DELTA_FPS_LIMIT)
				{
					GRAPHIC->REFRESH_SCREEN(GRAPHIC);
					QueryPerformanceCounter(&START);
					GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);
				}
			}
		}
		else
		{
			while (PeekMessage(&EVENT_MSG, ((void *)0), 0, 0, PM_REMOVE) || 1)
			{
				LARGE_INTEGER	END;
				register double	ELAPSED_TIME;

				if (EVENT_MSG.message == WM_QUIT)
					return (1);

				TranslateMessage(&EVENT_MSG);
				DispatchMessage(&EVENT_MSG);

				QueryPerformanceCounter(&END);
				ELAPSED_TIME = (double)(
					(double)(
						END.QuadPart - START.QuadPart
					) / FREQUENCY.QuadPart
				);

				if (ELAPSED_TIME >= DELTA_FPS_LIMIT)
				{
					if (GRAPHIC->WINDOW_HANDLE)
					{
						InvalidateRect(GRAPHIC->WINDOW_HANDLE, ((void *)0), 0);
						UpdateWindow(GRAPHIC->WINDOW_HANDLE);
					}

					QueryPerformanceCounter(&START);
					GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);
				}
			}
		}
	}
	else
	{
		if (GRAPHIC->WINDOW_STYLE.TRANSPARENCY)
		{
			while (PeekMessage(&EVENT_MSG, ((void *)0), 0, 0, PM_REMOVE) || 1)
			{
				LARGE_INTEGER	END;
				register double	ELAPSED_TIME;

				if (EVENT_MSG.message == WM_QUIT)
					return (1);

				TranslateMessage(&EVENT_MSG);
				DispatchMessage(&EVENT_MSG);

				QueryPerformanceCounter(&END);
				ELAPSED_TIME = (double)(
					(double)(
						END.QuadPart - START.QuadPart
					) / FREQUENCY.QuadPart
				);

				if (ELAPSED_TIME >= DELTA_FPS_LIMIT)
				{
					GRAPHIC->REFRESH_SCREEN(GRAPHIC);
					QueryPerformanceCounter(&START);
				}
			}
		}
		else
		{
			while (PeekMessage(&EVENT_MSG, ((void *)0), 0, 0, PM_REMOVE) || 1)
			{
				LARGE_INTEGER	END;
				register double	ELAPSED_TIME;

				if (EVENT_MSG.message == WM_QUIT)
					return (1);

				TranslateMessage(&EVENT_MSG);
				DispatchMessage(&EVENT_MSG);

				QueryPerformanceCounter(&END);
				ELAPSED_TIME = (double)(
					(double)(
						END.QuadPart - START.QuadPart
					) / FREQUENCY.QuadPart
				);

				if (ELAPSED_TIME >= DELTA_FPS_LIMIT)
				{
					InvalidateRect(GRAPHIC->WINDOW_HANDLE, ((void *)0), 0);
					UpdateWindow(GRAPHIC->WINDOW_HANDLE);
					QueryPerformanceCounter(&START);
				}
			}
		}
	}

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C */
