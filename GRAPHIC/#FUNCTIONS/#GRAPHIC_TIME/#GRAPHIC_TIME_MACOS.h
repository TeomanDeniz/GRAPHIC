/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_TIME_MACOS      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/05/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_TIME_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include <time.h> /*
#	 define CLOCK_REALTIME
#	 struct timespec;
#	    int clock_gettime(clockid_t, struct timespec *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
long
	GRAPHIC_TIME(void)
{
	struct timespec (TIME);

	clock_gettime(CLOCK_REALTIME, &TIME);
	return (TIME.tv_sec * 1000L + (TIME.tv_nsec / 1000000L));
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_TIME_H */
