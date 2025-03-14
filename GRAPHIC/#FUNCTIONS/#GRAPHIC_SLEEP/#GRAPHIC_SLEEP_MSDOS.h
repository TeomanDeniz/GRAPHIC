/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_SLEEP_MSDOS     #       Maximum Tension       #
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
#	include <dos.h> /*
#	   void delay(uint);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef __STDC__ /* STANDARD C */
void REGPARM(1)
	GRAPHIC_SLEEP(register long MILLISECONDS)
#	else /* K&R */
void REGPARM(1)
	GRAPHIC_SLEEP(MILLISECONDS)

	register long	MILLISECONDS;
#	endif /* __STDC__ */
void REGPARM(1)
	GRAPHIC_SLEEP(register long MILLISECONDS)
{
	delay((unsigned int)MILLISECONDS);
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_SLEEP_C */
