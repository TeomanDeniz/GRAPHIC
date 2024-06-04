/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_TIME_WINDOWS    #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_TIME_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include <winnt.h> /*
#	typedef LARGE_INTEGER;
#	        */
#	include <windows.h> /*
#	   BOOL QueryPerformanceFrequency(LARGE_INTEGER *);
#	   BOOL QueryPerformanceCounter(LARGE_INTEGER *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
long
	GRAPHIC_TIME(void)
{
	LARGE_INTEGER (FREQUENCY);
	LARGE_INTEGER       (ECX);

	QueryPerformanceFrequency(&FREQUENCY);
	QueryPerformanceCounter(&ECX);
	return ((long)(ECX.QuadPart * 1000.0 / FREQUENCY.QuadPart));
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_TIME_C */
