/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_TITLE_WINDOWS    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/06/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_TITLE_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <winuser.h> /*
#	 define SetWindowText
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, char *TITLE)
{
	static char (CURRENT_TITLE)[1024];
	register int   (TITLE_SIZE);

	if (!GRAPHIC)
		return (-1);

	if (!TITLE || !*TITLE)
	{
		CURRENT_TITLE[0] = ' ';
		CURRENT_TITLE[1] = 0;
	}
	else
	{
		TITLE_SIZE = -1;

		while (++TITLE_SIZE, TITLE[TITLE_SIZE] && TITLE_SIZE < 1023)
			CURRENT_TITLE[TITLE_SIZE] = TITLE[TITLE_SIZE];

		CURRENT_TITLE[TITLE_SIZE] = 0;
	}

	GRAPHIC->TITLE = CURRENT_TITLE;
	
	if (!!GRAPHIC->WINDOW_HANDLE)
		SetWindowText(GRAPHIC->WINDOW_HANDLE, GRAPHIC->TITLE);

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_TITLE_C */
