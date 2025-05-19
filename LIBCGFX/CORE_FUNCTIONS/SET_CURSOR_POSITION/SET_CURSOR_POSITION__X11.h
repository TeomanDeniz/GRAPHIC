/******************************************************************************\
# H - SET_CURSOR_POSITION__X11                   #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_POSITION_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <X11/Xlib.h> /*
#	typedef Window;
#	    int XWarpPointer(Display *, Window, Window, int, int, uint, uint, int,
>	        	int);
#	    int XFlush(Display *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	SET_CURSOR_POSITION(struct S_APP *const APP, const int X, const int Y)
{
	XWarpPointer(APP->DISPLAY, (Window)0, APP->WINDOW, 0, 0, 0, 0, X, Y);
	XFlush(APP->DISPLAY);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_POSITION_C */
