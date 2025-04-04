/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/                    #       Maximum Tension       #
# CLOSE_WINDOW__WINDOWS                          #                             #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <winuser.h> /*
#	   BOOL DestroyWindow(HWND);
#	   BOOL KillTimer(HWND, UINT_PTR);
#	        */
#	include <stdlib.h> /*
#	   void free(void *);
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

	if (!!APP->BUFFER)
	{
		free(APP->BUFFER); 
		APP->BUFFER = ((void *)0);
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C */
