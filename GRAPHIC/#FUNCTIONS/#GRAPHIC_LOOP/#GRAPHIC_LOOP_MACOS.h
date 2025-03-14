/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP_MACOS      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/03/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C
/* **************************** [v] INCLUDES [v] **************************** */
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
#	include "../../../GRAPHIC.h" /*
#	 struct GRAPHIC;
#      void WINDOW_CLOSE(struct GRAPHIC *);
#	        */
#	include "../../LIBCMT/KEYWORDS/IGNORE.h" /*
#	 define IGNORE
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
#	endif /* OBJC */
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
#	endif /* OBJC1 */
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
#	endif /* OBJC4 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* REFRESH_SCREEN */
/* ************************* [^] HELPER MACROS [^] ************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
static void	__GRAPHIC_LOOP__(
	CFRunLoopObserverRef OBSERVER,
	CFRunLoopActivity ACTIVITY,
	void *ARG
);
static void	__TIMER_LOOP__(CFRunLoopTimerRef OBSERVER, void *ARG);
static void	*__THREAD_UPDATE_WINDOW__(void *ARG);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	CFRunLoopTimerContext		TIMER_CONTEXT;
	CFRunLoopTimerRef			TIMER_ID;
	CFRunLoopObserverContext	OBSERVER_CONTEXT;
	CFRunLoopObserverRef		OBSERVER_ID;
	Class						NS_DATE;

	if (!!GRAPHIC->FUNCTION_LOOP)
	{
		TIMER_CONTEXT.version = 0;
		TIMER_CONTEXT.info = (void *)GRAPHIC;
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
		GRAPHIC->TIMER_ID = TIMER_ID;
		CFRunLoopAddTimer(CFRunLoopGetMain(), TIMER_ID, kCFRunLoopCommonModes);
	}

	OBSERVER_CONTEXT.version = 0;
	OBSERVER_CONTEXT.info = (void *)GRAPHIC;
	OBSERVER_CONTEXT.retain = ((void *)0);
	OBSERVER_CONTEXT.release = ((void *)0);
	OBSERVER_CONTEXT.copyDescription = ((void *)0);
	OBSERVER_ID = CFRunLoopObserverCreate(
		((void *)0),
		kCFRunLoopBeforeTimers,
		true,
		0,
		__GRAPHIC_LOOP__,
		&OBSERVER_CONTEXT
	);
	GRAPHIC->OBSERVER_ID = OBSERVER_ID;
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
			&GRAPHIC->THREAD_UPDATE_WINDOW,
			((void *)0),
			__THREAD_UPDATE_WINDOW__,
			GRAPHIC
		)
	)
	{
		WINDOW_CLOSE(GRAPHIC);
		return (-1);
	}

	while (!!GRAPHIC->WINDOW_MODULE)
	{
		GRAPHIC->EVENT = OBJC4(
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
				GRAPHIC->WINDOW_MODULE,
				"contentView"
			),
			"setNeedsDisplay:",
			BOOL,
			YES
		);

		if (!GRAPHIC->EVENT)
			continue ;

		OBJC1(void, NSApp, "sendEvent:", id, GRAPHIC->EVENT); // DO NEXT EVENT
		//OBJC(void, NSApp, "updateWindows");
	}

	return (0);
}

static void
	__GRAPHIC_LOOP__(
	CFRunLoopObserverRef OBSERVER,
	CFRunLoopActivity ACTIVITY,
	void *ARG
)
{
	struct GRAPHIC	*GRAPHIC;
	NSUInteger		EVENT_TYPE;

	IGNORE	OBSERVER;
	IGNORE	ACTIVITY;

	GRAPHIC = (struct GRAPHIC *)ARG;
	EVENT_TYPE = OBJC(NSUInteger, GRAPHIC->EVENT, "type");
	GRAPHIC->MOUSE.LEFT_UP = 0;
	GRAPHIC->MOUSE.RIGHT_UP = 0;
	GRAPHIC->MOUSE.VALUE = 0;
	GRAPHIC->MOUSE.MIDDLE_UP = 0;
	GRAPHIC->MOUSE.WHEEL = 0;
	GRAPHIC->MOUSE.HORIZANTAL_WHEEL = 0;

	switch (EVENT_TYPE) // "switch case" is speed! Wrom wrommmm!!!
	{
		case (1): /* NSEventTypeLeftMouseDown */
		{
			GRAPHIC->MOUSE.LEFT_DOWN = 1;

			if (!!GRAPHIC->FUNCTION_MOUSE)
			{
				GRAPHIC->FUNCTION_MOUSE(
					GRAPHIC->MOUSE.X,
					GRAPHIC->MOUSE.Y,
					GRAPHIC->MOUSE.VALUE,
					GRAPHIC->FUNCTION_MOUSE_ARG
				);
			}

			break ;
		}
		case (2): /* NSEventTypeLeftMouseUp*/
		{
			GRAPHIC->MOUSE.LEFT_DOWN = 0;
			GRAPHIC->MOUSE.LEFT_UP = 1;
			break ;
		}
		case (5): /* NSEventTypeMouseMoved */
		case (6): /* NSEventTypeLeftMouseDragged */
		case (7): /* NSEventTypeRightMouseDragged */
		{
			register CGPoint	X_AND_Y;

			X_AND_Y = OBJC(
				CGPoint,
				GRAPHIC->WINDOW_MODULE,
				"mouseLocationOutsideOfEventStream" /* Thx miniLibX <3 */
			);
			GRAPHIC->MOUSE.X = (int)X_AND_Y.x;
			GRAPHIC->MOUSE.Y = (GRAPHIC->HEIGHT - (int)X_AND_Y.y);

			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(
					GRAPHIC->MOUSE.X,
					GRAPHIC->MOUSE.Y,
					GRAPHIC->MOUSE.VALUE,
					GRAPHIC->FUNCTION_MOUSE_ARG
				);

			return ;
		}
		case (10): /* NSEventTypeKeyDown */
		case (11): /* NSEventTypeKeyUp */
		case (12): /* NSEventTypeFlagsChanged (AKA: Command, Option etc keys) */
		{
			register NSUInteger	KEY;

			KEY = OBJC(NSUInteger, GRAPHIC->EVENT, "keyCode");

			switch (KEY)
			{ // "switch case" is speed! Wrom wrommmm!!!
				case (0):
				{
					GRAPHIC->KEY.A = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.A)
						GRAPHIC->KEY.DOWN = 65;
					else
						GRAPHIC->KEY.UP = 65;

					break ;
				}
				case (1):
				{
					GRAPHIC->KEY.S = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.S)
						GRAPHIC->KEY.DOWN = 83;
					else
						GRAPHIC->KEY.UP = 83;

					break ;
				}
				case (2):
				{
					GRAPHIC->KEY.D = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.D)
						GRAPHIC->KEY.DOWN = 68;
					else
						GRAPHIC->KEY.UP = 68;

					break ;
				}
				case (3):
				{
					GRAPHIC->KEY.F = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F)
						GRAPHIC->KEY.DOWN = 70;
					else
						GRAPHIC->KEY.UP = 70;

					break ;
				}
				case (4):
				{
					GRAPHIC->KEY.H = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.H)
						GRAPHIC->KEY.DOWN = 72;
					else
						GRAPHIC->KEY.UP = 72;

					break ;
				}
				case (5):
				{
					GRAPHIC->KEY.G = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.G)
						GRAPHIC->KEY.DOWN = 71;
					else
						GRAPHIC->KEY.UP = 71;

					break ;
				}
				case (6):
				{
					GRAPHIC->KEY.Z = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.Z)
						GRAPHIC->KEY.DOWN = 90;
					else
						GRAPHIC->KEY.UP = 90;

					break ;
				}
				case (7):
				{
					GRAPHIC->KEY.X = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.X)
						GRAPHIC->KEY.DOWN = 88;
					else
						GRAPHIC->KEY.UP = 88;

					break ;
				}
				case (8):
				{
					GRAPHIC->KEY.C = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.C)
						GRAPHIC->KEY.DOWN = 67;
					else
						GRAPHIC->KEY.UP = 67;

					break ;
				}
				case (9):
				{
					GRAPHIC->KEY.V = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.V)
						GRAPHIC->KEY.DOWN = 86;
					else
						GRAPHIC->KEY.UP = 86;

					break ;
				}
				case (10):
				{
					GRAPHIC->KEY.SELECTION_SIGN = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.SELECTION_SIGN)
						GRAPHIC->KEY.DOWN = 245;
					else
						GRAPHIC->KEY.UP = 245;

					break ;
				}
				case (11):
				{
					GRAPHIC->KEY.B = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.B)
						GRAPHIC->KEY.DOWN = 66;
					else
						GRAPHIC->KEY.UP = 66;

					break ;
				}
				case (12):
				{
					GRAPHIC->KEY.Q = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.Q)
						GRAPHIC->KEY.DOWN = 81;
					else
						GRAPHIC->KEY.UP = 81;

					break ;
				}
				case (13):
				{
					GRAPHIC->KEY.W = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.W)
						GRAPHIC->KEY.DOWN = 87;
					else
						GRAPHIC->KEY.UP = 87;

					break ;
				}
				case (14):
				{
					GRAPHIC->KEY.E = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.E)
						GRAPHIC->KEY.DOWN = 69;
					else
						GRAPHIC->KEY.UP = 69;

					break ;
				}
				case (15):
				{
					GRAPHIC->KEY.R = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.R)
						GRAPHIC->KEY.DOWN = 82;
					else
						GRAPHIC->KEY.UP = 82;

					break ;
				}
				case (16):
				{
					GRAPHIC->KEY.Y = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.Y)
						GRAPHIC->KEY.DOWN = 89;
					else
						GRAPHIC->KEY.UP = 89;

					break ;
				}
				case (17):
				{
					GRAPHIC->KEY.T = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.T)
						GRAPHIC->KEY.DOWN = 84;
					else
						GRAPHIC->KEY.UP = 84;

					break ;
				}
				case (18):
				{
					GRAPHIC->KEY._1 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._1)
						GRAPHIC->KEY.DOWN = 49;
					else
						GRAPHIC->KEY.UP = 49;

					break ;
				}
				case (19):
				{
					GRAPHIC->KEY._2 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._2)
						GRAPHIC->KEY.DOWN = 50;
					else
						GRAPHIC->KEY.UP = 50;

					break ;
				}
				case (20):
				{
					GRAPHIC->KEY._3 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._3)
						GRAPHIC->KEY.DOWN = 51;
					else
						GRAPHIC->KEY.UP = 51;

					break ;
				}
				case (21):
				{
					GRAPHIC->KEY._4 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._4)
						GRAPHIC->KEY.DOWN = 52;
					else
						GRAPHIC->KEY.UP = 52;

					break ;
				}
				case (22):
				{
					GRAPHIC->KEY._6 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._6)
						GRAPHIC->KEY.DOWN = 54;
					else
						GRAPHIC->KEY.UP = 54;

					break ;
				}
				case (23):
				{
					GRAPHIC->KEY._5 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._5)
						GRAPHIC->KEY.DOWN = 53;
					else
						GRAPHIC->KEY.UP = 53;

					break ;
				}
				case (24):
				{
					GRAPHIC->KEY.EQUAL = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.EQUAL)
						GRAPHIC->KEY.DOWN = 187;
					else
						GRAPHIC->KEY.UP = 187;

					break ;
				}
				case (25):
				{
					GRAPHIC->KEY._9 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._9)
						GRAPHIC->KEY.DOWN = 57;
					else
						GRAPHIC->KEY.UP = 57;

					break ;
				}
				case (26):
				{
					GRAPHIC->KEY._7 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._7)
						GRAPHIC->KEY.DOWN = 55;
					else
						GRAPHIC->KEY.UP = 55;

					break ;
				}
				case (27):
				{
					GRAPHIC->KEY.MINUS = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.MINUS)
						GRAPHIC->KEY.DOWN = 189;
					else
						GRAPHIC->KEY.UP = 189;

					break ;
				}
				case (28):
				{
					GRAPHIC->KEY._8 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._8)
						GRAPHIC->KEY.DOWN = 56;
					else
						GRAPHIC->KEY.UP = 56;

					break ;
				}
				case (29):
				{
					GRAPHIC->KEY._0 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY._0)
						GRAPHIC->KEY.DOWN = 48;
					else
						GRAPHIC->KEY.UP = 48;

					break ;
				}
				case (30):
				{
					GRAPHIC->KEY.RIGHT_BRACKET = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.RIGHT_BRACKET)
						GRAPHIC->KEY.DOWN = 221;
					else
						GRAPHIC->KEY.UP = 221;

					break ;
				}
				case (31):
				{
					GRAPHIC->KEY.O = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.O)
						GRAPHIC->KEY.DOWN = 79;
					else
						GRAPHIC->KEY.UP = 79;

					break ;
				}
				case (32):
				{
					GRAPHIC->KEY.U = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.U)
						GRAPHIC->KEY.DOWN = 85;
					else
						GRAPHIC->KEY.UP = 85;

					break ;
				}
				case (33):
				{
					GRAPHIC->KEY.LEFT_BRACKET = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.LEFT_BRACKET)
						GRAPHIC->KEY.DOWN = 219;
					else
						GRAPHIC->KEY.UP = 219;

					break ;
				}
				case (34):
				{
					GRAPHIC->KEY.I = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.I)
						GRAPHIC->KEY.DOWN = 73;
					else
						GRAPHIC->KEY.UP = 73;

					break ;
				}
				case (35):
				{
					GRAPHIC->KEY.P = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.P)
						GRAPHIC->KEY.DOWN = 80;
					else
						GRAPHIC->KEY.UP = 80;

					break ;
				}
				case (37):
				{
					GRAPHIC->KEY.L = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.L)
						GRAPHIC->KEY.DOWN = 76;
					else
						GRAPHIC->KEY.UP = 76;

					break ;
				}
				case (38):
				{
					GRAPHIC->KEY.J = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.J)
						GRAPHIC->KEY.DOWN = 74;
					else
						GRAPHIC->KEY.UP = 74;

					break ;
				}
				case (39):
				{
					GRAPHIC->KEY.APOSTROPHE = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.APOSTROPHE)
						GRAPHIC->KEY.DOWN = 222;
					else
						GRAPHIC->KEY.UP = 222;

					break ;
				}
				case (40):
				{
					GRAPHIC->KEY.K = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.K)
						GRAPHIC->KEY.DOWN = 75;
					else
						GRAPHIC->KEY.UP = 75;

					break ;
				}
				case (41):
				{
					GRAPHIC->KEY.SEMICOLON = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.SEMICOLON)
						GRAPHIC->KEY.DOWN = 186;
					else
						GRAPHIC->KEY.UP = 186;

					break ;
				}
				case (42):
				{
					GRAPHIC->KEY.BACKSLASH = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.BACKSLASH)
						GRAPHIC->KEY.DOWN = 220;
					else
						GRAPHIC->KEY.UP = 220;

					break ;
				}
				case (43):
				{
					GRAPHIC->KEY.COMMA = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.COMMA)
						GRAPHIC->KEY.DOWN = 188;
					else
						GRAPHIC->KEY.UP = 188;

					break ;
				}
				case (44):
				{
					GRAPHIC->KEY.SLASH = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.SLASH)
						GRAPHIC->KEY.DOWN = 191;
					else
						GRAPHIC->KEY.UP = 191;

					break ;
				}
				case (45):
				{
					GRAPHIC->KEY.N = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.N)
						GRAPHIC->KEY.DOWN = 78;
					else
						GRAPHIC->KEY.UP = 78;

					break ;
				}
				case (46):
				{
					GRAPHIC->KEY.M = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.M)
						GRAPHIC->KEY.DOWN = 77;
					else
						GRAPHIC->KEY.UP = 77;

					break ;
				}
				case (47):
				{
					GRAPHIC->KEY.DOT = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.DOT)
						GRAPHIC->KEY.DOWN = 190;
					else
						GRAPHIC->KEY.UP = 190;

					break ;
				}
				case (48):
				{
					GRAPHIC->KEY.TAB = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.TAB)
						GRAPHIC->KEY.DOWN = 9;
					else
						GRAPHIC->KEY.UP = 9;

					break ;
				}
				case (49):
				{
					GRAPHIC->KEY.SPACEBAR = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.SPACEBAR)
						GRAPHIC->KEY.DOWN = 32;
					else
						GRAPHIC->KEY.UP = 32;

					break ;
				}
				case (50):
				{
					GRAPHIC->KEY.GRAVE = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.GRAVE)
						GRAPHIC->KEY.DOWN = 192;
					else
						GRAPHIC->KEY.UP = 192;

					break ;
				}
				case (51):
				{
					GRAPHIC->KEY.BACKSPACE = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.BACKSPACE)
						GRAPHIC->KEY.DOWN = 8;
					else
						GRAPHIC->KEY.UP = 8;

					break ;
				}
				case (53):
				{
					GRAPHIC->KEY.ESC = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ESC)
						GRAPHIC->KEY.DOWN = 27;
					else
						GRAPHIC->KEY.UP = 27;

					break ;
				}
				case (65):
				{
					GRAPHIC->KEY.DOT = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.DOT)
						GRAPHIC->KEY.DOWN = 190;
					else
						GRAPHIC->KEY.UP = 190;

					break ;
				}
				case (67):
				{
					GRAPHIC->KEY.ASTERISK = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ASTERISK)
						GRAPHIC->KEY.DOWN = 42;
					else
						GRAPHIC->KEY.UP = 42;

					break ;
				}
				case (69):
				{
					GRAPHIC->KEY.PLUS = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.PLUS)
						GRAPHIC->KEY.DOWN = 43;
					else
						GRAPHIC->KEY.UP = 43;

					break ;
				}
				case (75):
				{
					GRAPHIC->KEY.SLASH = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.SLASH)
						GRAPHIC->KEY.DOWN = 191;
					else
						GRAPHIC->KEY.UP = 191;

					break ;
				}
				case (76):
				{
					GRAPHIC->KEY.ENTER = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ENTER)
						GRAPHIC->KEY.DOWN = 10;
					else
						GRAPHIC->KEY.UP = 10;

					break ;
				}
				case (78):
				{
					GRAPHIC->KEY.MINUS = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.MINUS)
						GRAPHIC->KEY.DOWN = 189;
					else
						GRAPHIC->KEY.UP = 189;

					break ;
				}
				case (81):
				{
					GRAPHIC->KEY.EQUAL = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.EQUAL)
						GRAPHIC->KEY.DOWN = 187;
					else
						GRAPHIC->KEY.UP = 187;

					break ;
				}
				case (96):
				{
					GRAPHIC->KEY.F5 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F5)
						GRAPHIC->KEY.DOWN = 116;
					else
						GRAPHIC->KEY.UP = 116;

					break ;
				}
				case (97):
				{
					GRAPHIC->KEY.F6 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F6)
						GRAPHIC->KEY.DOWN = 117;
					else
						GRAPHIC->KEY.UP = 117;

					break ;
				}
				case (98):
				{
					GRAPHIC->KEY.F7 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F7)
						GRAPHIC->KEY.DOWN = 118;
					else
						GRAPHIC->KEY.UP = 118;

					break ;
				}
				case (99):
				{
					GRAPHIC->KEY.F3 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F3)
						GRAPHIC->KEY.DOWN = 114;
					else
						GRAPHIC->KEY.UP = 114;

					break ;
				}
				case (100):
				{
					GRAPHIC->KEY.F8 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F8)
						GRAPHIC->KEY.DOWN = 119;
					else
						GRAPHIC->KEY.UP = 119;

					break ;
				}
				case (101):
				{
					GRAPHIC->KEY.F9 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F9)
						GRAPHIC->KEY.DOWN = 120;
					else
						GRAPHIC->KEY.UP = 120;

					break ;
				}
				case (103):
				{
					GRAPHIC->KEY.F11 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F11)
						GRAPHIC->KEY.DOWN = 122;
					else
						GRAPHIC->KEY.UP = 122;

					break ;
				}
				case (109):
				{
					GRAPHIC->KEY.F10 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F10)
						GRAPHIC->KEY.DOWN = 121;
					else
						GRAPHIC->KEY.UP = 121;

					break ;
				}
				case (111):
				{
					GRAPHIC->KEY.F12 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F12)
						GRAPHIC->KEY.DOWN = 123;
					else
						GRAPHIC->KEY.UP = 123;

					break ;
				}
				case (114):
				{
					GRAPHIC->KEY.HELP = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.HELP)
						GRAPHIC->KEY.DOWN = 47;
					else
						GRAPHIC->KEY.UP = 47;

					break ;
				}
				case (115):
				{
					GRAPHIC->KEY.HOME = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.HOME)
						GRAPHIC->KEY.DOWN = 36;
					else
						GRAPHIC->KEY.UP = 36;

					break ;
				}
				case (116):
				{
					GRAPHIC->KEY.PAGE_UP = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.PAGE_UP)
						GRAPHIC->KEY.DOWN = 33;
					else
						GRAPHIC->KEY.UP = 33;

					break ;
				}
				case (117):
				{
					GRAPHIC->KEY.DEL = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.DEL)
						GRAPHIC->KEY.DOWN = 46;
					else
						GRAPHIC->KEY.UP = 46;

					break ;
				}
				case (118):
				{
					GRAPHIC->KEY.F4 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F4)
						GRAPHIC->KEY.DOWN = 115;
					else
						GRAPHIC->KEY.UP = 115;

					break ;
				}
				case (119):
				{
					GRAPHIC->KEY.END = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.END)
						GRAPHIC->KEY.DOWN = 35;
					else
						GRAPHIC->KEY.UP = 35;

					break ;
				}
				case (120):
				{
					GRAPHIC->KEY.F2 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F2)
						GRAPHIC->KEY.DOWN = 113;
					else
						GRAPHIC->KEY.UP = 113;

					break ;
				}
				case (121):
				{
					GRAPHIC->KEY.PAGE_DOWN = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.PAGE_DOWN)
						GRAPHIC->KEY.DOWN = 34;
					else
						GRAPHIC->KEY.UP = 34;

					break ;
				}
				case (122):
				{
					GRAPHIC->KEY.F1 = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.F1)
						GRAPHIC->KEY.DOWN = 112;
					else
						GRAPHIC->KEY.UP = 112;

					break ;
				}
				case (123):
				{
					GRAPHIC->KEY.ARROW_LEFT = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ARROW_LEFT)
						GRAPHIC->KEY.DOWN = 37;
					else
						GRAPHIC->KEY.UP = 37;

					break ;
				}
				case (124):
				{
					GRAPHIC->KEY.ARROW_RIGHT = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ARROW_RIGHT)
						GRAPHIC->KEY.DOWN = 39;
					else
						GRAPHIC->KEY.UP = 39;

					break ;
				}
				case (125):
				{
					GRAPHIC->KEY.ARROW_DOWN = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ARROW_DOWN)
						GRAPHIC->KEY.DOWN = 40;
					else
						GRAPHIC->KEY.UP = 40;

					break ;
				}
				case (126):
				{
					GRAPHIC->KEY.ARROW_UP = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.ARROW_UP)
						GRAPHIC->KEY.DOWN = 38;
					else
						GRAPHIC->KEY.UP = 38;

					break ;
				}
				case (256):
				{
					GRAPHIC->KEY.CONTROL = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.CONTROL)
						GRAPHIC->KEY.DOWN = KEY;
					else
						GRAPHIC->KEY.UP = KEY;

					break ;
				}
				case (257):
				case (258):
				{
					GRAPHIC->KEY.SHIFT = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.SHIFT)
						GRAPHIC->KEY.DOWN = 16;
					else
						GRAPHIC->KEY.UP = 16;

					break ;
				}
				case (259):
				case (260):
				{
					GRAPHIC->KEY.COMMAND = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.COMMAND)
						GRAPHIC->KEY.DOWN = KEY;
					else
						GRAPHIC->KEY.UP = KEY;

					break ;
				}
				case (261):
				case (262):
				{
					GRAPHIC->KEY.OPTION = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.OPTION)
						GRAPHIC->KEY.DOWN = KEY;
					else
						GRAPHIC->KEY.UP = KEY;

					break ;
				}
				case (272):
				{
					GRAPHIC->KEY.CAPSLOCK = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.CAPSLOCK)
						GRAPHIC->KEY.DOWN = 20;
					else
						GRAPHIC->KEY.UP = 20;

					break ;
				}
				case (279):
				{
					GRAPHIC->KEY.FN = (EVENT_TYPE == 10);

					if (GRAPHIC->KEY.FN)
						GRAPHIC->KEY.DOWN = 0;
					else
						GRAPHIC->KEY.UP = 0;

					break ;
				}
			}

			if (EVENT_TYPE == 10)
			{
				if (!!GRAPHIC->FUNCTION_KEY_DOWN)
				{
					GRAPHIC->FUNCTION_KEY_DOWN(
						GRAPHIC->KEY.DOWN,
						GRAPHIC->FUNCTION_KEY_DOWN_ARG
					);
				}
			}
			else if (!!GRAPHIC->FUNCTION_KEY_UP)
			{
				GRAPHIC->FUNCTION_KEY_UP(
					GRAPHIC->KEY.UP,
					GRAPHIC->FUNCTION_KEY_UP_ARG
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
	IGNORE	OBSERVER;

	((struct GRAPHIC *)ARG)->\
		FUNCTION_LOOP(((struct GRAPHIC *)ARG)->FUNCTION_LOOP_ARG);
		OBJC1(
			void,
			OBJC(
				id,
				((struct GRAPHIC *)ARG)->WINDOW_MODULE,
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
	struct GRAPHIC	*GRAPHIC;
	CGContextRef	CONTEXT;
	CGImageRef		IMAGE;
	id				NSGC;

	GRAPHIC = (struct GRAPHIC *)ARG;
	pthread_mutex_lock(&GRAPHIC->CLOSE_THREAD_MUTEX);
	NSGC = REFRESH_SCREEN("NSGraphicsContext");

	while (!GRAPHIC->CLOSE_THREAD)
	{
		pthread_mutex_unlock(&GRAPHIC->CLOSE_THREAD_MUTEX);
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
			GRAPHIC->WIDTH,
			GRAPHIC->HEIGHT,
			8,
			32,
			(GRAPHIC->WIDTH << 2),
			GRAPHIC->COLOR_SPACE,
			(
				kCGImageAlphaNoneSkipFirst |
				kCGBitmapByteOrder32Little
			),
			GRAPHIC->IMAGE_PROVIDER,
			((void *)0),
			false,
			kCGRenderingIntentDefault
		);

		if (!IMAGE)
		{
			pthread_mutex_lock(&GRAPHIC->CLOSE_THREAD_MUTEX);
			continue ;
		}

		CGContextDrawImage(
			CONTEXT,
			GRAPHIC->CANVAS_INFO,
			IMAGE
		);
		CGImageRelease(IMAGE);
		pthread_mutex_lock(&GRAPHIC->CLOSE_THREAD_MUTEX);
	}

	pthread_mutex_unlock(&GRAPHIC->CLOSE_THREAD_MUTEX);
	return ((void *)0);
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C */
