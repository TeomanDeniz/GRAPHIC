/******************************************************************************\
# C - LIBCGFX/CORE_FUNCTIONS/APP_SLEEP           #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/05 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../../LIBCMT/ATTRIBUTES/REGPARM.h" /*
# define REGPARM()
#        */
#include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_SLEEP_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	include "APP_SLEEP__MACOS.h"
#else
#	ifdef _WIN32
#		include "APP_SLEEP__WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "APP_SLEEP__MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__unix__))
#				include "APP_SLEEP__UNIX.h"
#			endif /* UNIX */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
void REGPARM(1)
	app_sleep(register long milliseconds)
#else /* STANDARD C */
void REGPARM(1)
	app_sleep(milliseconds)
	register long	milliseconds;
#endif /* !KNR_STYLE */
{
	APP_SLEEP(milliseconds);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
