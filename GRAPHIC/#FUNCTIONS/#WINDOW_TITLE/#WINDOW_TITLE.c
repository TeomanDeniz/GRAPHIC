/******************************************************************************\
# C - GRAPHIC/#FUNCIONS/#WINDOW_TITLE            #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/03/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../#STRUCT.h" /*
# struct graphic;
# struct GRAPHIC;
#        */
#include "../../LIBCMT/KEYWORDS/UNUSED.h" /*
# define UNUSED
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define GRAPHIC_FUNCTIONS__WINDOW_TITLE_C /* SEALER */

#ifdef __APPLE__
#	include "#WINDOW_TITLE_MACOS.h"
#else
#	ifdef _WIN32
#		include "#WINDOW_TITLE_WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "#WINDOW_TITLE_MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__gnu_linux__) || \
				defined(__FreeBSD__) || defined(__NetBSD__) || \
				defined(__OpenBSD__) || defined(__DragonFly__) || \
				defined(__sun) || defined(X11))
#				include "#WINDOW_TITLE_UNIX.h"
#			endif /* UNIX */
#		endif /* DJGPP (DOS) */
#	endif /* WINDOWS */
#endif /* APPLE */
				
/* ***************************** [V] LOWERCASE [V] ************************** */
#	ifdef __STDC__ /* STANDARD C */
UNUSED int
	window_title(struct graphic *const graphic, char *const title)
#	else /* K&R */
UNUSED int
	window_title(graphic, title)

	struct graphic	*graphic;
	char			*title;
#	endif /* __STDC__ */
{
	return (WINDOW_TITLE((struct GRAPHIC *)graphic, title));
}
/* ***************************** [^] LOWERCASE [^] ************************** */
