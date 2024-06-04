/******************************************************************************\
# H - GRAPHIC/#EVENT_HOOKS/#MOUSE                #       Maximum Tension       #
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
#	include "../#STRUCT.h" /*
#	 struct GRAPHIC;
#	 struct graphic;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	EVENT_HOOK_MOUSE(struct GRAPHIC *GRAPHIC, \
int (*F)(unsigned int, unsigned int, unsigned char, void *), void *ARG)
{
	GRAPHIC->FUNCTION_MOUSE = F;
	GRAPHIC->FUNCTION_MOUSE_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
void
	event_hook_mouse(struct graphic *graphic, \
int (*f)(unsigned int, unsigned int, unsigned char, void *), void *arg)
{
	graphic->FUNCTION_MOUSE = f;
	graphic->FUNCTION_MOUSE_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
