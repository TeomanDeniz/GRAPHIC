/******************************************************************************\
# H - GRAPHIC/#EVENT_HOOKS/#CLOSE                #       Maximum Tension       #
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

#ifndef EVENT_HOOK_CLOSE_H
#	define EVENT_HOOK_CLOSE_H 202405
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../#STRUCT.h" /*
#	 struct GRAPHIC;
#	 struct graphic;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
void
	EVENT_HOOK_CLOSE(struct GRAPHIC *GRAPHIC, int (*F)(void *), void *ARG)
{
	GRAPHIC->FUNCTION_CLOSE = F;
	GRAPHIC->FUNCTION_CLOSE_ARG = ARG;
}
/* ***************************** [V] LOWERCASE [V] ************************** */
void
	event_hook_close(struct graphic *GRAPHIC, int (*F)(void *), void *ARG)
{
	GRAPHIC->FUNCTION_CLOSE = F;
	GRAPHIC->FUNCTION_CLOSE_ARG = ARG;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
#endif /* EVENT_HOOK_CLOSE_H */
