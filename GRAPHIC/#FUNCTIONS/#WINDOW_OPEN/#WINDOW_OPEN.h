/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_OPEN             #       Maximum Tension       #
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

#ifndef GRAPHIC_FUNCTIONS__WINDOW_OPEN_H
#	define GRAPHIC_FUNCTIONS__WINDOW_OPEN_H 202405
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	if (defined(__APPLE__) && !defined(X11))
#		include "#WINDOW_OPEN_MACOS.h"
#	else
#		ifdef _WIN32
#			include "#WINDOW_OPEN_WINDOWS.h"
#		else /* DOS */
#			ifdef __DJGPP__
#				include "#WINDOW_OPEN_MSDOS.h"
#			else /* UNIX (PROBABLY) */
#				if (defined(__linux__) || defined(__gnu_linux__) || \
					defined(__FreeBSD__) || defined(__NetBSD__) || \
					defined(__OpenBSD__) || defined(__DragonFly__) || \
					defined(__sun) || defined(X11))
#					include "#WINDOW_OPEN_UNIX.h"
#				endif /* UNIX */
#			endif /* DJGPP (DOS) */
#		endif /* WINDOWS */
#	endif /* APPLE */
/* ***************************** [V] LOWERCASE [V] ************************** */
#	define window_open(\
		__window_open_graphic__, \
		__window_open_width__, \
		__window_open_height__\
	) \
		WINDOW_OPEN(\
			(struct GRAPHIC *)__window_open_graphic__, \
			__window_open_width__, \
			__window_open_height__\
	)
/* ***************************** [^] LOWERCASE [^] ************************** */
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_H */
