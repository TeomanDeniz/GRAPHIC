/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_TITLE_MACOS      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/06/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_TITLE_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
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
#	ifndef MSG1
#		define MSG1(\
			__MSG1_ROUGHNESS__, \
			__MSG1_OPTION__, \
			__MSG1_SIZE__, \
			__MSG1_A__, \
			__MSG1_a__\
		) (\
			(\
				__MSG1_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG1_A__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG1_OPTION__, \
			sel_getUid(__MSG1_SIZE__), \
			__MSG1_a__\
		)
#	endif /* MSG1 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* REFRESH_SCREEN */
/* ************************* [^] HELPER MACROS [^] ************************** */
int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, char *TITLE)
{
	id               (TITLE_ID);
	static char (CURRENT_TITLE)[1024];
	register int   (TITLE_SIZE);

	if (!GRAPHIC)
		return (-1);

	if (!TITLE || !*TITLE)
	{
		CURRENT_TITLE[0] = ' ';
		CURRENT_TITLE[1] = 0;
	}
	else
	{
		TITLE_SIZE = -1;

		while (++TITLE_SIZE, TITLE[TITLE_SIZE] && TITLE_SIZE < 1023)
			CURRENT_TITLE[TITLE_SIZE] = TITLE[TITLE_SIZE];

		CURRENT_TITLE[TITLE_SIZE] = 0;
	}

	GRAPHIC->TITLE = CURRENT_TITLE;

	if (!!GRAPHIC->WINDOW_MODULE)
	{
		TITLE_ID = MSG1(id, \
			REFRESH_SCREEN("NSString"), \
			"stringWithUTF8String:", \
			char *, \
			GRAPHIC->TITLE\
		);
		MSG1(void, GRAPHIC->WINDOW_MODULE, "setTitle:", id, TITLE_ID);
	}

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_TITLE_C */
