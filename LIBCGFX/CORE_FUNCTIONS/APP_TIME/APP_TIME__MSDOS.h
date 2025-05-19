/******************************************************************************\
# H - APP_TIME__MSDOS                            #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_TIME_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include <dos.h> /*
#	 struct time;
#	   void gettime(struct time *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifndef KNR_STYLE /* STANDARD C */
long
	APP_TIME(void)
#	else /* K&R */
long
	APP_TIME()
#	endif /* !KNR_STYLE */
{
	struct time	TIME;
	long		RESULT;

	gettime(&TIME);
	RESULT = (long)TIME.ti_hund;
	RESULT += (long)TIME.ti_sec * 100L;
	RESULT += (long)TIME.ti_min * 6000L;
	RESULT += (long)TIME.ti_hour * 360000L;
	return (RESULT);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_TIME_C */
