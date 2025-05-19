/******************************************************************************\
# C - APP_LOOP                                   #       Maximum Tension       #
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

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../STRUCTURES.h" /*
# struct s_app;
# struct S_APP;
#        */
#include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	ifdef __APPLE_OPENGL__
#		include "APP_LOOP__MACOS_OPENGL.h"
#	else /* CORE GRAPHICS */
#		include "APP_LOOP__MACOS.h"
#	endif /* __APPLE_OPENGL__ */
#else
#	ifdef _WIN32
#		ifdef __OPENGL__
#			include "WINDOWS/APP_LOOP__WINDOWS__OPENGL.h"
#		else
#			include "WINDOWS/APP_LOOP__WINDOWS__BITMAP.h"
#		endif /* __OPENGL__ */
#	else /* DOS */
#		ifdef __DJGPP__
#			include "APP_LOOP__MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__unix__))
#				include "APP_LOOP__X11.h"
#			endif /* UNIX */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* STANDARD C */
int
	app_loop(struct s_app *app)
#else /* K&R */
int
	app_loop(app)
	struct s_app	*app;
#endif /* !KNR_STYLE */
{
	return (APP_LOOP((struct S_APP *)app));
}
/* ***************************** [^] LOWERCASE [^] ************************** */
