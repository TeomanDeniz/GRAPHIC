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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_CLOSE_C
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
#	include <CoreGraphics/CoreGraphics.h> /*
#	   void CGColorSpaceRelease(CGColorSpaceRef);
#	   void CGDataProviderRelease(CGDataProviderRef);
#	        */
#	include <pthread.h> /*
#	    int pthread_mutex_lock(pthread_mutex_t *);
#	    int pthread_mutex_unlock(pthread_mutex_t *);
#	    int pthread_mutex_destroy(pthread_mutex_t *);
#	    int pthread_cancel(pthread_t);
#	    int pthread_join(pthread_t, void **);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
extern id const NSApp;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */
/* ************************* [v] HELPER MACROS [v] ************************** */
#	ifndef OBJC
#		define OBJC(\
			__OBJC_ROUGHNESS__, \
			__OBJC_OPTION__, \
			__OBJC_SIZE__\
		) (\
			(\
				__OBJC_ROUGHNESS__(*)\
				(\
					id, \
					SEL\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC_OPTION__, \
			sel_getUid(__OBJC_SIZE__)\
		)
#	endif /* OBJC */
/* ************************* [^] HELPER MACROS [^] ************************** */

void
	WINDOW_CLOSE(struct GRAPHIC *const GRAPHIC)
{
	pthread_mutex_lock(&GRAPHIC->CLOSE_THREAD_MUTEX);
	GRAPHIC->CLOSE_THREAD = 1;
	pthread_mutex_unlock(&GRAPHIC->CLOSE_THREAD_MUTEX);
	pthread_join(GRAPHIC->THREAD_UPDATE_WINDOW, ((void *)0));

	if (!!GRAPHIC->WINDOW_MODULE)
	{
		OBJC(void, GRAPHIC->WINDOW_MODULE, "close");
		OBJC(void, GRAPHIC->WINDOW_MODULE, "release");
		GRAPHIC->WINDOW_MODULE = ((void *)0);
	}

	pthread_join(GRAPHIC->THREAD_UPDATE_WINDOW, ((void *)0));
	pthread_mutex_destroy(&GRAPHIC->CLOSE_THREAD_MUTEX);

	if (!!GRAPHIC->BUFFER)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
	}

	if (!!GRAPHIC->TIMER_ID)
	{
		CFRunLoopTimerInvalidate(GRAPHIC->TIMER_ID);
		OBJC(void, (id)GRAPHIC->TIMER_ID, "release"); // Thx MiniLibX!!!
		GRAPHIC->TIMER_ID = ((void *)0);
	}

	if (!!GRAPHIC->OBSERVER_ID)
	{
		CFRunLoopObserverInvalidate(GRAPHIC->OBSERVER_ID);
		OBJC(void, (id)GRAPHIC->OBSERVER_ID, "release");
		GRAPHIC->OBSERVER_ID = ((void *)0);
	}

	if (!!GRAPHIC->COLOR_SPACE)
	{
		CGColorSpaceRelease(GRAPHIC->COLOR_SPACE);
		GRAPHIC->COLOR_SPACE = ((void *)0);
	}

	if (!!GRAPHIC->IMAGE_PROVIDER)
	{
		CGDataProviderRelease(GRAPHIC->IMAGE_PROVIDER);
		GRAPHIC->IMAGE_PROVIDER = ((void *)0);
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_CLOSE_C */
