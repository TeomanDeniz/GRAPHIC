/******************************************************************************\
# H - CLOSE_WINDOW__MACOS                        #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C

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
extern id const	NSApp;
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
#	endif /* !OBJC */
/* ************************* [^] HELPER MACROS [^] ************************** */

void
	CLOSE_WINDOW(struct S_APP *const APP)
{
	pthread_mutex_lock(&APP->CLOSE_THREAD_MUTEX);
	APP->CLOSE_THREAD = 1;
	pthread_mutex_unlock(&APP->CLOSE_THREAD_MUTEX);
	pthread_join(APP->THREAD_UPDATE_WINDOW, ((void *)0));

	if (!!APP->WINDOW_MODULE)
	{
		OBJC(void, APP->WINDOW_MODULE, "close");
		OBJC(void, APP->WINDOW_MODULE, "release");
		APP->WINDOW_MODULE = ((void *)0);
	}

	pthread_join(APP->THREAD_UPDATE_WINDOW, ((void *)0));
	pthread_mutex_destroy(&APP->CLOSE_THREAD_MUTEX);

	if (!!APP->BUFFER)
	{
		free(APP->BUFFER);
		APP->BUFFER = ((void *)0);
	}

	if (!!APP->TIMER_ID)
	{
		CFRunLoopTimerInvalidate(APP->TIMER_ID);
		OBJC(void, (id)APP->TIMER_ID, "release"); // Thx MiniLibX!!!
		APP->TIMER_ID = ((void *)0);
	}

	if (!!APP->OBSERVER_ID)
	{
		CFRunLoopObserverInvalidate(APP->OBSERVER_ID);
		OBJC(void, (id)APP->OBSERVER_ID, "release");
		APP->OBSERVER_ID = ((void *)0);
	}

	if (!!APP->COLOR_SPACE)
	{
		CGColorSpaceRelease(APP->COLOR_SPACE);
		APP->COLOR_SPACE = ((void *)0);
	}

	if (!!APP->IMAGE_PROVIDER)
	{
		CGDataProviderRelease(APP->IMAGE_PROVIDER);
		APP->IMAGE_PROVIDER = ((void *)0);
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C */
