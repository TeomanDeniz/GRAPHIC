/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/APP_LOOP__MSDOS     #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef __STDC__ /* STANDARD C */
int
	APP_LOOP(struct S_APP *APP)
#	else /* K&R */
int
	APP_LOOP(APP)

	struct S_APP	*APP;
#	endif /* __STDC__ */
{
	IGNORE_VAR	APP; // TODO: USE GRAPHIC

	return (0);
}

/* TODO: GET KEYBOARD INPUT
#include <conio.h>

	if (kbhit())
		int ch = getch();
*/

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C */
