/******************************************************************************\
# C - GRAPHIC/#FUNCIONS/#GRAPHIC_SLEEP           #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/05/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#define GRAPHIC_FUNCTIONS__GRAPHIC_SLEEP_C /* SEALER */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../LIBCMT/ATTRIBUTES/REGPARM.h" /*
# define REGPARM()
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#if (defined(__APPLE__) && !defined(X11))
#	include "#GRAPHIC_SLEEP_MACOS.h"
#else
#	ifdef _WIN32
#		include "#GRAPHIC_SLEEP_WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "#GRAPHIC_SLEEP_MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__gnu_linux__) || \
				defined(__FreeBSD__) || defined(__NetBSD__) || \
				defined(__OpenBSD__) || defined(__DragonFly__) || \
				defined(__sun) || defined(X11))
#				include "#GRAPHIC_SLEEP_UNIX.h"
#			endif /* UNIX */
#		endif /* DJGPP (DOS) */
#	endif /* WINDOWS */
#endif /* APPLE */

/* ***************************** [V] LOWERCASE [V] ************************** */
#	ifdef __STDC__ /* STANDARD C */
void REGPARM(1)
	graphic_sleep(register long milliseconds)
#	else /* K&R */
void REGPARM(1)
	graphic_sleep(milliseconds)
	register long	milliseconds;
#	endif /* __STDC__ */
{
	GRAPHIC_SLEEP(milliseconds);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
