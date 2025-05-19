/******************************************************************************\
# H - APP_LOOP__MACOS                            #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../LIBCGFX.h" /*
#	 struct S_APP;
#      void CLOSE_WINDOW(struct S_APP *);
#	        */
#	include "../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include <CoreFoundation/CoreFoundation.h> /*
#	 struct CFRunLoopActivity;
#	 struct CFRunLoopTimerContext;
#	typedef CFRunLoopObserverRef;
#	typedef CFRunLoopTimerRef;
v	 >>>>>> (CFRunLoopTimerRef)
#	 ^^^^^^ CFRunLoopTimerCreate(CFAllocatorRef, CFAbsoluteTime, CFTimeInterval,
>	        CFOptionFlags, CFIndex, void (*f)(CFRunLoopTimerRef, void *),
>	        CFRunLoopTimerContext *);
#	   void CFRunLoopAddTimer(CFRunLoopRef, CFRunLoopTimerRef, CFStringRef);
v	 >>>>>> (CFRunLoopRef)
#	 ^^^^^^ CFRunLoopGetMain(void);
#	        */
#	include <objc/objc-runtime.h> /*
#	typedef *SEL;
#	    SEL sel_getUid(const char *);
#	  Class objc_getClass(const char *);
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	 define YES
v	>>>>>>> (NSApplication)
G	^^^^^^^ *NSApp;
#	 define NSUIntegerMax
#	typedef BOOL;
#	typedef id;
#	typedef NSUInteger;
#	        */
#	include <CoreGraphics/CoreGraphics.h> /*
#	typedef CGPoint;
#	        */
#	include <pthread.h> /*
#	    int pthread_create(pthread_t *, pthread_attr_t *, void *(*f)(void *),
>	        void *);
#	    int pthread_mutex_lock(pthread_mutex_t *);
#	    int pthread_mutex_unlock(pthread_mutex_t *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
extern id const	NSDefaultRunLoopMode;
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
static void	__APP_LOOP__(
	CFRunLoopObserverRef OBSERVER,
	CFRunLoopActivity ACTIVITY,
	void *ARG
);
static void	__TIMER_LOOP__(CFRunLoopTimerRef OBSERVER, void *ARG);
static void	*__THREAD_UPDATE_WINDOW__(void *ARG);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	APP_LOOP(struct S_APP *APP)
{
	CFRunLoopTimerContext		TIMER_CONTEXT;
	CFRunLoopTimerRef			TIMER_ID;
	CFRunLoopObserverContext	OBSERVER_CONTEXT;
	CFRunLoopObserverRef		OBSERVER_ID;
	Class						NS_DATE;

	if (!!APP->FUNCTION_LOOP)
	{
		TIMER_CONTEXT.version = 0;
		TIMER_CONTEXT.info = (void *)APP;
		TIMER_CONTEXT.retain = ((void *)0);
		TIMER_CONTEXT.release = ((void *)0);
		TIMER_CONTEXT.copyDescription = ((void *)0);
		TIMER_ID = CFRunLoopTimerCreate(
			kCFAllocatorDefault,
			0.0,
			0.0001,
			0,
			0,
			__TIMER_LOOP__,
			&TIMER_CONTEXT
		);
		APP->TIMER_ID = TIMER_ID;
		CFRunLoopAddTimer(CFRunLoopGetMain(), TIMER_ID, kCFRunLoopCommonModes);
	}

	OBSERVER_CONTEXT.version = 0;
	OBSERVER_CONTEXT.info = (void *)APP;
	OBSERVER_CONTEXT.retain = ((void *)0);
	OBSERVER_CONTEXT.release = ((void *)0);
	OBSERVER_CONTEXT.copyDescription = ((void *)0);
	OBSERVER_ID = CFRunLoopObserverCreate(
		((void *)0),
		kCFRunLoopBeforeTimers,
		true,
		0,
		__APP_LOOP__,
		&OBSERVER_CONTEXT
	);
	APP->OBSERVER_ID = OBSERVER_ID;
	CFRunLoopAddObserver(
		CFRunLoopGetMain(),
		OBSERVER_ID,
		kCFRunLoopCommonModes
	);
	NS_DATE = ((Class(*)(Class, SEL, double))objc_msgSend)(
		objc_getClass("NSDate"),
		sel_getUid("dateWithTimeIntervalSinceNow:"),
		0.1
	);

	if (
		pthread_create(
			&APP->THREAD_UPDATE_WINDOW,
			((void *)0),
			__THREAD_UPDATE_WINDOW__,
			APP
		)
	)
	{
		CLOSE_WINDOW(APP);
		return (-1);
	}

	while (!!APP->WINDOW_MODULE)
	{
		APP->EVENT = OBJC4(
			id,
			NSApp,
			"nextEventMatchingMask:untilDate:inMode:dequeue:",
			NSUInteger,
			NSUIntegerMax,
			Class,
			NS_DATE,
			id,
			NSDefaultRunLoopMode,
			BOOL,
			YES
		);
		OBJC1(
			void,
			OBJC(
				id,
				APP->WINDOW_MODULE,
				"contentView"
			),
			"setNeedsDisplay:",
			BOOL,
			YES
		);

		if (!APP->EVENT)
			continue ;

		OBJC1(void, NSApp, "sendEvent:", id, APP->EVENT); // DO NEXT EVENT
		//OBJC(void, NSApp, "updateWindows");
	}

	return (0);
}

