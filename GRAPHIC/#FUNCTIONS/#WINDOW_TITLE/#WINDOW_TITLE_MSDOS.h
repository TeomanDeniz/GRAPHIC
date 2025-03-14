/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_TITLE_MSDOS      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/03/12 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_TITLE_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include "../../LIBCMT/KEYWORDS/UNUSED.h" /*
#	 define UNUSED
#	        */
#	include "../../LIBCMT/KEYWORDS/IGNORE.h" /*
#	 define IGNORE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef __STDC__ /* STANDARD C */
UNUSED int
	WINDOW_TITLE(struct GRAPHIC *const GRAPHIC, const char *const TITLE)
#	else /* K&R */
UNUSED int
	WINDOW_TITLE(GRAPHIC, TITLE)

	struct GRAPHIC	*GRAPHIC;
	char			*TITLE;
#	endif /* __STDC__ */
{
	IGNORE	GRAPHIC;
	IGNORE	TITLE;

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_TITLE_C */
