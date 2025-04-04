/******************************************************************************\
# C - LIBCGFX/CORE_FUNCTIONS/SET_TITLE           #       Maximum Tension       #
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
#include "../../STRUCTURES.h" /*
# struct s_app;
# struct S_APP;
#        */
#include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C /* SEALER */

#ifdef __APPLE__
#	include "SET_TITLE__MACOS.h"
#else
#	ifdef _WIN32
#		include "SET_TITLE__WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "SET_TITLE__MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			ifdef X11
#				include "SET_TITLE__X11.h"
#			endif /* X11 */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */
				
/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
int
	set_title(struct s_app *const app, char *const title)
#else /* STANDARD C */
int
	set_title(app, title)

	struct s_app	*app;
	char			*title;
#endif /* !KNR_STYLE */
{
	return (SET_TITLE((struct S_APP *)app, title));
}
/* ***************************** [^] LOWERCASE [^] ************************** */
