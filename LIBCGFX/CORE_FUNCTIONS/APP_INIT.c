/******************************************************************************\
# C - LIBCGFX/CORE_FUNCTIONS/APP_INIT            #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/23 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../LIBCGFX.h" /*
# struct S_APP;
#   void APP_SETUP(struct S_APP *);
#        */
#include "../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
# define KNR_STYLE
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

#ifndef KNR_STYLE /* K&R */
void
	*APP_INIT(void)
#else /* STANDARD C */
void
	*APP_INIT()
#endif /* !KNR_STYLE */
{
	struct S_APP	*APP;

	APP = (struct S_APP *)malloc(sizeof(struct S_APP));

	if (!APP)
		return ((void *)0);

	APP_SETUP(APP);
	return ((void *)APP);
}

/* ***************************** [V] LOWERCASE [V] ************************** */
#ifndef KNR_STYLE /* K&R */
void
	*app_init(void)
#else /* STANDARD C */
void
	*app_init()
#endif /* !KNR_STYLE */
{
	return (APP_INIT());
}
/* ***************************** [^] LOWERCASE [^] ************************** */
