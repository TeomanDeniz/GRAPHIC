/******************************************************************************\
# H - SET_CURSOR__X11                            #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include "../../CURSORS.h" /*
#	 define CURSOR_NONE
#	 define CURSOR_CONTEXT_MENU
#	 define CURSOR_CELL
#	 define CURSOR_VERTICAL_TEXT
#	 define CURSOR_ALIAS
#	 define CURSOR_COPY
#	 define CURSOR_NO_DROP
#	 define CURSOR_NOT_ALLOWED
#	 define CURSOR_EW_RESIZE
#	 define CURSOR_NS_RESIZE
#	 define CURSOR_NESW_RESIZE
#	 define CURSOR_NWSE_RESIZE
#	 define CURSOR_COL_RESIZE
#	 define CURSOR_ROW_RESIZE
#	 define CURSOR_ALL_SCROLL
#	 define CURSOR_GRAB
#	 define CURSOR_GRABBING
#	 define CURSOR_ZOOM_IN
#	 define CURSOR_ZOOM_OUT
#	        */
#	include <X11/Xlib.h> /*
#	    int XUndefineCursor(Display *, Window);
#	    int XDefineCursor(Display *, Window, Cursor);
#	    int XFlush(Display *);
#	        */
#	include <X11/cursorfont.h> /*
#	 define XC_left_ptr
#	 define XC_tcross
#	 define XC_xterm
#	 define XC_hand2
#	 define XC_pirate
#	 define XC_sb_h_double_arrow
#	 define XC_sb_v_double_arrow
#	 define XC_bottom_left_corner
#	 define XC_bottom_right_corner
#	 define XC_fleur
#	 define XC_fleur
#	 define XC_hand2
#	 define XC_left_ptr
#	 Cursor XCreateFontCursor(Display *, uint);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	SET_CURSOR(struct S_APP *const APP, const unsigned char CURSOR_TYPE)
{
	register unsigned int	CURSOR_ID;

	CURSOR_ID = XC_left_ptr;
	APP->MOUSE.CURSOR = CURSOR_TYPE;

	switch (CURSOR_TYPE)
	{
		case (CURSOR_NONE):
		{
			XUndefineCursor(APP->DISPLAY, APP->WINDOW); 
		}
		return ;
		case (CURSOR_CONTEXT_MENU):
		case (CURSOR_CELL):
		{
			CURSOR_ID = XC_tcross;
		}
		break ;
		case (CURSOR_VERTICAL_TEXT):
		{
			CURSOR_ID = XC_xterm;
		}
		break ;
		case (CURSOR_ALIAS):
		case (CURSOR_COPY):
		{
			CURSOR_ID = XC_hand2;
		}
		break ;
		case (CURSOR_NO_DROP):
		case (CURSOR_NOT_ALLOWED):
		{
			CURSOR_ID = XC_pirate;
		}
		break ;
		case (CURSOR_EW_RESIZE):
		{
			CURSOR_ID = XC_sb_h_double_arrow;
		}
		break ;
		case (CURSOR_NS_RESIZE):
		{
			CURSOR_ID = XC_sb_v_double_arrow;
		}
		break ;
		case (CURSOR_NESW_RESIZE):
		{
			CURSOR_ID = XC_bottom_left_corner;
		}
		break ;
		case (CURSOR_NWSE_RESIZE):
		{
			CURSOR_ID = XC_bottom_right_corner;
		}
		break ;
		case (CURSOR_COL_RESIZE):
		case (CURSOR_ROW_RESIZE):
		{
			CURSOR_ID = XC_fleur;
		}
		break ;
		case (CURSOR_ALL_SCROLL):
		{
			CURSOR_ID = XC_fleur;
		}
		break ;
		case (CURSOR_GRAB):
		case (CURSOR_GRABBING):
		case (CURSOR_ZOOM_IN):
		case (CURSOR_ZOOM_OUT):
		{
			CURSOR_ID = XC_hand2;
		}
		break ;
		default:
		{
			CURSOR_ID = XC_left_ptr;
		}
	}

	XDefineCursor(
		APP->DISPLAY,
		APP->WINDOW,
		XCreateFontCursor(APP->DISPLAY, CURSOR_ID)
	);
	XFlush(APP->DISPLAY);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_C */
