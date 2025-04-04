/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/SET_TITLE__MSDOS    #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include "../../../LIBCMT/KEYWORDS/IGNORE.h" /*
#	 define IGNORE_VAR
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef __STDC__ /* STANDARD C */
int
	SET_TITLE(struct S_APP *const APP, const char *const TITLE)
#	else /* K&R */
int
	SET_TITLE(APP, TITLE)

	struct S_APP	*APP;
	char			*TITLE;
#	endif /* __STDC__ */
{
	IGNORE_VAR	APP;
	IGNORE_VAR	TITLE;

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C */
