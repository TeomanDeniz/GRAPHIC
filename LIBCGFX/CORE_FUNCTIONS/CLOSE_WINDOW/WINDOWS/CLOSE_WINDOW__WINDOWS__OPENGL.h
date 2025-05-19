/******************************************************************************\
# H - CLOSE_WINDOW__WINDOWS__OPENGL              #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/05/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <winuser.h> /*
#	   BOOL DestroyWindow(HWND);
#	   BOOL KillTimer(HWND, UINT_PTR);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	CLOSE_WINDOW(struct S_APP *const APP)
{
	if (!APP)
		return ;

	if (!!APP->WINDOW_HANDLE)
	{
		KillTimer(APP->WINDOW_HANDLE, 1);
		DestroyWindow(APP->WINDOW_HANDLE);
		APP->WINDOW_HANDLE = ((void *)0);
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C */
