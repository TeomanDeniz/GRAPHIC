/******************************************************************************\
# H - SET_TITLE__WINDOWS                         #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <winuser.h> /*
#	 define SetWindowText
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	SET_TITLE(struct S_APP *const APP, const char *const TITLE)
{
	static char	CURRENT_TITLE[1024];
	// WHAT? DON'T BLAME ME. WINDOWS HAS THIS LIMIT.
	// NOT BECAUSE I AM TOO LAZY TO HANDLE MALLOC.

	if (!APP)
		return (-1);

	if (!TITLE || !*TITLE)
	{
		// DIRECTLY SETTING "CURRENT_TITLE[0] = 0" GIVING A SEG ERROR
		CURRENT_TITLE[0] = ' ';
		CURRENT_TITLE[1] = 0;
	}
	else
	{
		register int	TITLE_SIZE;

		TITLE_SIZE = 0;

		while (TITLE[TITLE_SIZE] && TITLE_SIZE < 1023)
		{
			CURRENT_TITLE[TITLE_SIZE] = TITLE[TITLE_SIZE];
			++TITLE_SIZE;
		}

		CURRENT_TITLE[TITLE_SIZE] = 0;
	}

	APP->WINDOW.TITLE = CURRENT_TITLE;
	
	if (!!APP->WINDOW_HANDLE)
		SetWindowText(APP->WINDOW_HANDLE, APP->WINDOW.TITLE);

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C */