static void
	__APP_LOOP__(
	CFRunLoopObserverRef OBSERVER,
	CFRunLoopActivity ACTIVITY,
	void *ARG
)
{
	struct S_APP	*APP;
	NSUInteger		EVENT_TYPE;

	IGNORE_VAR	OBSERVER;
	IGNORE_VAR	ACTIVITY;

	APP = (struct S_APP *)ARG;
	EVENT_TYPE = OBJC(NSUInteger, APP->EVENT, "type");
	APP->MOUSE.LEFT_UP = 0;
	APP->MOUSE.RIGHT_UP = 0;
	APP->MOUSE.VALUE = 0;
	APP->MOUSE.MIDDLE_UP = 0;
	APP->MOUSE.WHEEL = 0;
	APP->MOUSE.HORIZANTAL_WHEEL = 0;

	switch (EVENT_TYPE) // "switch case" is speed! Wrom wrommmm!!!
	{
		case (1): /* NSEventTypeLeftMouseDown */
		{
			APP->MOUSE.LEFT_DOWN = 1;

			if (!!APP->FUNCTION_MOUSE)
			{
				APP->FUNCTION_MOUSE(
					APP->MOUSE.X,
					APP->MOUSE.Y,
					APP->MOUSE.VALUE,
					APP->FUNCTION_MOUSE_ARG
				);
			}

			break ;
		}
		case (2): /* NSEventTypeLeftMouseUp*/
		{
			APP->MOUSE.LEFT_DOWN = 0;
			APP->MOUSE.LEFT_UP = 1;
			break ;
		}
		case (5): /* NSEventTypeMouseMoved */
		case (6): /* NSEventTypeLeftMouseDragged */
		case (7): /* NSEventTypeRightMouseDragged */
		{
			register CGPoint	X_AND_Y;

			X_AND_Y = OBJC(
				CGPoint,
				APP->WINDOW_MODULE,
				"mouseLocationOutsideOfEventStream" /* Thx miniLibX <3 */
			);
			APP->MOUSE.X = (int)X_AND_Y.x;
			APP->MOUSE.Y = (APP->HEIGHT - (int)X_AND_Y.y);

			if (!!APP->FUNCTION_MOUSE)
				APP->FUNCTION_MOUSE(
					APP->MOUSE.X,
					APP->MOUSE.Y,
					APP->MOUSE.VALUE,
					APP->FUNCTION_MOUSE_ARG
				);

			return ;
		}
		case (10): /* NSEventTypeKeyDown */
		case (11): /* NSEventTypeKeyUp */
		case (12): /* NSEventTypeFlagsChanged (AKA: Command, Option etc keys) */
		{
			register NSUInteger	KEY;

			KEY = OBJC(NSUInteger, APP->EVENT, "keyCode");

			switch (KEY)
			{ // "switch case" is speed! Wrom wrommmm!!!
				case (0):
				{
					APP->KEY.A = (EVENT_TYPE == 10);

					if (APP->KEY.A)
						APP->KEY.DOWN = 65;
					else
						APP->KEY.UP = 65;

					break ;
				}
				case (1):
				{
					APP->KEY.S = (EVENT_TYPE == 10);

					if (APP->KEY.S)
						APP->KEY.DOWN = 83;
					else
						APP->KEY.UP = 83;

					break ;
				}
				case (2):
				{
					APP->KEY.D = (EVENT_TYPE == 10);

					if (APP->KEY.D)
						APP->KEY.DOWN = 68;
					else
						APP->KEY.UP = 68;

					break ;
				}
				case (3):
				{
					APP->KEY.F = (EVENT_TYPE == 10);

					if (APP->KEY.F)
						APP->KEY.DOWN = 70;
					else
						APP->KEY.UP = 70;

					break ;
				}
				case (4):
				{
					APP->KEY.H = (EVENT_TYPE == 10);

					if (APP->KEY.H)
						APP->KEY.DOWN = 72;
					else
						APP->KEY.UP = 72;

					break ;
				}
				case (5):
				{
					APP->KEY.G = (EVENT_TYPE == 10);

					if (APP->KEY.G)
						APP->KEY.DOWN = 71;
					else
						APP->KEY.UP = 71;

					break ;
				}
				case (6):
				{
					APP->KEY.Z = (EVENT_TYPE == 10);

					if (APP->KEY.Z)
						APP->KEY.DOWN = 90;
					else
						APP->KEY.UP = 90;

					break ;
				}
				case (7):
				{
					APP->KEY.X = (EVENT_TYPE == 10);

					if (APP->KEY.X)
						APP->KEY.DOWN = 88;
					else
						APP->KEY.UP = 88;

					break ;
				}
				case (8):
				{
					APP->KEY.C = (EVENT_TYPE == 10);

					if (APP->KEY.C)
						APP->KEY.DOWN = 67;
					else
						APP->KEY.UP = 67;

					break ;
				}
				case (9):
				{
					APP->KEY.V = (EVENT_TYPE == 10);

					if (APP->KEY.V)
						APP->KEY.DOWN = 86;
					else
						APP->KEY.UP = 86;

					break ;
				}
				case (10):
				{
					APP->KEY.SELECTION_SIGN = (EVENT_TYPE == 10);

					if (APP->KEY.SELECTION_SIGN)
						APP->KEY.DOWN = 245;
					else
						APP->KEY.UP = 245;

					break ;
				}
				case (11):
				{
					APP->KEY.B = (EVENT_TYPE == 10);

					if (APP->KEY.B)
						APP->KEY.DOWN = 66;
					else
						APP->KEY.UP = 66;

					break ;
				}
				case (12):
				{
					APP->KEY.Q = (EVENT_TYPE == 10);

					if (APP->KEY.Q)
						APP->KEY.DOWN = 81;
					else
						APP->KEY.UP = 81;

					break ;
				}
				case (13):
				{
					APP->KEY.W = (EVENT_TYPE == 10);

					if (APP->KEY.W)
						APP->KEY.DOWN = 87;
					else
						APP->KEY.UP = 87;

					break ;
				}
				case (14):
				{
					APP->KEY.E = (EVENT_TYPE == 10);

					if (APP->KEY.E)
						APP->KEY.DOWN = 69;
					else
						APP->KEY.UP = 69;

					break ;
				}
				case (15):
				{
					APP->KEY.R = (EVENT_TYPE == 10);

					if (APP->KEY.R)
						APP->KEY.DOWN = 82;
					else
						APP->KEY.UP = 82;

					break ;
				}
				case (16):
				{
					APP->KEY.Y = (EVENT_TYPE == 10);

					if (APP->KEY.Y)
						APP->KEY.DOWN = 89;
					else
						APP->KEY.UP = 89;

					break ;
				}
				case (17):
				{
					APP->KEY.T = (EVENT_TYPE == 10);

					if (APP->KEY.T)
						APP->KEY.DOWN = 84;
					else
						APP->KEY.UP = 84;

					break ;
				}
				case (18):
				{
					APP->KEY._1 = (EVENT_TYPE == 10);

					if (APP->KEY._1)
						APP->KEY.DOWN = 49;
					else
						APP->KEY.UP = 49;

					break ;
				}
				case (19):
				{
					APP->KEY._2 = (EVENT_TYPE == 10);

					if (APP->KEY._2)
						APP->KEY.DOWN = 50;
					else
						APP->KEY.UP = 50;

					break ;
				}
				case (20):
				{
					APP->KEY._3 = (EVENT_TYPE == 10);

					if (APP->KEY._3)
						APP->KEY.DOWN = 51;
					else
						APP->KEY.UP = 51;

					break ;
				}
				case (21):
				{
					APP->KEY._4 = (EVENT_TYPE == 10);

					if (APP->KEY._4)
						APP->KEY.DOWN = 52;
					else
						APP->KEY.UP = 52;

					break ;
				}
				case (22):
				{
					APP->KEY._6 = (EVENT_TYPE == 10);

					if (APP->KEY._6)
						APP->KEY.DOWN = 54;
					else
						APP->KEY.UP = 54;

					break ;
				}
				case (23):
				{
					APP->KEY._5 = (EVENT_TYPE == 10);

					if (APP->KEY._5)
						APP->KEY.DOWN = 53;
					else
						APP->KEY.UP = 53;

					break ;
				}
				case (24):
				{
					APP->KEY.EQUAL = (EVENT_TYPE == 10);

					if (APP->KEY.EQUAL)
						APP->KEY.DOWN = 187;
					else
						APP->KEY.UP = 187;

					break ;
				}
				case (25):
				{
					APP->KEY._9 = (EVENT_TYPE == 10);

					if (APP->KEY._9)
						APP->KEY.DOWN = 57;
					else
						APP->KEY.UP = 57;

					break ;
				}
				case (26):
				{
					APP->KEY._7 = (EVENT_TYPE == 10);

					if (APP->KEY._7)
						APP->KEY.DOWN = 55;
					else
						APP->KEY.UP = 55;

					break ;
				}
				case (27):
				{
					APP->KEY.MINUS = (EVENT_TYPE == 10);

					if (APP->KEY.MINUS)
						APP->KEY.DOWN = 189;
					else
						APP->KEY.UP = 189;

					break ;
				}
				case (28):
				{
					APP->KEY._8 = (EVENT_TYPE == 10);

					if (APP->KEY._8)
						APP->KEY.DOWN = 56;
					else
						APP->KEY.UP = 56;

					break ;
				}
				case (29):
				{
					APP->KEY._0 = (EVENT_TYPE == 10);

					if (APP->KEY._0)
						APP->KEY.DOWN = 48;
					else
						APP->KEY.UP = 48;

					break ;
				}
				case (30):
				{
					APP->KEY.RIGHT_BRACKET = (EVENT_TYPE == 10);

					if (APP->KEY.RIGHT_BRACKET)
						APP->KEY.DOWN = 221;
					else
						APP->KEY.UP = 221;

					break ;
				}
				case (31):
				{
					APP->KEY.O = (EVENT_TYPE == 10);

					if (APP->KEY.O)
						APP->KEY.DOWN = 79;
					else
						APP->KEY.UP = 79;

					break ;
				}
				case (32):
				{
					APP->KEY.U = (EVENT_TYPE == 10);

					if (APP->KEY.U)
						APP->KEY.DOWN = 85;
					else
						APP->KEY.UP = 85;

					break ;
				}
				case (33):
				{
					APP->KEY.LEFT_BRACKET = (EVENT_TYPE == 10);

					if (APP->KEY.LEFT_BRACKET)
						APP->KEY.DOWN = 219;
					else
						APP->KEY.UP = 219;

					break ;
				}
				case (34):
				{
					APP->KEY.I = (EVENT_TYPE == 10);

					if (APP->KEY.I)
						APP->KEY.DOWN = 73;
					else
						APP->KEY.UP = 73;

					break ;
				}
				case (35):
				{
					APP->KEY.P = (EVENT_TYPE == 10);

					if (APP->KEY.P)
						APP->KEY.DOWN = 80;
					else
						APP->KEY.UP = 80;

					break ;
				}
				case (37):
				{
					APP->KEY.L = (EVENT_TYPE == 10);

					if (APP->KEY.L)
						APP->KEY.DOWN = 76;
					else
						APP->KEY.UP = 76;

					break ;
				}
				case (38):
				{
					APP->KEY.J = (EVENT_TYPE == 10);

					if (APP->KEY.J)
						APP->KEY.DOWN = 74;
					else
						APP->KEY.UP = 74;

					break ;
				}
				case (39):
				{
					APP->KEY.APOSTROPHE = (EVENT_TYPE == 10);

					if (APP->KEY.APOSTROPHE)
						APP->KEY.DOWN = 222;
					else
						APP->KEY.UP = 222;

					break ;
				}
				case (40):
				{
					APP->KEY.K = (EVENT_TYPE == 10);

					if (APP->KEY.K)
						APP->KEY.DOWN = 75;
					else
						APP->KEY.UP = 75;

					break ;
				}
				case (41):
				{
					APP->KEY.SEMICOLON = (EVENT_TYPE == 10);

					if (APP->KEY.SEMICOLON)
						APP->KEY.DOWN = 186;
					else
						APP->KEY.UP = 186;

					break ;
				}
				case (42):
				{
					APP->KEY.BACKSLASH = (EVENT_TYPE == 10);

					if (APP->KEY.BACKSLASH)
						APP->KEY.DOWN = 220;
					else
						APP->KEY.UP = 220;

					break ;
				}
				case (43):
				{
					APP->KEY.COMMA = (EVENT_TYPE == 10);

					if (APP->KEY.COMMA)
						APP->KEY.DOWN = 188;
					else
						APP->KEY.UP = 188;

					break ;
				}
				case (44):
				{
					APP->KEY.SLASH = (EVENT_TYPE == 10);

					if (APP->KEY.SLASH)
						APP->KEY.DOWN = 191;
					else
						APP->KEY.UP = 191;

					break ;
				}
				case (45):
				{
					APP->KEY.N = (EVENT_TYPE == 10);

					if (APP->KEY.N)
						APP->KEY.DOWN = 78;
					else
						APP->KEY.UP = 78;

					break ;
				}
				case (46):
				{
					APP->KEY.M = (EVENT_TYPE == 10);

					if (APP->KEY.M)
						APP->KEY.DOWN = 77;
					else
						APP->KEY.UP = 77;

					break ;
				}
				case (47):
				{
					APP->KEY.DOT = (EVENT_TYPE == 10);

					if (APP->KEY.DOT)
						APP->KEY.DOWN = 190;
					else
						APP->KEY.UP = 190;

					break ;
				}
				case (48):
				{
					APP->KEY.TAB = (EVENT_TYPE == 10);

					if (APP->KEY.TAB)
						APP->KEY.DOWN = 9;
					else
						APP->KEY.UP = 9;

					break ;
				}
				case (49):
				{
					APP->KEY.SPACEBAR = (EVENT_TYPE == 10);

					if (APP->KEY.SPACEBAR)
						APP->KEY.DOWN = 32;
					else
						APP->KEY.UP = 32;

					break ;
				}
				case (50):
				{
					APP->KEY.GRAVE = (EVENT_TYPE == 10);

					if (APP->KEY.GRAVE)
						APP->KEY.DOWN = 192;
					else
						APP->KEY.UP = 192;

					break ;
				}
				case (51):
				{
					APP->KEY.BACKSPACE = (EVENT_TYPE == 10);

					if (APP->KEY.BACKSPACE)
						APP->KEY.DOWN = 8;
					else
						APP->KEY.UP = 8;

					break ;
				}
				case (53):
				{
					APP->KEY.ESC = (EVENT_TYPE == 10);

					if (APP->KEY.ESC)
						APP->KEY.DOWN = 27;
					else
						APP->KEY.UP = 27;

					break ;
				}
				case (65):
				{
					APP->KEY.DOT = (EVENT_TYPE == 10);

					if (APP->KEY.DOT)
						APP->KEY.DOWN = 190;
					else
						APP->KEY.UP = 190;

					break ;
				}
				case (67):
				{
					APP->KEY.ASTERISK = (EVENT_TYPE == 10);

					if (APP->KEY.ASTERISK)
						APP->KEY.DOWN = 42;
					else
						APP->KEY.UP = 42;

					break ;
				}
				case (69):
				{
					APP->KEY.PLUS = (EVENT_TYPE == 10);

					if (APP->KEY.PLUS)
						APP->KEY.DOWN = 43;
					else
						APP->KEY.UP = 43;

					break ;
				}
				case (75):
				{
					APP->KEY.SLASH = (EVENT_TYPE == 10);

					if (APP->KEY.SLASH)
						APP->KEY.DOWN = 191;
					else
						APP->KEY.UP = 191;

					break ;
				}
				case (76):
				{
					APP->KEY.ENTER = (EVENT_TYPE == 10);

					if (APP->KEY.ENTER)
						APP->KEY.DOWN = 10;
					else
						APP->KEY.UP = 10;

					break ;
				}
				case (78):
				{
					APP->KEY.MINUS = (EVENT_TYPE == 10);

					if (APP->KEY.MINUS)
						APP->KEY.DOWN = 189;
					else
						APP->KEY.UP = 189;

					break ;
				}
				case (81):
				{
					APP->KEY.EQUAL = (EVENT_TYPE == 10);

					if (APP->KEY.EQUAL)
						APP->KEY.DOWN = 187;
					else
						APP->KEY.UP = 187;

					break ;
				}
				case (96):
				{
					APP->KEY.F5 = (EVENT_TYPE == 10);

					if (APP->KEY.F5)
						APP->KEY.DOWN = 116;
					else
						APP->KEY.UP = 116;

					break ;
				}
				case (97):
				{
					APP->KEY.F6 = (EVENT_TYPE == 10);

					if (APP->KEY.F6)
						APP->KEY.DOWN = 117;
					else
						APP->KEY.UP = 117;

					break ;
				}
				case (98):
				{
					APP->KEY.F7 = (EVENT_TYPE == 10);

					if (APP->KEY.F7)
						APP->KEY.DOWN = 118;
					else
						APP->KEY.UP = 118;

					break ;
				}
				case (99):
				{
					APP->KEY.F3 = (EVENT_TYPE == 10);

					if (APP->KEY.F3)
						APP->KEY.DOWN = 114;
					else
						APP->KEY.UP = 114;

					break ;
				}
				case (100):
				{
					APP->KEY.F8 = (EVENT_TYPE == 10);

					if (APP->KEY.F8)
						APP->KEY.DOWN = 119;
					else
						APP->KEY.UP = 119;

					break ;
				}
				case (101):
				{
					APP->KEY.F9 = (EVENT_TYPE == 10);

					if (APP->KEY.F9)
						APP->KEY.DOWN = 120;
					else
						APP->KEY.UP = 120;

					break ;
				}
				case (103):
				{
					APP->KEY.F11 = (EVENT_TYPE == 10);

					if (APP->KEY.F11)
						APP->KEY.DOWN = 122;
					else
						APP->KEY.UP = 122;

					break ;
				}
				case (109):
				{
					APP->KEY.F10 = (EVENT_TYPE == 10);

					if (APP->KEY.F10)
						APP->KEY.DOWN = 121;
					else
						APP->KEY.UP = 121;

					break ;
				}
				case (111):
				{
					APP->KEY.F12 = (EVENT_TYPE == 10);

					if (APP->KEY.F12)
						APP->KEY.DOWN = 123;
					else
						APP->KEY.UP = 123;

					break ;
				}
				case (114):
				{
					APP->KEY.HELP = (EVENT_TYPE == 10);

					if (APP->KEY.HELP)
						APP->KEY.DOWN = 47;
					else
						APP->KEY.UP = 47;

					break ;
				}
				case (115):
				{
					APP->KEY.HOME = (EVENT_TYPE == 10);

					if (APP->KEY.HOME)
						APP->KEY.DOWN = 36;
					else
						APP->KEY.UP = 36;

					break ;
				}
				case (116):
				{
					APP->KEY.PAGE_UP = (EVENT_TYPE == 10);

					if (APP->KEY.PAGE_UP)
						APP->KEY.DOWN = 33;
					else
						APP->KEY.UP = 33;

					break ;
				}
				case (117):
				{
					APP->KEY.DEL = (EVENT_TYPE == 10);

					if (APP->KEY.DEL)
						APP->KEY.DOWN = 46;
					else
						APP->KEY.UP = 46;

					break ;
				}
				case (118):
				{
					APP->KEY.F4 = (EVENT_TYPE == 10);

					if (APP->KEY.F4)
						APP->KEY.DOWN = 115;
					else
						APP->KEY.UP = 115;

					break ;
				}
				case (119):
				{
					APP->KEY.END = (EVENT_TYPE == 10);

					if (APP->KEY.END)
						APP->KEY.DOWN = 35;
					else
						APP->KEY.UP = 35;

					break ;
				}
				case (120):
				{
					APP->KEY.F2 = (EVENT_TYPE == 10);

					if (APP->KEY.F2)
						APP->KEY.DOWN = 113;
					else
						APP->KEY.UP = 113;

					break ;
				}
				case (121):
				{
					APP->KEY.PAGE_DOWN = (EVENT_TYPE == 10);

					if (APP->KEY.PAGE_DOWN)
						APP->KEY.DOWN = 34;
					else
						APP->KEY.UP = 34;

					break ;
				}
				case (122):
				{
					APP->KEY.F1 = (EVENT_TYPE == 10);

					if (APP->KEY.F1)
						APP->KEY.DOWN = 112;
					else
						APP->KEY.UP = 112;

					break ;
				}
				case (123):
				{
					APP->KEY.ARROW_LEFT = (EVENT_TYPE == 10);

					if (APP->KEY.ARROW_LEFT)
						APP->KEY.DOWN = 37;
					else
						APP->KEY.UP = 37;

					break ;
				}
				case (124):
				{
					APP->KEY.ARROW_RIGHT = (EVENT_TYPE == 10);

					if (APP->KEY.ARROW_RIGHT)
						APP->KEY.DOWN = 39;
					else
						APP->KEY.UP = 39;

					break ;
				}
				case (125):
				{
					APP->KEY.ARROW_DOWN = (EVENT_TYPE == 10);

					if (APP->KEY.ARROW_DOWN)
						APP->KEY.DOWN = 40;
					else
						APP->KEY.UP = 40;

					break ;
				}
				case (126):
				{
					APP->KEY.ARROW_UP = (EVENT_TYPE == 10);

					if (APP->KEY.ARROW_UP)
						APP->KEY.DOWN = 38;
					else
						APP->KEY.UP = 38;

					break ;
				}
				case (256):
				{
					APP->KEY.CONTROL = (EVENT_TYPE == 10);

					if (APP->KEY.CONTROL)
						APP->KEY.DOWN = KEY;
					else
						APP->KEY.UP = KEY;

					break ;
				}
				case (257):
				case (258):
				{
					APP->KEY.SHIFT = (EVENT_TYPE == 10);

					if (APP->KEY.SHIFT)
						APP->KEY.DOWN = 16;
					else
						APP->KEY.UP = 16;

					break ;
				}
				case (259):
				case (260):
				{
					APP->KEY.COMMAND = (EVENT_TYPE == 10);

					if (APP->KEY.COMMAND)
						APP->KEY.DOWN = KEY;
					else
						APP->KEY.UP = KEY;

					break ;
				}
				case (261):
				case (262):
				{
					APP->KEY.OPTION = (EVENT_TYPE == 10);

					if (APP->KEY.OPTION)
						APP->KEY.DOWN = KEY;
					else
						APP->KEY.UP = KEY;

					break ;
				}
				case (272):
				{
					APP->KEY.CAPSLOCK = (EVENT_TYPE == 10);

					if (APP->KEY.CAPSLOCK)
						APP->KEY.DOWN = 20;
					else
						APP->KEY.UP = 20;

					break ;
				}
				case (279):
				{
					APP->KEY.FN = (EVENT_TYPE == 10);

					if (APP->KEY.FN)
						APP->KEY.DOWN = 0;
					else
						APP->KEY.UP = 0;

					break ;
				}
			}

			if (EVENT_TYPE == 10)
			{
				if (!!APP->FUNCTION_KEY_DOWN)
				{
					APP->FUNCTION_KEY_DOWN(
						APP->KEY.DOWN,
						APP->FUNCTION_KEY_DOWN_ARG
					);
				}
			}
			else if (!!APP->FUNCTION_KEY_UP)
			{
				APP->FUNCTION_KEY_UP(
					APP->KEY.UP,
					APP->FUNCTION_KEY_UP_ARG
				);
			}

			return ;
		}
		default :
		{
			return ;
		}
	}
	
	return ;
}

