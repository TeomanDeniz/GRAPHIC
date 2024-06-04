/******************************************************************************\
# C - GRAPHIC/#FUNCIONS/#WINDOW_CLOSE            #       Maximum Tension       #
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

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../#STRUCT.h" /*
# struct graphic;
# struct GRAPHIC;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define GRAPHIC_FUNCTIONS__WINDOW_CLOSE_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	include "#WINDOW_CLOSE_MACOS.h"
#else
#	ifdef _WIN32
#		include "#WINDOW_CLOSE_WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "#WINDOW_CLOSE_MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__gnu_linux__) || \
				defined(__FreeBSD__) || defined(__NetBSD__) || \
				defined(__OpenBSD__) || defined(__DragonFly__) || \
				defined(__sun) || defined(X11))
#				include "#WINDOW_CLOSE_UNIX.h"
#			endif /* UNIX */
#		endif /* DJGPP (DOS) */
#	endif /* WINDOWS */
#endif /* APPLE */

/* ***************************** [V] LOWERCASE [V] ************************** */
void
	window_close(struct graphic *graphic)
{
	WINDOW_CLOSE((struct GRAPHIC *)graphic);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
