/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/SET_TITLE__MACOS    #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	typedef id;
#	        */
#	include <objc/objc-runtime.h> /*
#	typedef *SEL;
#	    SEL sel_getUid(const char *);
#	  Class objc_getClass(const char *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] HELPER MACROS [v] ************************** */
#	ifndef OBJC1
#		define OBJC1(\
			__OBJC1_ROUGHNESS__, \
			__OBJC1_OPTION__, \
			__OBJC1_SIZE__, \
			__OBJC1_A__, \
			__OBJC1_a__\
		) (\
			(\
				__OBJC1_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__OBJC1_A__\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC1_OPTION__, \
			sel_getUid(__OBJC1_SIZE__), \
			__OBJC1_a__\
		)
#	endif /* !OBJC1 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* !REFRESH_SCREEN */
/* ************************* [^] HELPER MACROS [^] ************************** */

int
	SET_TITLE(struct S_APP *const APP, const char *const TITLE)
{
	id				TITLE_ID;
	static char		CURRENT_TITLE[1024];

	if (!APP)
		return (-1);

	if (!TITLE || !*TITLE)
	{
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

	if (!!APP->WINDOW_MODULE)
	{
		TITLE_ID = OBJC1(id,
			REFRESH_SCREEN("NSString"),
			"stringWithUTF8String:",
			char *,
			APP->WINDOW.TITLE
		);
		OBJC1(void, APP->WINDOW_MODULE, "setTitle:", id, TITLE_ID);
	}

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_SET_TITLE_C */