static void /* Thank you MiniLibX!!! You saved my life! <3 <3 */
	__TIMER_LOOP__(CFRunLoopTimerRef OBSERVER, void *ARG)
{
	IGNORE_VAR	OBSERVER;

	((struct S_APP *)ARG)->\
		FUNCTION_LOOP(((struct S_APP *)ARG)->FUNCTION_LOOP_ARG);
		OBJC1(
			void,
			OBJC(
				id,
				((struct S_APP *)ARG)->WINDOW_MODULE,
				"contentView"
			),
			"setNeedsDisplay:",
			BOOL,
			YES
		);
}

static void
	*__THREAD_UPDATE_WINDOW__(void *ARG)
{
	struct S_APP	*APP;
	CGContextRef	CONTEXT;
	CGImageRef		IMAGE;
	id				NSGC;

	APP = (struct S_APP *)ARG;
	pthread_mutex_lock(&APP->CLOSE_THREAD_MUTEX);
	NSGC = REFRESH_SCREEN("NSGraphicsContext");

	while (!APP->CLOSE_THREAD)
	{
		pthread_mutex_unlock(&APP->CLOSE_THREAD_MUTEX);
		CONTEXT = OBJC(
			CGContextRef,
			OBJC(
				id,
				NSGC,
				"currentContext"
			),
			"graphicsPort"
		);

		IMAGE = CGImageCreate(
			APP->WIDTH,
			APP->HEIGHT,
			8,
			32,
			(APP->WIDTH << 2),
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

		if (!IMAGE)
		{
			pthread_mutex_lock(&APP->CLOSE_THREAD_MUTEX);
			continue ;
		}

		CGContextDrawImage(
			CONTEXT,
			APP->CANVAS_INFO,
			IMAGE
		);
		CGImageRelease(IMAGE);
		pthread_mutex_lock(&APP->CLOSE_THREAD_MUTEX);
	}

	pthread_mutex_unlock(&APP->CLOSE_THREAD_MUTEX);
	return ((void *)0);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C */
