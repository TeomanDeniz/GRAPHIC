/******************************************************************************\
# C - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP            #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/06/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../#STRUCT.h" /*
# struct graphic;
# struct GRAPHIC;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C /* SEALER */

#if (defined(__APPLE__) && !defined(X11))
#	ifdef __APPLE_OPENGL__
#		include "#GRAPHIC_LOOP_MACOS_OPENGL.h"
#	else /* CORE GRAPHICS */
#		include "#GRAPHIC_LOOP_MACOS.h"
#	endif /* __APPLE_OPENGL__ */
#else
#	ifdef _WIN32
#		include "#GRAPHIC_LOOP_WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "#GRAPHIC_LOOP_MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__gnu_linux__) || \
				defined(__FreeBSD__) || defined(__NetBSD__) || \
				defined(__OpenBSD__) || defined(__DragonFly__) || \
				defined(__sun) || defined(X11))
#				include "#GRAPHIC_LOOP_UNIX.h"
#			endif /* UNIX */
#		endif /* DJGPP (DOS) */
#	endif /* WINDOWS */
#endif /* APPLE */

/* ***************************** [V] LOWERCASE [V] ************************** */
int
	graphic_loop(struct graphic *graphic)
{
	return (GRAPHIC_LOOP((struct GRAPHIC *)graphic));
}
/* ***************************** [^] LOWERCASE [^] ************************** */
