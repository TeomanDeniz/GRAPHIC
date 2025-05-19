/******************************************************************************\
# C - EVENT_HOOK_CLOSE                           #       Maximum Tension       #
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
	EVENT_HOOK_CLOSE(struct S_APP *const APP, int (*F)(void *), void *ARG)
#else /* K&R */
void
	EVENT_HOOK_CLOSE(APP, F, ARG)
	struct S_APP	*APP;
	int	(*F)(void *);
	void			*ARG;
#endif /* !KNR_STYLE */
{
	APP->FUNCTION_CLOSE = F;
	APP->FUNCTION_CLOSE_ARG = ARG;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* STANDARD C */
void
	event_hook_close(struct s_app *const app, int (*f)(void *), void *arg)
#else /* K&R */
void
	event_hook_close(app, f, arg)
	struct s_app	*app;
	int	(*f)(void *);
	void			*arg;
#endif /* !KNR_STYLE */
{
	app->FUNCTION_CLOSE = f;
	app->FUNCTION_CLOSE_ARG = arg;
}
/* ***************************** [^] LOWERCASE [^] ************************** */
