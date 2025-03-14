/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_TITLE_UNIX       #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_TITLE_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <X11/Xlib.h> /*
#	    int XStoreName(Display *, Window, char *);
#	    int XSync(Display *, Bool);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	WINDOW_TITLE(struct GRAPHIC *const GRAPHIC, const char *const TITLE)
{
	static char	CURRENT_TITLE[1024];
	// OK I AM LIED. I AM TOO LAZY TO HANDLE MALLOCS.
	// WHAT? WHAT YOU GONNA DO ABOUT IT? OPEN AN ISSUE?

	if (!GRAPHIC)
		return (-1);

	if (!TITLE || !*TITLE)
	{
		CURRENT_TITLE[0] = ' ';
		CURRENT_TITLE[1] = 0;
	}
	else
	{
		register int	TITLE_SIZE;

		TITLE_SIZE = 0;

		while (TITLE[TITLE_SIZE] && TITLE_SIZE < 1023)
		{
			CURRENT_TITLE[TITLE_SIZE] = TITLE[TITLE_SIZE];
			++TITLE_SIZE;
		}

		CURRENT_TITLE[TITLE_SIZE] = 0;
	}

	GRAPHIC->WINDOW.TITLE = CURRENT_TITLE;
	XStoreName(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, GRAPHIC->WINDOW.TITLE);
	XSync(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_TITLE_C */
