/******************************************************************************\
# C - APP_SETUP                                  #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/05/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../LIBCGFX.h" /*
# struct APP;
#    int SET_TITLE(struct S_APP *, char *);
#   long APP_TIME(void);
#        */
#include "../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
#include <string.h> /*
#   void *memset(void *, int, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#ifndef KNR_STYLE /* STANDARD C */
void
	APP_SETUP(struct S_APP *const APP)
#else /* K&R */
void
	APP_SETUP(APP)
	struct S_APP	*APP;
#endif /* !KNR_STYLE */
{
	if (!APP)
		return ;

	memset(APP, 0, sizeof(struct S_APP));
	SET_TITLE(APP, ((void *)0));
	APP->FPS_START_TIME = APP_TIME();
	APP->FPS = 60;
	APP->WINDOW.BORDER = 1;
	APP->WINDOW.TRANSPARENCY = 0;
	APP->WINDOW.RESIZABLE = 1;
	APP->WINDOW.MINIMIZABLE = 1;
	APP->WINDOW.MAXIMIZABLE = 1;
	APP->WINDOW.CLOSEBUTTON = 1;
	APP->WINDOW.FOCUSABLE = 1;
	APP->WINDOW.TOPMOST = 0;
	APP->WINDOW.TOOLWINDOW = 0;
	APP->WINDOW.HIDEONCREATE = 0;
	APP->WINDOW.CLIENTEDGE = 0;
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* STANDARD C */
void
	app_setup(struct s_app *const app)
#else /* K&R */
void
	app_setup(app)
	struct s_app	*app;
#endif /* !KNR_STYLE */
{
	APP_SETUP((struct S_APP *)app);
}
/* ***************************** [^] LOWERCASE [^] ************************** */
