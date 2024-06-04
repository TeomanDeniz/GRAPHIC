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

void
	GRAPHIC_SETUP(struct GRAPHIC *GRAPHIC)
{
	register unsigned int  (INDEX);
	register unsigned int (SIZEOF);
	char         *(GRAPHIC_MEMORY);

	if (!GRAPHIC)
		return ;

	SIZEOF = sizeof(struct GRAPHIC);
	GRAPHIC_MEMORY = (char *)GRAPHIC;
	INDEX = (unsigned int)-1;

	while (++INDEX, INDEX < SIZEOF)
		GRAPHIC_MEMORY[INDEX] = 0;

	WINDOW_TITLE(GRAPHIC, ((void *)0));
	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();
}

/* ***************************** [V] LOWERCASE [V] ************************** */
void
	graphic_setup(struct graphic *graphic)
{
	GRAPHIC_SETUP((struct GRAPHIC *)graphic);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
