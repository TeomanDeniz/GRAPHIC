/******************************************************************************\
# H - SET_CURSOR__MACOS                          #       Maximum Tension       #
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
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	typedef id;
#	        */
#	include <objc/objc-runtime.h> /*
#	typedef *SEL;
#	    SEL sel_getUid(const char *);
#	  Class objc_getClass(const char *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] HELPER MACROS [v] ************************** */
#	ifndef OBJC
#		define OBJC(\
			__OBJC_ROUGHNESS__, \
			__OBJC_OPTION__, \
			__OBJC_SIZE__\
		) (\
			(\
				__OBJC_ROUGHNESS__(*)\
				(\
					id, \
					SEL\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC_OPTION__, \
			sel_getUid(__OBJC_SIZE__)\
		)
#	endif /* !OBJC */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* !REFRESH_SCREEN */
/* ************************* [^] HELPER MACROS [^] ************************** */

void
	SET_CURSOR(struct S_APP *const APP, const unsigned char CURSOR_TYPE)
{
	IGNORE_VAR	APP;

	id	CURSOR_ID;
	id	CURSOR;

	APP->MOUSE.CURSOR = CURSOR_TYPE;

	switch (CURSOR_TYPE)
	{
		case (CURSOR_NONE):
		{
			CURSOR = OBJC(id, (id)objc_getClass("NSCursor"), "hide");
		}
		return ;
		case (CURSOR_CONTEXT_MENU):
		case (CURSOR_CELL):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "crosshairCursor");
		}
		break ;
		case (CURSOR_VERTICAL_TEXT):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "IBeamCursor");
		}
		break ;
		case (CURSOR_ALIAS):
		case (CURSOR_COPY):
		case (CURSOR_NO_DROP):
		case (CURSOR_NOT_ALLOWED):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "operationNotAllowedCursor");
		}
		break ;
		case (CURSOR_EW_RESIZE):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "resizeLeftRightCursor");
		}
		break ;
		case (CURSOR_NS_RESIZE):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "resizeUpDownCursor");
		}
		break ;
		case (CURSOR_NESW_RESIZE):
		case (CURSOR_NWSE_RESIZE):
		case (CURSOR_COL_RESIZE):
		case (CURSOR_ROW_RESIZE):
		case (CURSOR_ALL_SCROLL):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "openHandCursor");
		}
		break ;
		case (CURSOR_GRAB):
		case (CURSOR_GRABBING):
		case (CURSOR_ZOOM_IN):
		case (CURSOR_ZOOM_OUT):
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "pointingHandCursor");
		}
		break ;
		default:
		{
			CURSOR_ID = (id)objc_getClass("NSCursor");
			CURSOR = OBJC(id, CURSOR_ID, "arrowCursor");
		}
	}

	OBJC(void, CURSOR, "set");
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_C */
