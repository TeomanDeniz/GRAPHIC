/******************************************************************************\
# H - APP_TIME__WINDOWS                          #       Maximum Tension       #
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
#	include <windows.h> /*
#	   BOOL QueryPerformanceFrequency(LARGE_INTEGER *);
#	   BOOL QueryPerformanceCounter(LARGE_INTEGER *);
#	        */
#	include <winnt.h> /*
#	typedef LARGE_INTEGER;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

long
	APP_TIME(void)
{
	LARGE_INTEGER	FREQUENCY;
	LARGE_INTEGER	ECX;

	QueryPerformanceFrequency(&FREQUENCY);
	QueryPerformanceCounter(&ECX);
	return ((long)(ECX.QuadPart * 1000.0 / FREQUENCY.QuadPart));
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_TIME_C */
