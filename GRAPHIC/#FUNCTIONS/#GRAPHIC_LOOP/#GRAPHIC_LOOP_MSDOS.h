/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP_MSDOS      #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	ifdef __STDC__ /* STANDARD C */
int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
#	else /* K&R */
int
	GRAPHIC_LOOP(GRAPHIC)

	struct GRAPHIC *(GRAPHIC);
#	endif /* __STDC__ */
{
	(void)GRAPHIC; // TODO
	return (0);
}
/* TODO
#include <conio.h>

	if (kbhit())
		int ch = getch();
*/
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H */
