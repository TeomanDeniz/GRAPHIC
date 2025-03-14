/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_SLEEP_UNIX      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/03/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_SLEEP_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../LIBCMT/ATTRIBUTES/REGPARM.h" /*
#	 define REGPARM()
#	        */
#	include <time.h> /*
#	 struct timespec;
#	    int nanosleep(struct timespec *, struct timespec *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

void REGPARM(1)
	GRAPHIC_SLEEP(register long MILLISECONDS)
{
	struct timespec	TIME_SPECIAL;

	TIME_SPECIAL.tv_sec = MILLISECONDS / 1000L;
	TIME_SPECIAL.tv_nsec = (MILLISECONDS % 1000L) * 1000000L;
	nanosleep(&TIME_SPECIAL, ((void *)0));
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_SLEEP_C */
