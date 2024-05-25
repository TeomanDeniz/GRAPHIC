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
# : License - APACHE 2  :: Update - 2024/05/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <objc/objc-runtime.h> /*
#	typedef *SEL;
#	    SEL sel_getUid(const char *);
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	 define YES
v	>>>>>>> (NSApplication)
G	^^^^^^^ *NSApp;
#	typedef BOOL;
#	typedef id;
#	typedef NSUInteger;
#	        */
#	include <CoreGraphics/CoreGraphics.h> /*
#	typedef CGPoint;
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
/* ************************* [^] HELPER MACROS [^] ************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
static int	__GRAPHIC_LOOP__(struct GRAPHIC *GRAPHIC);
/* *************************** [^] PROTOTYPES [^] *************************** */
int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	if (!!GRAPHIC->FUNCTION_LOOP)
	{
		while (!__GRAPHIC_LOOP__(GRAPHIC))
			GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);
	}
	else
		while (!__GRAPHIC_LOOP__(GRAPHIC));
}

static int
	__GRAPHIC_LOOP__(struct GRAPHIC *GRAPHIC)
{
	NSUInteger (EVENT_TYPE);
	id              (EVENT);

	MSG1(\
		void, \
		MSG(\
			id, \
			GRAPHIC->WINDOW_MODULE, \
			"contentView"\
		), \
		"setNeedsDisplay:", \
		BOOL, \
		YES\
	);
	EVENT = MSG4(\
		id, \
		NSApp, \
		"nextEventMatchingMask:untilDate:inMode:dequeue:", \
		NSUInteger, \
		NSUIntegerMax, \
		id, \
		NULL, \
		id, \
		NSDefaultRunLoopMode, \
		BOOL, \
		YES\
	);

	if (!EVENT)
		return (-1);

	EVENT_TYPE = MSG(NSUInteger, EVENT, "type");
	GRAPHIC->MOUSE.LEFT_UP = 0;
	GRAPHIC->MOUSE.RIGHT_UP = 0;
	GRAPHIC->MOUSE.VALUE = 0;
	GRAPHIC->MOUSE.MIDDLE_UP = 0;
	GRAPHIC->MOUSE.WHEEL = 0;
	GRAPHIC->MOUSE.HORIZANTAL_WHELL = 0;

	if (EVENT_TYPE == 1) /* NSEventTypeLeftMouseDown */
		GRAPHIC->MOUSE |= 1;
	else if (EVENT_TYPE == 2) /* NSEventTypeLeftMouseUp*/
		GRAPHIC->MOUSE &= ~1;
	else if (\
		EVENT_TYPE == 5 || /* NSEventTypeMouseMoved */\
		EVENT_TYPE == 6 /* NSEventTypeLeftMouseDragged */\
	)
	{
		register CGPoint (X_AND_Y);

		X_AND_Y = MSG(CGPoint, EVENT, "locationInWindow");
		GRAPHIC->MOUSE.X = (int)X_AND_Y.x;
		GRAPHIC->MOUSE.Y = (GRAPHIC->HEIGHT - (int)X_AND_Y.y);

		if (!!GRAPHIC->FUNCTION_MOUSE)
			GRAPHIC->FUNCTION_MOUSE(\
				GRAPHIC->X, \
				GRAPHIC->Y, \
				GRAPHIC->MOUSE.VALUE, \
				GRAPHIC->FUNCTION_MOUSE_ARG\
			);

		return (0);
	}
	else if (EVENT_TYPE == 10 /* NSEventTypeKeyDown */ \
		|| EVENT_TYPE == 11 /* NSEventTypeKeyUp */ \
		|| EVENT_TYPE == 12 /* SPECIAL KEY */)
	{
		register NSUInteger (KEY);

		KEY = MSG(NSUInteger, EVENT, "keyCode");
		switch (KEY)
		{ // "switch case" is speed! Wrom wrommmm!!!
			case 0:
				GRAPHIC->KEY.A = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 65;
				else
					GRAPHIC->KEY.UP = 65;
				break ;
			case 1:
				GRAPHIC->KEY.S = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 83;
				else
					GRAPHIC->KEY.UP = 83;
				break ;
			case 2:
				GRAPHIC->KEY.D = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 68;
				else
					GRAPHIC->KEY.UP = 68;
				break ;
			case 3:
				GRAPHIC->KEY.F = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 70;
				else
					GRAPHIC->KEY.UP = 70;
				break ;
			case 4:
				GRAPHIC->KEY.H = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 72;
				else
					GRAPHIC->KEY.UP = 72;
				break ;
			case 5:
				GRAPHIC->KEY.G = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 71;
				else
					GRAPHIC->KEY.UP = 71;
				break ;
			case 6:
				GRAPHIC->KEY.Z = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 90;
				else
					GRAPHIC->KEY.UP = 90;
				break ;
			case 7:
				GRAPHIC->KEY.X = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 88;
				else
					GRAPHIC->KEY.UP = 88;
				break ;
			case 8:
				GRAPHIC->KEY.C = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 67;
				else
					GRAPHIC->KEY.UP = 67;
				break ;
			case 9:
				GRAPHIC->KEY.V = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 86;
				else
					GRAPHIC->KEY.UP = 86;
				break ;
			case 10:
				GRAPHIC->KEY.SELECTION_SIGN = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 245;
				else
					GRAPHIC->KEY.UP = 245;
				break ;
			case 11:
				GRAPHIC->KEY.B = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 66;
				else
					GRAPHIC->KEY.UP = 66;
				break ;
			case 12:
				GRAPHIC->KEY.Q = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 81;
				else
					GRAPHIC->KEY.UP = 81;
				break ;
			case 13:
				GRAPHIC->KEY.W = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 87;
				else
					GRAPHIC->KEY.UP = 87;
				break ;
			case 14:
				GRAPHIC->KEY.E = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 69;
				else
					GRAPHIC->KEY.UP = 69;
				break ;
			case 15:
				GRAPHIC->KEY.R = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 82;
				else
					GRAPHIC->KEY.UP = 82;
				break ;
			case 16:
				GRAPHIC->KEY.Y = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 89;
				else
					GRAPHIC->KEY.UP = 89;
				break ;
			case 17:
				GRAPHIC->KEY.T = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 84;
				else
					GRAPHIC->KEY.UP = 84;
				break ;
			case 18:
				GRAPHIC->KEY._1 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 49;
				else
					GRAPHIC->KEY.UP = 49;
				break ;
			case 19:
				GRAPHIC->KEY._2 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 50;
				else
					GRAPHIC->KEY.UP = 50;
				break ;
			case 20:
				GRAPHIC->KEY._3 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 51;
				else
					GRAPHIC->KEY.UP = 51;
				break ;
			case 21:
				GRAPHIC->KEY._4 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 52;
				else
					GRAPHIC->KEY.UP = 52;
				break ;
			case 22:
				GRAPHIC->KEY._6 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 54;
				else
					GRAPHIC->KEY.UP = 54;
				break ;
			case 23:
				GRAPHIC->KEY._5 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 53;
				else
					GRAPHIC->KEY.UP = 53;
				break ;
			case 24:
				GRAPHIC->KEY.EQUAL = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 187;
				else
					GRAPHIC->KEY.UP = 187;
				break ;
			case 25:
				GRAPHIC->KEY._9 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 57;
				else
					GRAPHIC->KEY.UP = 57;
				break ;
			case 26:
				GRAPHIC->KEY._7 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 55;
				else
					GRAPHIC->KEY.UP = 55;
				break ;
			case 27:
				GRAPHIC->KEY.MINUS = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 189;
				else
					GRAPHIC->KEY.UP = 189;
				break ;
			case 28:
				GRAPHIC->KEY._8 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 56;
				else
					GRAPHIC->KEY.UP = 56;
				break ;
			case 29:
				GRAPHIC->KEY._0 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 48;
				else
					GRAPHIC->KEY.UP = 48;
				break ;
			case 30:
				GRAPHIC->KEY.RIGHT_BRACKET = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 221;
				else
					GRAPHIC->KEY.UP = 221;
				break ;
			case 31:
				GRAPHIC->KEY.O = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 79;
				else
					GRAPHIC->KEY.UP = 79;
				break ;
			case 32:
				GRAPHIC->KEY.U = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 85;
				else
					GRAPHIC->KEY.UP = 85;
				break ;
			case 33:
				GRAPHIC->KEY.LEFT_BRACKET = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 219;
				else
					GRAPHIC->KEY.UP = 219;
				break ;
			case 34:
				GRAPHIC->KEY.I = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 73;
				else
					GRAPHIC->KEY.UP = 73;
				break ;
			case 35:
				GRAPHIC->KEY.P = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 80;
				else
					GRAPHIC->KEY.UP = 80;
				break ;
			case 37:
				GRAPHIC->KEY.L = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 76;
				else
					GRAPHIC->KEY.UP = 76;
				break ;
			case 38:
				GRAPHIC->KEY.J = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 74;
				else
					GRAPHIC->KEY.UP = 74;
				break ;
			case 39:
				GRAPHIC->KEY.APOSTROPHE = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 222;
				else
					GRAPHIC->KEY.UP = 222;
				break ;
			case 40:
				GRAPHIC->KEY.K = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 75;
				else
					GRAPHIC->KEY.UP = 75;
				break ;
			case 41:
				GRAPHIC->KEY.SEMICOLON = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 186;
				else
					GRAPHIC->KEY.UP = 186;
				break ;
			case 42:
				GRAPHIC->KEY.BACKSLASH = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 220;
				else
					GRAPHIC->KEY.UP = 220;
				break ;
			case 43:
				GRAPHIC->KEY.COMMA = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 188;
				else
					GRAPHIC->KEY.UP = 188;
				break ;
			case 44:
				GRAPHIC->KEY.SLASH = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 191;
				else
					GRAPHIC->KEY.UP = 191;
				break ;
			case 45:
				GRAPHIC->KEY.N = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 78;
				else
					GRAPHIC->KEY.UP = 78;
				break ;
			case 46:
				GRAPHIC->KEY.M = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 77;
				else
					GRAPHIC->KEY.UP = 77;
				break ;
			case 47:
				GRAPHIC->KEY.DOT = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 190;
				else
					GRAPHIC->KEY.UP = 190;
				break ;
			case 48:
				GRAPHIC->KEY.TAB = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 9;
				else
					GRAPHIC->KEY.UP = 9;
				break ;
			case 49:
				GRAPHIC->KEY.SPACEBAR = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 32;
				else
					GRAPHIC->KEY.UP = 32;
				break ;
			case 50:
				GRAPHIC->KEY.GRAVE = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 192;
				else
					GRAPHIC->KEY.UP = 192;
				break ;
			case 51:
				GRAPHIC->KEY.BACKSPACE = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 8;
				else
					GRAPHIC->KEY.UP = 8;
				break ;
			case 53:
				GRAPHIC->KEY.ESC = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 27;
				else
					GRAPHIC->KEY.UP = 27;
				break ;
			case 65:
				GRAPHIC->KEY.DOT = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 190;
				else
					GRAPHIC->KEY.UP = 190;
				break ;
			case 67:
				GRAPHIC->KEY.ASTERISK = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 42;
				else
					GRAPHIC->KEY.UP = 42;
				break ;
			case 69:
				GRAPHIC->KEY.PLUS = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 43;
				else
					GRAPHIC->KEY.UP = 43;
				break ;
			case 75:
				GRAPHIC->KEY.SLASH = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 191;
				else
					GRAPHIC->KEY.UP = 191;
				break ;
			case 76:
				GRAPHIC->KEY.ENTER = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 10;
				else
					GRAPHIC->KEY.UP = 10;
				break ;
			case 78:
				GRAPHIC->KEY.MINUS = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 189;
				else
					GRAPHIC->KEY.UP = 189;
				break ;
			case 81:
				GRAPHIC->KEY.EQUAL = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 187;
				else
					GRAPHIC->KEY.UP = 187;
				break ;
			case 96:
				GRAPHIC->KEY.F5 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 116;
				else
					GRAPHIC->KEY.UP = 116;
				break ;
			case 97:
				GRAPHIC->KEY.F6 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 117;
				else
					GRAPHIC->KEY.UP = 117;
				break ;
			case 98:
				GRAPHIC->KEY.F7 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 118;
				else
					GRAPHIC->KEY.UP = 118;
				break ;
			case 99:
				GRAPHIC->KEY.F3 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 114;
				else
					GRAPHIC->KEY.UP = 114;
				break ;
			case 100:
				GRAPHIC->KEY.F8 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 119;
				else
					GRAPHIC->KEY.UP = 119;
				break ;
			case 101:
				GRAPHIC->KEY.F9 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 120;
				else
					GRAPHIC->KEY.UP = 120;
				break ;
			case 103:
				GRAPHIC->KEY.F11 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 122;
				else
					GRAPHIC->KEY.UP = 122;
				break ;
			case 109:
				GRAPHIC->KEY.F10 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 121;
				else
					GRAPHIC->KEY.UP = 121;
				break ;
			case 111:
				GRAPHIC->KEY.F12 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 123;
				else
					GRAPHIC->KEY.UP = 123;
				break ;
			case 114:
				GRAPHIC->KEY.HELP = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 47;
				else
					GRAPHIC->KEY.UP = 47;
				break ;
			case 115:
				GRAPHIC->KEY.HOME = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 36;
				else
					GRAPHIC->KEY.UP = 36;
				break ;
			case 116:
				GRAPHIC->KEY.PAGE_UP = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 33;
				else
					GRAPHIC->KEY.UP = 33;
				break ;
			case 117:
				GRAPHIC->KEY.DEL = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 46;
				else
					GRAPHIC->KEY.UP = 46;
				break ;
			case 118:
				GRAPHIC->KEY.F4 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 115;
				else
					GRAPHIC->KEY.UP = 115;
				break ;
			case 119:
				GRAPHIC->KEY.END = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 35;
				else
					GRAPHIC->KEY.UP = 35;
				break ;
			case 120:
				GRAPHIC->KEY.F2 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 113;
				else
					GRAPHIC->KEY.UP = 113;
				break ;
			case 121:
				GRAPHIC->KEY.PAGE_DOWN = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 34;
				else
					GRAPHIC->KEY.UP = 34;
				break ;
			case 122:
				GRAPHIC->KEY.F1 = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 112;
				else
					GRAPHIC->KEY.UP = 112;
				break ;
			case 123:
				GRAPHIC->KEY.ARROW_LEFT = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 37;
				else
					GRAPHIC->KEY.UP = 37;
				break ;
			case 124:
				GRAPHIC->KEY.ARROW_RIGHT = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 39;
				else
					GRAPHIC->KEY.UP = 39;
				break ;
			case 125:
				GRAPHIC->KEY.ARROW_DOWN = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 40;
				else
					GRAPHIC->KEY.UP = 40;
				break ;
			case 126:
				GRAPHIC->KEY.ARROW_UP = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 38;
				else
					GRAPHIC->KEY.UP = 38;
				break ;
			case 256:
				GRAPHIC->KEY.CONTROL = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = KEY;
				else
					GRAPHIC->KEY.UP = KEY;
				break ;
			case 257:
			case 258:
				GRAPHIC->KEY.SHIFT = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 16;
				else
					GRAPHIC->KEY.UP = 16;
				break ;
			case 259:
			case 260:
				GRAPHIC->KEY.COMMAND = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = KEY;
				else
					GRAPHIC->KEY.UP = KEY;
				break ;
			case 261:
			case 262:
				GRAPHIC->KEY.OPTION = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = KEY;
				else
					GRAPHIC->KEY.UP = KEY;
				break ;
			case 272:
				GRAPHIC->KEY.CAPSLOCK = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 20;
				else
					GRAPHIC->KEY.UP = 20;
				break ;
			case 279:
				GRAPHIC->KEY.FN = (EVENT_TYPE == 10);
				if (EVENT_TYPE == 10)
					GRAPHIC->KEY.DOWN = 0;
				else
					GRAPHIC->KEY.UP = 0;
				break ;
		}

		if (EVENT_TYPE == 10)
			if (!!GRAPHIC->FUNCTION_KEY_DOWN)
				GRAPHIC->FUNCTION_KEY_DOWN(GRAPHIC->KEY.DOWN, \
					GRAPHIC->FUNCTION_KEY_DOWN_ARG);
		else if (!!GRAPHIC->FUNCTION_KEY_UP)
			GRAPHIC->FUNCTION_KEY_UP(GRAPHIC->KEY.UP, \
				GRAPHIC->FUNCTION_KEY_UP_ARG);

		return (0);
	} /* EVENT_TYPE == 10 || EVENT_TYPE == 11 */

	MSG1(void, NSApp, "sendEvent:", id, EVENT);
	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H */
