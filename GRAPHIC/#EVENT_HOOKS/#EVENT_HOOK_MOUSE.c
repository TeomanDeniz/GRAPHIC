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
	EVENT_HOOK_MOUSE(
	struct GRAPHIC *const GRAPHIC,
	int (*F)(unsigned int, unsigned int, unsigned char, void *),
	void *ARG
)
#else /* K&R */
void
	EVENT_HOOK_MOUSE(GRAPHIC, F, ARG)
	struct GRAPHIC	*GRAPHIC;
	int	(*F)(unsigned int, unsigned int, unsigned char, void *);
	void			*ARG;
#endif /* __STDC__ */
{
	GRAPHIC->FUNCTION_MOUSE = F;
	GRAPHIC->FUNCTION_MOUSE_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifdef __STDC__ /* STANDARD C */
void
	event_hook_mouse(
	struct graphic *const graphic,
	int (*f)(unsigned int, unsigned int, unsigned char, void *),
	void *arg
)
#else /* K&R */
void
	event_hook_mouse(graphic, f, arg)
	struct graphic	*graphic;
	int	(*f)(unsigned int, unsigned int, unsigned char, void *);
	void			*arg;
#endif /* __STDC__ */
{
	graphic->FUNCTION_MOUSE = f;
	graphic->FUNCTION_MOUSE_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
