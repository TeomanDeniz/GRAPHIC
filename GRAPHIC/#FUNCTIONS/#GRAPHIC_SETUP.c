/******************************************************************************\
# C - GRAPHIC/#FUNCIONS/#GRAPHIC_SETUP           #       Maximum Tension       #
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

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../GRAPHIC.h" /*
#	 struct GRAPHIC;
#	    int WINDOW_TITLE(struct GRAPHIC *, char *);
#	   long GRAPHIC_TIME(void);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef __STDC__ /* STANDARD C */
void
	GRAPHIC_SETUP(struct GRAPHIC *const GRAPHIC)
#	else /* K&R */
void
	GRAPHIC_SETUP(GRAPHIC)
	struct GRAPHIC	*GRAPHIC;
#	endif /* __STDC__ */
{
	register unsigned int	INDEX;
	register unsigned int	SIZEOF;
	char					*GRAPHIC_MEMORY;

	if (!GRAPHIC)
		return ;

	SIZEOF = sizeof(struct GRAPHIC);
	GRAPHIC_MEMORY = (char *)GRAPHIC;
	INDEX = (unsigned int)0;

	while (INDEX < SIZEOF)
	{
		GRAPHIC_MEMORY[INDEX] = 0;
		++INDEX;
	}

	WINDOW_TITLE(GRAPHIC, ((void *)0));
	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();
	GRAPHIC->FPS = 60;
	GRAPHIC->WINDOW_STYLE.BORDER = 1;
	GRAPHIC->WINDOW_STYLE.TRANSPARENCY = 0;
	GRAPHIC->WINDOW_STYLE.RESIZABLE = 1;
	GRAPHIC->WINDOW_STYLE.MINIMIZABLE = 1;
	GRAPHIC->WINDOW_STYLE.MAXIMIZABLE = 1;
	GRAPHIC->WINDOW_STYLE.CLOSEBUTTON = 1;
	GRAPHIC->WINDOW_STYLE.FOCUSABLE = 1;
	GRAPHIC->WINDOW_STYLE.TOPMOST = 0;
	GRAPHIC->WINDOW_STYLE.TOOLWINDOW = 0;
	GRAPHIC->WINDOW_STYLE.HIDEONCREATE = 0;
	GRAPHIC->WINDOW_STYLE.CLIENTEDGE = 0;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#	ifdef __STDC__ /* STANDARD C */
void
	graphic_setup(struct graphic *const graphic)
#	else /* K&R */
void
	graphic_setup(graphic)
	struct graphic	*graphic;
#	endif /* __STDC__ */
{
	GRAPHIC_SETUP((struct GRAPHIC *)graphic);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
