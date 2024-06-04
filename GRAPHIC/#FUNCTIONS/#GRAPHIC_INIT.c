/******************************************************************************\
# C - GRAPHIC/#FUNCIONS/#GRAPHIC_INIT            #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/23 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/05/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../GRAPHIC.h" /*
#	 struct GRAPHIC;
#	   void GRAPHIC_SETUP(struct GRAPHIC *);
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*GRAPHIC_INIT(void)
{
	struct GRAPHIC	*GRAPHIC;

	GRAPHIC = (struct GRAPHIC *)malloc(sizeof(struct GRAPHIC));

	if (!GRAPHIC)
		return ((void *)0);

	GRAPHIC_SETUP(GRAPHIC);
	return ((void *)GRAPHIC);
}

/* ***************************** [V] LOWERCASE [V] ************************** */
void
	*graphic_init(void)
{
	return (GRAPHIC_INIT());
}
/* ***************************** [^] LOWERCASE [^] ************************** */
