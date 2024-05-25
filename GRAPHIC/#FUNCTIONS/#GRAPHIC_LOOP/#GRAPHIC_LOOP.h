/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP            #       Maximum Tension       #
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

#ifndef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H
#	define GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H 202405
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	ifdef __APPLE__
#		include "#GRAPHIC_LOOP_MACOS.h"
#	else
#		ifdef _WIN32
#			include "#GRAPHIC_LOOP_WINDOWS.h"
#		else /* DOS */
#			ifdef __DJGPP__
#				include "#GRAPHIC_LOOP_MSDOS.h"
#			else /* UNIX (PROBABLY) */
#				if (defined(__linux__) || defined(__gnu_linux__) || \
					defined(__FreeBSD__) || defined(__NetBSD__) || \
					defined(__OpenBSD__) || defined(__DragonFly__) || \
					defined(__sun)) /* __sun IS SOLARIS SYSTEMS */
#					include "#GRAPHIC_LOOP_UNIX.h"
#				endif /* UNIX */
#			endif /* DJGPP (DOS) */
#		endif /* WINDOWS */
#	endif /* APPLE */
/* ***************************** [V] LOWERCASE [V] ************************** */
#	define graphic_loop(__graphic_loop_graphic__) \
		GRAPHIC_LOOP((struct GRAPHIC *)__graphic_loop_graphic__)
/* ***************************** [^] LOWERCASE [^] ************************** */
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H */
