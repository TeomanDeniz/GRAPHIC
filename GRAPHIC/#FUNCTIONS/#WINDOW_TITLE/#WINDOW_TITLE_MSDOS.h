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
# : License - AGPL-3.0  :: Update - 2024/05/20 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_TITLE_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include "../../CMT/KEYWORDS/UNUSED.h" /*
#	 define UNUSED
#	 define NOPE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	ifdef __STDC__ /* STANDARD C */
UNUSED int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, char *TITLE)
#	else /* K&R */
UNUSED int
	WINDOW_TITLE(GRAPHIC, TITLE)

	struct GRAPHIC *(GRAPHIC);
	char             *(TITLE);
#	endif /* __STDC__ */
{
	NOPE GRAPHIC;
	NOPE TITLE;

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_TITLE_H */
