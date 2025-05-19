/******************************************************************************\
# C - SET_CURSOR_POSITION                        #       Maximum Tension       #
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

#define LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_POSITION_C /* SEALER */

#ifdef __APPLE__
#	include "SET_CURSOR_POSITION__MACOS.h"
#else
#	ifdef _WIN32
#		include "SET_CURSOR_POSITION__WINDOWS.h"
#	else /* DOS */
#		ifdef __DJGPP__
#			include "SET_CURSOR_POSITION__MSDOS.h"
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__unix__))
#				include "SET_CURSOR_POSITION__X11.h"
#			endif /* UNIX */
#		endif /* __DJGPP__ */
#	endif /* _WIN32 */
#endif /* __APPLE__ */
				
/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* STANDARD C */
void
	set_cursor_position(struct s_app *const app, const int x, const int y)
#else /* K&R */
void
	set_cursor_position(app, x, y)

	struct s_app	*app;
	int				x;
	int				y;
#endif /* !KNR_STYLE */
{
	SET_CURSOR_POSITION((struct S_APP *)app, x, y);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
