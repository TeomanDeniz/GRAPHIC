/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_SETUP           #       Maximum Tension       #
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

#ifndef GRAPHIC_FUNCTIONS__GRAPHIC_SETUP_H
#	define GRAPHIC_FUNCTIONS__GRAPHIC_SETUP_H 202405
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
	((char *)&GRAPHIC->KEY)[0] = 0;
	((char *)&GRAPHIC->KEY)[1] = 0;
	((char *)&GRAPHIC->KEY)[2] = 0;
	((char *)&GRAPHIC->KEY)[3] = 0;
	((char *)&GRAPHIC->KEY)[4] = 0;
	((char *)&GRAPHIC->KEY)[5] = 0;
	((char *)&GRAPHIC->KEY)[6] = 0;
	((char *)&GRAPHIC->KEY)[7] = 0;
	((char *)&GRAPHIC->KEY)[8] = 0;
	((char *)&GRAPHIC->KEY)[9] = 0;
	((char *)&GRAPHIC->KEY)[10] = 0;
	((char *)&GRAPHIC->KEY)[11] = 0;
	GRAPHIC->KEY.DOWN = 0;
	GRAPHIC->KEY.UP = 0;
	WINDOW_TITLE(GRAPHIC, ((void *)0));
	*((unsigned char *)&GRAPHIC->MOUSE) = 0;
	GRAPHIC->MOUSE.X = 0;
	GRAPHIC->MOUSE.Y = 0;
	GRAPHIC->MOUSE.VALUE = 0;
	GRAPHIC->MOUSE.WHELL = 0;
	GRAPHIC->MOUSE.HORIZANTAL_WHELL = 0;
	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();
	GRAPHIC->FUNCTION_LOOP = ((void *)0);
	GRAPHIC->FUNCTION_LOOP_ARG = ((void *)0);
	GRAPHIC->FUNCTION_KEY_DOWN = ((void *)0);
	GRAPHIC->FUNCTION_KEY_DOWN_ARG = ((void *)0);
	GRAPHIC->FUNCTION_KEY_UP = ((void *)0);
	GRAPHIC->FUNCTION_KEY_UP_ARG = ((void *)0);
	GRAPHIC->FUNCTION_CLOSE = ((void *)0);
	GRAPHIC->FUNCTION_CLOSE_ARG = ((void *)0);
	GRAPHIC->FUNCTION_MOUSE = ((void *)0);
	GRAPHIC->FUNCTION_MOUSE_ARG = ((void *)0);
}
/* ***************************** [V] LOWERCASE [V] ************************** */
#	define graphic_setup(__graphic_setup_graphic__) \
		GRAPHIC_SETUP((struct GRAPHIC *)__graphic_setup_graphic__)
/* ***************************** [^] LOWERCASE [^] ************************** */
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_SETUP_H */
