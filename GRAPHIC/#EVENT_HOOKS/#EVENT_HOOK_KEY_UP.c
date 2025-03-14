/******************************************************************************\
# H - GRAPHIC/#EVENT_HOOKS/#KEY_UP               #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/23 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/03/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../#STRUCT.h" /*
# struct GRAPHIC;
# struct graphic;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#ifdef __STDC__ /* STANDARD C */
void
	EVENT_HOOK_KEY_UP(
	struct GRAPHIC *const GRAPHIC,
	int (*F)(unsigned int, void *),
	void *ARG
)
#else /* K&R */
void
	EVENT_HOOK_KEY_UP(GRAPHIC, F, ARG)
	struct GRAPHIC	*GRAPHIC;
	int	(*F)(unsigned int, void *);
	void			*ARG;
#endif /* __STDC__ */
{
	GRAPHIC->FUNCTION_KEY_UP = F;
	GRAPHIC->FUNCTION_KEY_UP_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifdef __STDC__ /* STANDARD C */
void
	event_hook_key_up(
	struct graphic *const graphic,
	int (*f)(unsigned int, void *),
	void *arg
)
#else /* K&R */
void
	event_hook_key_up(graphic, f, arg)
	struct graphic	*graphic;
	int	(*f)(unsigned int, void *);
	void			*arg;
#endif /* __STDC__ */
{
	graphic->FUNCTION_KEY_UP = f;
	graphic->FUNCTION_KEY_UP_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
