/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_CLOSE_WINDOWS    #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_CLOSE_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
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
	WINDOW_CLOSE(struct GRAPHIC *const GRAPHIC)
{
	if (!GRAPHIC)
		return ;

	if (!!GRAPHIC->WINDOW_HANDLE)
	{
		KillTimer(GRAPHIC->WINDOW_HANDLE, 1);
		DestroyWindow(GRAPHIC->WINDOW_HANDLE);
		GRAPHIC->WINDOW_HANDLE = ((void *)0);
	}

	if (!!GRAPHIC->BUFFER)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_CLOSE_C */
