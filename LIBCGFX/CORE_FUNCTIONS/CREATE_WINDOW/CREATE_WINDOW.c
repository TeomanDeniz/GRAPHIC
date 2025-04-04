/******************************************************************************\
# C - LIBCGFX/CORE_FUNCTIONS/CREATE_WINDOW       #       Maximum Tension       #
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

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../STRUCTURES.h" /*
# struct s_app;
# struct S_APP;
#        */
#include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	ifdef __APPLE_OPENGL__
#		include "CREATE_WINDOW__MACOS_OPENGL.h"
#	else /* CORE GRAPHICS */
#		include "CREATE_WINDOW__MACOS.h"
#	endif /* __APPLE_OPENGL__ */
#else
#	ifdef _WIN32
#		include "CREATE_WINDOW__WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "CREATE_WINDOW__MSDOS.h"
#			ifdef X11
#				include "CREATE_WINDOW__X11.h"
#			endif /* X11 */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
int
	create_window(
	struct s_app *app,
	register unsigned int width,
	register unsigned int height
)
#else /* STANDARD C */
int
	create_window(app, width, height)
	struct s_app	*app;
	register int	width;
	register int	height;
#endif /* !KNR_STYLE */
{
	return (CREATE_WINDOW((struct S_APP *)app, width, height));
}
/* ***************************** [^] LOWERCASE [^] ************************** */
