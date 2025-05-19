/******************************************************************************\
# H - SET_CURSOR_POSITION__MACOS                 #       Maximum Tension       #
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
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include <CoreGraphics/CoreGraphics.h> /*
#	typedef CGFloat;
#	typedef CGPoint;
#	        */
#	include <ApplicationServices/ApplicationServices.h> /*
#	   void CGWarpMouseCursorPosition(CGPoint);
#	CGError CGAssociateMouseAndMouseCursorPosition(boolean_t);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	SET_CURSOR_POSITION(struct S_APP *const APP, const int X, const int Y)
{
	IGNORE_VAR	APP;

	CGPoint	POINT;

	POINT.x = (CGFloat)X;
	POINT.y = (CGFloat)Y;
	CGWarpMouseCursorPosition(POINT);
	CGAssociateMouseAndMouseCursorPosition(1);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_POSITION_C */
