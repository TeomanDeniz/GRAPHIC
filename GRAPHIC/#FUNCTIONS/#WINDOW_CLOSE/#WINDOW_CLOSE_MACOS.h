/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_CLOSE_MACOS      #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_CLOSE_H
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
#	        */
#	include <stdlib.h> /*
#	   void free(void *);
#	        */
#	include <CoreFoundation/CoreFoundation.h> /*
#	   void CFRunLoopTimerInvalidate(CFRunLoopTimerRef);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
extern id const NSApp;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */
/* ************************* [v] HELPER MACROS [v] ************************** */
#	ifndef MSG
#		define MSG(\
			__MSG_ROUGHNESS__, \
			__MSG_OPTION__, \
			__MSG_SIZE__\
		) (\
			(\
				__MSG_ROUGHNESS__(*)\
				(\
					id, \
					SEL\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG_OPTION__, \
			sel_getUid(__MSG_SIZE__)\
		)
#	endif /* MSG */
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
/* ************************* [^] HELPER MACROS [^] ************************** */
void
	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC)
{
	if (!!GRAPHIC->WINDOW_MODULE)
	{
		MSG(void, GRAPHIC->WINDOW_MODULE, "close");
		MSG(void, GRAPHIC->WINDOW_MODULE, "release");
		GRAPHIC->WINDOW_MODULE = ((void *)0);
	}

	if (!!GRAPHIC->BUFFER)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
	}

	if (!!GRAPHIC->TIMER_ID)
	{
		CFRunLoopTimerInvalidate(GRAPHIC->TIMER_ID);
		MSG(void, (id)GRAPHIC->TIMER_ID, "release"); // Thx MiniLibX!!!
		GRAPHIC->TIMER_ID = ((void *)0);
	}

	if (!!GRAPHIC->OBSERVER_ID)
	{
		CFRunLoopObserverInvalidate(GRAPHIC->OBSERVER_ID);
		MSG(void, (id)GRAPHIC->OBSERVER_ID, "release");
		GRAPHIC->OBSERVER_ID = ((void *)0);
	}
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_CLOSE_H */
