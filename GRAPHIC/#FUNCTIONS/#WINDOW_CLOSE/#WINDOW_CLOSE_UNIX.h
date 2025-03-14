/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_CLOSE_UNIX       #       Maximum Tension       #
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
#	include <X11/Xlib.h> /*
#	    int XFreeGC(Display *, GC);
#	    int XCloseDisplay(Display *);
#	    int XDestroyWindow(Display *, Window);
#	        */
#	include <stdlib.h> /*
#	   void free(void *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	WINDOW_CLOSE(struct GRAPHIC *const GRAPHIC)
{
	if (!!GRAPHIC->GRAPHICS_CONTEXT)
	{
		XFreeGC(GRAPHIC->DISPLAY, GRAPHIC->GRAPHICS_CONTEXT);
		GRAPHIC->GRAPHICS_CONTEXT = ((void *)0);
	}

	if (!!GRAPHIC->WINDOW)
	{
		XDestroyWindow(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
		GRAPHIC->WINDOW = ((void *)0);
	}

	if (!!GRAPHIC->DISPLAY)
	{
		XCloseDisplay(GRAPHIC->DISPLAY);
		GRAPHIC->DISPLAY = ((void *)0);
	}

	if (!!GRAPHIC->IMAGE)
	{
		XDestroyImage(GRAPHIC->IMAGE);
		GRAPHIC->IMAGE = ((void *)0);
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
