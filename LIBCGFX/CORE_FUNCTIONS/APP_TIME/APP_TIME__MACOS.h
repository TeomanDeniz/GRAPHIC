/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/APP_TIME__MACOS     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_TIME_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include <time.h> /*
#	 define CLOCK_REALTIME
#	 struct timespec;
#	    int clock_gettime(clockid_t, struct timespec *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

long
	APP_TIME(void)
{
	struct timespec	TIME;

	clock_gettime(CLOCK_REALTIME, &TIME);
	return (TIME.tv_sec * 1000L + (TIME.tv_nsec / 1000000L));
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_TIME_C */
