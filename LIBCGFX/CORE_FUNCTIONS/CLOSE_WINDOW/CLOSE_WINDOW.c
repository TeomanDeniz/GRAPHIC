/******************************************************************************\
# C - LIBCGFX/CORE_FUNCTIONS/CLOSE_WINDOW        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/06 : #    ::::!!!1!!1!!!1!!!::     #
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

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	ifdef __APPLE_OPENGL__
#		include "CLOSE_WINDOW__MACOS_OPENGL.h"
#	else /* CORE GRAPHICS */
#		include "CLOSE_WINDOW__MACOS.h"
#	endif /* __APPLE_OPENGL__ */
#else
#	ifdef _WIN32
#		include "CLOSE_WINDOW__WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "CLOSE_WINDOW__MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__unix__))
#				include "CLOSE_WINDOW__X11.h"
#			endif /* UNIX */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
void
	close_window(struct s_app *const app)
#else /* STANDARD C */
void
	close_window(app)
	struct s_app	*app;
#endif /* !KNR_STYLE */
{
	CLOSE_WINDOW((struct S_APP *)app);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
