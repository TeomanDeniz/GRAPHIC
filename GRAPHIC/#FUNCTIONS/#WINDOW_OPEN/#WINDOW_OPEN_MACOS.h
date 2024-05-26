/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_OPEN_MACOS       #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_OPEN_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include "../../CMT/KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	   void free(void *);
#	        */
#	include "../../CMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	 define NO
#	 define YES
v	>>>>>>> (NSApplication)
G	^^^^^^^ *NSApp;
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
#	   void CGColorSpaceRelease(CGColorSpaceRef);
#	   void CGDataProviderRelease(CGDataProviderRef);
#	   void CGContextDrawImage(CGContextRef, CGRect, CGImageRef);
#	   void CGImageRelease(CGImageRef);
#	        */
#	include "../../CMT/KEYWORDS/UNUSED.h" /*
#	 define UNUSED
#	 define NOPE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
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
#	ifndef MSG4
#		define MSG4(\
			__MSG4_ROUGHNESS__, \
			__MSG4_OPTION__, \
			__MSG4_SIZE__, \
			__MSG4_A__, \
			__MSG4_a__, \
			__MSG4_B__, \
			__MSG4_b__, \
			__MSG4_C__, \
			__MSG4_c__, \
			__MSG4_D__, \
			__MSG4_d__\
		) (\
			(\
				__MSG4_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG4_A__, \
					__MSG4_B__, \
					__MSG4_C__, \
					__MSG4_D__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG4_OPTION__, \
			sel_getUid(__MSG4_SIZE__), \
			__MSG4_a__, \
			__MSG4_b__, \
			__MSG4_c__, \
			__MSG4_d__\
		)
#	endif /* MSG4 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* REFRESH_SCREEN */
/* ************************* [^] HELPER MACROS [^] ************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern INLINE void	GRAPHIC_DRAW_RECT(const id VIEW, const SEL SELECTOR, \
const CGRect RECT);
extern INLINE BOOL	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, \
const id WINDOW);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC, register unsigned int WIDTH, \
register unsigned int HEIGHT)
{
	Class    (VOYAGER);
	Class (VIEW_CLASS);
	id         (TITLE);
	id          (VIEW);

	GRAPHIC->BUFFER = (unsigned int *)malloc(\
		sizeof(unsigned int) * (WIDTH * HEIGHT + 1)\
	);

	if (!GRAPHIC->BUFFER)
		return (-1);

	PREFETCH_RANGE(GRAPHIC->BUFFER, WIDTH * HEIGHT);
	GRAPHIC->WIDTH = WIDTH;
	GRAPHIC->HEIGHT = HEIGHT;
	MSG(id, REFRESH_SCREEN("NSApplication"), "sharedApplication");
	MSG1(void, NSApp, "setActivationPolicy:", NSInteger, 0);
	GRAPHIC->WINDOW_MODULE = MSG4(\
		id, \
		MSG(\
			id, \
			REFRESH_SCREEN("NSWindow"), \
			"alloc"\
		), \
		"initWithContentRect:styleMask:backing:defer:", \
		CGRect, \
		CGRectMake(\
			0, \
			0, \
			GRAPHIC->WIDTH, \
			GRAPHIC->HEIGHT\
		), \
		NSUInteger, \
		3, \
		NSUInteger, \
		2, \
		BOOL, \
		NO\
	);

	if (!GRAPHIC->WINDOW_MODULE)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	VOYAGER = objc_allocateClassPair(\
		(Class)REFRESH_SCREEN("NSObject"), \
		"WindowDelegate", \
		0\
	);

	if (!VOYAGER)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	class_addMethod(\
		VOYAGER, \
		sel_getUid("windowShouldClose:"), \
		(IMP)WINDOW_SHOULD_CLOSE, \
		"c@:@"\
	);
	objc_registerClassPair(VOYAGER);
	MSG1(\
		void, \
		GRAPHIC->WINDOW_MODULE, \
		"setDelegate:", \
		id, \
		MSG(\
			id, \
			MSG(\
				id, \
				(id)VOYAGER, \
				"alloc"\
			), \
			"init"\
		)\
	);
	VIEW_CLASS = objc_allocateClassPair(\
		(Class)REFRESH_SCREEN("NSView"), \
		"WindowView", \
		0\
	);

	if (!VIEW_CLASS)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	class_addMethod(\
		VIEW_CLASS, \
		sel_getUid("drawRect:"), \
		(IMP)GRAPHIC_DRAW_RECT, \
		"i@:@@"\
	);
	objc_registerClassPair(VIEW_CLASS);
	VIEW = MSG(\
		id, \
		MSG(\
			id, \
			(id)VIEW_CLASS, \
			"alloc"\
		), \
		"init"\
	);

	if (!VIEW)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	MSG1(void, GRAPHIC->WINDOW_MODULE, "setContentView:", id, VIEW);
	objc_setAssociatedObject(\
		VIEW, \
		"GRAPHIC", \
		(id)GRAPHIC, \
		OBJC_ASSOCIATION_ASSIGN\
	);
	TITLE = MSG1(\
		id, \
		REFRESH_SCREEN("NSString"), \
		"stringWithUTF8String:", \
		const char *, \
		GRAPHIC->TITLE\
	);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "setTitle:", id, TITLE);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "makeKeyAndOrderFront:", id, nil);
	MSG(void, GRAPHIC->WINDOW_MODULE, "center");
	MSG1(void, NSApp, "activateIgnoringOtherApps:", BOOL, YES);
	GRAPHIC->WINDOW_EXIST = 1;
	return (0);
}

extern INLINE void
	GRAPHIC_DRAW_RECT(const id VIEW, const SEL SELECTOR, const CGRect RECT)
{
	NOPE RECT;
	NOPE SELECTOR;

	struct GRAPHIC    *(GRAPHIC);
	CGContextRef       (CONTEXT);
	CGColorSpaceRef      (SPACE);
	CGDataProviderRef (PROVIDER);
	CGImageRef           (IMAGE);

	GRAPHIC = (struct GRAPHIC *)objc_getAssociatedObject(VIEW, "GRAPHIC");
	CONTEXT = MSG(\
		CGContextRef, \
		MSG(\
			id, \
			REFRESH_SCREEN("NSGraphicsContext"), \
			"currentContext"\
		), \
		"graphicsPort"\
	);
	SPACE = CGColorSpaceCreateDeviceRGB();
	PROVIDER = CGDataProviderCreateWithData(\
		NULL, \
		GRAPHIC->BUFFER, \
		GRAPHIC->WIDTH * GRAPHIC->HEIGHT * 4, \
		NULL\
	);
	IMAGE = CGImageCreate(\
		GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, \
		8, \
		32, \
		GRAPHIC->WIDTH * 4, \
		SPACE, \
		(\
			kCGImageAlphaNoneSkipFirst | \
			kCGBitmapByteOrder32Little\
		), \
		PROVIDER, \
		NULL, \
		false, \
		kCGRenderingIntentDefault\
	);
	CGColorSpaceRelease(SPACE);
	CGDataProviderRelease(PROVIDER);
	CGContextDrawImage(\
		CONTEXT, \
		CGRectMake(\
			0, \
			0, \
			GRAPHIC->WIDTH, \
			GRAPHIC->HEIGHT\
		), \
		IMAGE\
	);
	CGImageRelease(IMAGE);
}

extern INLINE BOOL
	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, const id WINDOW)
{
	NOPE VIEW;
	NOPE SELECTOR;
	NOPE WINDOW;

	MSG1(void, NSApp, "terminate:", id, NSApp);
	return (YES);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_H */