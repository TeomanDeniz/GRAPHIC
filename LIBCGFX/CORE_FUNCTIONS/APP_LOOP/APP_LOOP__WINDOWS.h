/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/APP_LOOP__WINDOWS   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <winuser.h> /*
#	 define GetMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax)
#	 define WM_QUIT
#	 define DispatchMessage(lpMsg)
#	typedef MSG;
#	typedef UINT;
#	   BOOL TranslateMessage(MSG *);
#	   uint *SetTimer(HWND, UINT_PTR, UINT, TIMERPROC);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	APP_LOOP(struct S_APP *APP)
{
	MSG	EVENT_MSG = {0};

	SetTimer(
		APP->WINDOW_HANDLE,
		1,
		(UINT)((1.0 / (double)APP->FPS) * 1000),
		((void *)0)
	);

	while (GetMessage(&EVENT_MSG, ((void *)0), 0, 0))
	{
		if (EVENT_MSG.message == WM_QUIT)
			return (1);

		TranslateMessage(&EVENT_MSG);
		DispatchMessage(&EVENT_MSG);
	}

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C */
