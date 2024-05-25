/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_SLEEP_WINDOWS   #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_SLEEP_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../CMT/ATTRIBUTES/REGPARM.h" /*
#	 define REGPARM()
#	        */
#	include <windows.h> /*
#	   void Sleep(DWORD);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
void REGPARM(1)
	GRAPHIC_SLEEP(register long MILLISECONDS)
{
	Sleep((DWORD)MILLISECONDS);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_SLEEP_H */
