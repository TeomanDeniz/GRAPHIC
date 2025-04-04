/******************************************************************************\
# C - LIBCGFX/EVENT_HOOKS/LOOP                   #       Maximum Tension       #
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
	EVENT_HOOK_LOOP(
	struct S_APP *const APP,
	int (*F)(void *),
	void *ARG
)
#else /* STANDARD C */
void
	EVENT_HOOK_LOOP(APP, F, ARG)
	struct S_APP	*APP;
	int	(*F)(void *);
	void			*ARG;
#endif /* KNR_STYLE */
{
	APP->FUNCTION_LOOP = F;
	APP->FUNCTION_LOOP_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
void
	event_hook_loop(
	struct s_app *const app,
	int (*f)(void *),
	void *arg
)
#else /* STANDARD C */
void
	event_hook_loop(app, f, arg)
	struct s_app	*app;
	int	(*f)(void *);
	void			*arg;
#endif /* KNR_STYLE */
{
	app->FUNCTION_LOOP = f;
	app->FUNCTION_LOOP_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
