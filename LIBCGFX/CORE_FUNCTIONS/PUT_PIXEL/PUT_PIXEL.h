/******************************************************************************\
# H - PUT_PIXEL                                  #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/05/19 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/05/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_PUT_PIXEL_H /* SEALER */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../STRUCTURES.h" /*
# struct S_APP;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#ifdef __OPENGL__
#	include "PUT_PIXEL__OPENGL.h"
#else /* DOS */
#	ifdef __DJGPP__
#		include "PUT_PIXEL__MSDOS.h"
#	else /* BITMAP */
#		include "PUT_PIXEL__BITMAP.h"
#	endif /* __DJGPP__ */
#endif /* __OPENGL__ */

/* ***************************** [V] LOWERCASE [V] ************************** */
#define put_pixel(\
	__put_pixel_graphic__, \
	__put_pixel_x__, \
	__put_pixel_y__, \
	__put_pixel_color__\
) \
	PUT_PIXEL(\
		((struct S_APP *)__put_pixel_graphic__), \
		__put_pixel_x__, \
		__put_pixel_y__, \
		__put_pixel_color__\
	)
/* ***************************** [^] LOWERCASE [^] ************************** */
