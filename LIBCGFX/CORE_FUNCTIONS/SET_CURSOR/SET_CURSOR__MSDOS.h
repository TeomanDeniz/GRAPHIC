/******************************************************************************\
# H - SET_CURSOR__MSDOS                          #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifndef KNR_STYLE /* STANDARD C */
void
	SET_CURSOR(struct S_APP *const APP, const unsigned char CURSOR_TYPE)
#	else /* K&R */
void
	SET_CURSOR(APP, CURSOR_TYPE)

	struct S_APP	*APP;
	char			CURSOR_TYPE;
#	endif /* !KNR_STYLE */
{
	IGNORE_VAR	APP;
	IGNORE_VAR	CURSOR_TYPE;
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_CURSOR_C */
