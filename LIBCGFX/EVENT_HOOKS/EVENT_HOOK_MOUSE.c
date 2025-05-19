/******************************************************************************\
# C - EVENT_HOOK_MOUSE                           #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/23 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/05/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../STRUCTURES.h" /*
# struct S_APP;
# struct s_app;
#        */
#include "../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#ifndef KNR_STYLE /* STANDARD C */
void
	EVENT_HOOK_MOUSE(
	struct S_APP *const APP,
	int (*F)(unsigned int, unsigned int, unsigned char, void *),
	void *ARG
)
#else /* K&R */
void
	EVENT_HOOK_MOUSE(APP, F, ARG)
	struct S_APP	*APP;
	int	(*F)(unsigned int, unsigned int, unsigned char, void *);
	void			*ARG;
#endif /* !KNR_STYLE */
{
	APP->FUNCTION_MOUSE = F;
	APP->FUNCTION_MOUSE_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* STANDARD C */
void
	event_hook_mouse(
	struct s_app *const app,
	int (*f)(unsigned int, unsigned int, unsigned char, void *),
	void *arg
)
#else /* K&R */
void
	event_hook_mouse(app, f, arg)
	struct s_app	*app;
	int	(*f)(unsigned int, unsigned int, unsigned char, void *);
	void			*arg;
#endif /* !KNR_STYLE */
{
	app->FUNCTION_MOUSE = f;
	app->FUNCTION_MOUSE_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
