/******************************************************************************\
# C - LIBCGFX/EVENT_HOOKS/KEY_DOWN               #       Maximum Tension       #
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
#include "../STRUCTURES.h" /*
# struct S_APP;
# struct s_app;
#        */
#include "../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#ifndef KNR_STYLE /* K&R */
void
	EVENT_HOOK_KEY_DOWN(
	struct S_APP *const APP,
	int (*F)(unsigned int, void *),
	void *ARG
)
#else /* STANDARD C */
void
	EVENT_HOOK_KEY_DOWN(APP, F, ARG)
	struct S_APP	*APP;
	int	(*F)(unsigned int, void *);
	void			*ARG;
#endif /* KNR_STYLE */
{
	APP->FUNCTION_KEY_DOWN = F;
	APP->FUNCTION_KEY_DOWN_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
void
	event_hook_key_down(
	struct s_app *const app,
	int (*f)(unsigned int, void *),
	void *arg
)
#else /* STANDARD C */
void
	event_hook_key_down(app, f, arg)
	struct s_app	*app;
	int	(*f)(unsigned int, void *);
	void			*arg;
#endif /* KNR_STYLE */
{
	app->FUNCTION_KEY_DOWN = f;
	app->FUNCTION_KEY_DOWN_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
