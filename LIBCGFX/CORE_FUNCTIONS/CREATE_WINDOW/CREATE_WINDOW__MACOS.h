/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/                    #       Maximum Tension       #
# CREATE_WINDOW__MACOS                           #                             #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../LIBCGFX.h" /*
#	 struct S_APP;
#	   void CLOSE_WINDOW(struct S_APP *);
#	        */
#	include "../../../LIBCMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *, uint);
#	        */
#	include "../../../LIBCMT/KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	   void free(void *);
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	 define NO
#	 define YES
#	typedef BOOL;
#	typedef id;
#	typedef Class;
#	typedef NSInteger;
#	typedef NSUInteger;
#	        */
#	include <objc/objc-runtime.h> /*
#	 define OBJC_ASSOCIATION_ASSIGN
#	typedef *SEL;
#	typedef *IMP;
#	    SEL sel_getUid(const char *);
#	  Class objc_getClass(const char *);
#	  Class objc_allocateClassPair(Class, char *, size_t);
#	   BOOL class_addMethod(Class, SEL, IMP, char *);
#	   void objc_registerClassPair(Class);
#	   void objc_disposeClassPair(Class);
#	   void objc_setAssociatedObject(id, void *, id, objc_AssociationPolicy);
#	     id objc_getAssociatedObject(id, void *);
#	        */
#	include <CoreGraphics/CoreGraphics.h> /*
v	>>>>>>> (CGImageAlphaInfo)
G	^^^^^^^ kCGImageAlphaNoneSkipFirst;
v	>>>>>>> (CGBitmapInfo)
G	^^^^^^^ kCGBitmapByteOrder32Little;
v	>>>>>>> (CGColorRenderingIntent)
G	^^^^^^^ kCGRenderingIntentDefault;
#	typedef CGRect;
#	typedef CGContextRef;
#	typedef CGColorSpaceRef;
#	typedef CGDataProviderRef;
#	typedef CGImageRef;
#	 CGRect CGRectMake(float, float, float, float);
v	>>>>>>> (CGColorSpaceRef)
#	^^^^^^^ CGColorSpaceCreateDeviceRGB(void);
v	>>>>>>> (CGDataProviderRef)
#	^^^^^^^ CGDataProviderCreateWithData(void *, void *, size_t,
>	        CGDataProviderReleaseDataCallback);
v	>>>>>>> (CGImageRef)
#	^^^^^^^ CGImageCreate(size_t, size_t, size_t, size_t, size_t,
>	        CGColorSpaceRef, CGBitmapInfo, CGDataProviderRef, CGFloat *, bool,
>	        CGColorRenderingIntent);
#	   void CGContextDrawImage(CGContextRef, CGRect, CGImageRef);
#	   void CGImageRelease(CGImageRef);
#	        */
#	include <pthread.h> /*
#	    int pthread_mutex_init(pthread_mutex_t *, pthread_mutexattr_t *);
#	    int pthread_mutex_destroy(pthread_mutex_t *);
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
#	endif /* !OBJC */
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
#	ifndef OBJC4
#		define OBJC4(\
			__OBJC4_ROUGHNESS__, \
			__OBJC4_OPTION__, \
			__OBJC4_SIZE__, \
			__OBJC4_A__, \
			__OBJC4_a__, \
			__OBJC4_B__, \
			__OBJC4_b__, \
			__OBJC4_C__, \
			__OBJC4_c__, \
			__OBJC4_D__, \
			__OBJC4_d__\
		) (\
			(\
				__OBJC4_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__OBJC4_A__, \
					__OBJC4_B__, \
					__OBJC4_C__, \
					__OBJC4_D__\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC4_OPTION__, \
			sel_getUid(__OBJC4_SIZE__), \
			__OBJC4_a__, \
			__OBJC4_b__, \
			__OBJC4_c__, \
			__OBJC4_d__\
		)
#	endif /* !OBJC4 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* !REFRESH_SCREEN */
/* ************************* [^] HELPER MACROS [^] ************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern INLINE void	APP_DRAW_RECT(
	const id VIEW,
	const SEL SELECTOR,
	const CGRect RECT
);
extern INLINE BOOL	WINDOW_SHOULD_CLOSE(
	const id VIEW,
	const SEL SELECTOR,
	const id WINDOW
);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	CREATE_WINDOW(
	struct S_APP *APP,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
{
	Class	VOYAGER;
	Class	VIEW_CLASS;
	id		TITLE;
	id		VIEW;

	APP->BUFFER = (unsigned int *)
		malloc(sizeof(unsigned int) * (WIDTH * HEIGHT + 1));

	if (!APP->BUFFER)
		return (-1);

	if (pthread_mutex_init(&APP->CLOSE_THREAD_MUTEX, ((void *)0)))
	{
		free(APP->BUFFER);
		APP->BUFFER = ((void *)0);
		return (-1);
	}

	PREFETCH_RANGE(APP->BUFFER, WIDTH * HEIGHT);
	APP->WIDTH = WIDTH;
	APP->HEIGHT = HEIGHT;
	OBJC(id, REFRESH_SCREEN("NSApplication"), "sharedApplication");
	OBJC1(void, NSApp, "setActivationPolicy:", NSInteger, 0);
	APP->WINDOW_MODULE = OBJC4(
		id,
		OBJC(
			id,
			REFRESH_SCREEN("NSWindow"),
			"alloc"
		),
		"initWithContentRect:styleMask:backing:defer:",
		CGRect,
		CGRectMake(
			0,
			0,
			APP->WIDTH,
			APP->HEIGHT
		),
		NSUInteger,
		3,
		NSUInteger,
		2,
		BOOL,
		NO
	);

	if (!APP->WINDOW_MODULE)
	{
		free(APP->BUFFER);
		APP->BUFFER = ((void *)0);
		pthread_mutex_destroy(&APP->CLOSE_THREAD_MUTEX);
		return (-1);
	}

	VOYAGER = objc_allocateClassPair(
		(Class)REFRESH_SCREEN("NSObject"),
		"WindowDelegate",
		0
	);

	if (!VOYAGER)
	{
		CLOSE_WINDOW(APP);
		return (-1);
	}

	class_addMethod(
		VOYAGER,
		sel_getUid("windowShouldClose:"),
		(IMP)WINDOW_SHOULD_CLOSE,
		"c@:@"
	);
	objc_registerClassPair(VOYAGER);
	OBJC1(
		void,
		APP->WINDOW_MODULE,
		"setDelegate:",
		id,
		OBJC(
			id,
			OBJC(
				id,
				(id)VOYAGER,
				"alloc"
			),
			"init"
		)
	);
	VIEW_CLASS = objc_allocateClassPair(
		(Class)REFRESH_SCREEN("NSView"),
		"WindowView",
		0
	);

	if (!VIEW_CLASS)
	{
		CLOSE_WINDOW(APP);
		return (-1);
	}

	class_addMethod(
		VIEW_CLASS,
		sel_getUid("drawRect:"),
		(IMP)APP_DRAW_RECT,
		"i@:@@"
	);
	objc_registerClassPair(VIEW_CLASS);
	VIEW = OBJC(
		id,
		OBJC(
			id,
			(id)VIEW_CLASS,
			"alloc"
		),
		"init"
	);

	if (!VIEW)
	{
		objc_disposeClassPair(VIEW_CLASS);
		CLOSE_WINDOW(APP);
		return (-1);
	}

	OBJC1(void, APP->WINDOW_MODULE, "setContentView:", id, VIEW);
	objc_setAssociatedObject(
		VIEW,
		"APP",
		(id)APP,
		OBJC_ASSOCIATION_ASSIGN
	);
	TITLE = OBJC1(
		id,
		REFRESH_SCREEN("NSString"),
		"stringWithUTF8String:",
		const char *,
		APP->TITLE
	);
	APP->COLOR_SPACE = CGColorSpaceCreateDeviceRGB();

	if (!APP->COLOR_SPACE)
	{
		CLOSE_WINDOW(APP);
		return (-1);
	}

	APP->IMAGE_PROVIDER = CGDataProviderCreateWithData(
		((void *)0),
		APP->BUFFER,
		(APP->WIDTH * APP->HEIGHT) << 2,
		((void *)0)
	);

	if (!APP->IMAGE_PROVIDER)
	{
		CLOSE_WINDOW(APP);
		return (-1);
	}

	OBJC1(void, APP->WINDOW_MODULE, "setTitle:", id, TITLE);
	OBJC1(
		void,
		APP->WINDOW_MODULE,
		"makeKeyAndOrderFront:",
		id,
		((void *)0)
	);
	OBJC(void, APP->WINDOW_MODULE, "center");
	OBJC1(void, NSApp, "activateIgnoringOtherApps:", BOOL, YES);
	APP->CANVAS_INFO = CGRectMake(0, 0, APP->WIDTH, APP->HEIGHT);
	return (0);
}

extern INLINE void
	APP_DRAW_RECT(const id VIEW, const SEL SELECTOR, const CGRect RECT)
{
	static struct S_APP	*APP = ((void *)0);
	CGContextRef			CONTEXT;
	CGImageRef				IMAGE;

	IGNORE_VAR	RECT;
	IGNORE_VAR	SELECTOR;

	if (!APP)
		APP = (struct S_APP *)objc_getAssociatedObject(VIEW, "APP");

	CONTEXT = OBJC(
		CGContextRef,
		OBJC(
			id,
			REFRESH_SCREEN("NSGraphicsContext"),
			"currentContext"
		),
		"graphicsPort"
	);
	IMAGE = CGImageCreate(
		APP->WIDTH,
		APP->HEIGHT,
		8,
		32,
		APP->WIDTH << 2,
		APP->COLOR_SPACE,
		(
			kCGImageAlphaNoneSkipFirst |
			kCGBitmapByteOrder32Little
		),
		APP->IMAGE_PROVIDER,
		((void *)0),
		false,
		kCGRenderingIntentDefault
	);
	CGContextDrawImage(
		CONTEXT,
		APP->CANVAS_INFO,
		IMAGE
	);
	CGImageRelease(IMAGE);
}

extern INLINE BOOL
	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, const id WINDOW)
{
	IGNORE_VAR	VIEW;
	IGNORE_VAR	SELECTOR;
	IGNORE_VAR	WINDOW;

	OBJC1(void, NSApp, "terminate:", id, NSApp);
	return (YES);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C */
