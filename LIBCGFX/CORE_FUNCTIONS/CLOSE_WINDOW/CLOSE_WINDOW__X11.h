/******************************************************************************\
# H - CLOSE_WINDOW__X11                          #       Maximum Tension       #
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
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <X11/Xlib.h> /*
#	    int XFreeGC(Display *, GC);
#	    int XCloseDisplay(Display *);
#	    int XDestroyWindow(Display *, Window);
#	        */
#	include <X11/Xutil.h> /*
#	    int XDestroyImage(XImage *);
#	        */
#	include <stdlib.h> /*
#	   void free(void *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	CLOSE_WINDOW(struct S_APP *const APP)
{
	if (!!APP->GRAPHICS_CONTEXT)
	{
		XFreeGC(APP->DISPLAY, APP->GRAPHICS_CONTEXT);
		APP->GRAPHICS_CONTEXT = ((void *)0);
	}

	if (!!APP->XWINDOW)
	{
		XDestroyWindow(APP->DISPLAY, APP->XWINDOW);
		APP->XWINDOW = ((typeof(APP->XWINDOW))0);
	}

	if (!!APP->DISPLAY)
	{
		XCloseDisplay(APP->DISPLAY);
		APP->DISPLAY = ((void *)0);
	}

	if (!!APP->IMAGE)
	{
		XDestroyImage(APP->IMAGE);
		APP->IMAGE = ((void *)0);
		APP->BUFFER = ((void *)0); // YES, XDestroyImage FREES THE BUFFER..
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C */
