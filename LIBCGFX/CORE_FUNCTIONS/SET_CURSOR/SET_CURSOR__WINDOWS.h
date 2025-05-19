/******************************************************************************\
# H - SET_CURSOR__WINDOWS                        #       Maximum Tension       #
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
#	include <windef.h> /*
#	typedef LPCSTR;
#	typedef HINSTANCE;
#	        */
#	include <winuser.h> /*
#	 define IDC_CROSS
#	 define IDC_IBEAM
#	 define IDC_HAND
#	 define IDC_NO
#	 define IDC_SIZEWE
#	 define IDC_SIZENS
#	 define IDC_SIZENWSE
#	 define IDC_SIZEALL
#	 define IDC_SIZEALL
#	 define IDC_HAND
#	 define IDC_ARROW
#	 define LoadCursor(hInstance, lpCursorName)
#	HCURSOR SetCursor(HCURSOR);
#	    int ShowCursor(BOOL);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	SET_CURSOR(struct S_APP *const APP, const unsigned char CURSOR_TYPE)
{
	LPCSTR	CURSOR_ID;

	CURSOR_ID = IDC_ARROW;
	APP->MOUSE.CURSOR = CURSOR_TYPE;

	switch (CURSOR_TYPE)
	{
		case (CURSOR_NONE):
		{
			ShowCursor(0);
		}
		return ;
		case (CURSOR_CONTEXT_MENU):
		case (CURSOR_CELL):
		{
			CURSOR_ID = IDC_CROSS;
		}
		break ;
		case (CURSOR_VERTICAL_TEXT):
		{
			CURSOR_ID = IDC_IBEAM;
		}
		break ;
		case (CURSOR_ALIAS):
		case (CURSOR_COPY):
		{
			CURSOR_ID = IDC_HAND;
		}
		break ;
		case (CURSOR_NO_DROP):
		case (CURSOR_NOT_ALLOWED):
		{
			CURSOR_ID = IDC_NO;
		}
		break ;
		case (CURSOR_EW_RESIZE):
		{
			CURSOR_ID = IDC_SIZEWE;
		}
		break ;
		case (CURSOR_NS_RESIZE):
		{
			CURSOR_ID = IDC_SIZENS;
		}
		break ;
		case (CURSOR_NESW_RESIZE):
		case (CURSOR_NWSE_RESIZE):
		{
			CURSOR_ID = IDC_SIZENWSE;
		}
		break ;
		case (CURSOR_COL_RESIZE):
		case (CURSOR_ROW_RESIZE):
		{
			CURSOR_ID = IDC_SIZEALL;
		}
		break ;
		case (CURSOR_ALL_SCROLL):
		{
			CURSOR_ID = IDC_SIZEALL;
		}
		break ;
		case (CURSOR_GRAB):
		case (CURSOR_GRABBING):
		case (CURSOR_ZOOM_IN):
		case (CURSOR_ZOOM_OUT):
		{
			CURSOR_ID = IDC_HAND;
		}
		break ;
		default:
		{
			CURSOR_ID = IDC_ARROW;
		}
	}

	SetCursor(LoadCursor((HINSTANCE)0, CURSOR_ID));
	ShowCursor(1);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_C */
