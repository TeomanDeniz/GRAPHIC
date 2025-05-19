/******************************************************************************\
# H - APP_SLEEP__MSDOS                           #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_SLEEP_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../LIBCMT/ATTRIBUTES/REGPARM.h" /*
#	 define REGPARM()
#	        */
#	include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include <dos.h> /*
#	   void delay(uint);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifndef KNR_STYLE /* STANDARD C */
void REGPARM(1)
	APP_SLEEP(register long MILLISECONDS)
#	else /* K&R */
void REGPARM(1)
	APP_SLEEP(MILLISECONDS)

	register long	MILLISECONDS;
#	endif /* !KNR_STYLE */
void REGPARM(1)
	GRAPHIC_SLEEP(register long MILLISECONDS)
{
	delay((unsigned int)MILLISECONDS);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_SLEEP_C */
