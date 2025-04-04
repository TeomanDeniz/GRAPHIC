/******************************************************************************\
# C - LIBCGFX/CORE_FUNCTIONS/APP_TIME            #       Maximum Tension       #
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
#include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_TIME_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	include "APP_TIME__MACOS.h"
#else
#	ifdef _WIN32
#		include "APP_TIME__WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "APP_TIME__MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__gnu_linux__) || \
				defined(__FreeBSD__) || defined(__NetBSD__) || \
				defined(__OpenBSD__) || defined(__DragonFly__) || \
				defined(__sun) || defined(X11))
#				include "APP_TIME__UNIX.h"
#			endif /* UNIX */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
long
	app_time(void)
#else /* STANDARD C */
long
	app_time()
#endif /* !KNR_STYLE */
{
	return (APP_TIME());
}
/* ***************************** [^] LOWERCASE [^] ************************** */
