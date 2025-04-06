/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/APP_LOOP__X11       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/06 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <X11/Xlib.h> /*
#	typedef XEvent;
#	    int XPutImage(Display *, Drawable, GC, XImage *, int, int, int, int,
>	        uint, uint);
#	    int XFlush(Display *);
#	    int XPending(Display *);
#	    int XNextEvent(Display *, XEvent *);
#	   Atom XInternAtom(Display *, char *, Bool);
#	    int XCloseDisplay(Display *);
#	        */
#	include <X11/XKBlib.h> /*
#	 KeySym XkbKeycodeToKeysym(Display *, [kc], int, int);
#	        */
#	include <X11/keysym.h> /* [>] <X11/keysymdef.h>	 */
#	include <X11/keysymdef.h> /*
#	 define XK_BackSpace   #	 define XK_Delete
#	 define XK_Down        #	 define XK_End
#	 define XK_Escape      #	 define XK_Home
#	 define XK_Insert      #	 define XK_Left
#	 define XK_Page_Down   #	 define XK_Page_Up
#	 define XK_Return      #	 define XK_Right
#	 define XK_Tab         #	 define XK_Up
#	 define XK_apostrophe  #	 define XK_backslash
#	 define XK_bracketleft #	 define XK_bracketright
#	 define XK_comma       #	 define XK_equal
#	 define XK_grave       #	 define XK_minus
#	 define XK_period      #	 define XK_semicolon
#	 define XK_slash       #	 define XK_space
#	 define XK_asterisk    #	 define XK_plus
#	 define XK_a           #	 define XK_b
#	 define XK_c           #	 define XK_d
#	 define XK_e           #	 define XK_f
#	 define XK_g           #	 define XK_h
#	 define XK_i           #	 define XK_j
#	 define XK_k           #	 define XK_l
#	 define XK_m           #	 define XK_n
#	 define XK_o           #	 define XK_p
#	 define XK_q           #	 define XK_r
#	 define XK_s           #	 define XK_t
#	 define XK_u           #	 define XK_v
#	 define XK_w           #	 define XK_x
#	 define XK_y           #	 define XK_z
#	 define XK_0           #	 define XK_1
#	 define XK_2           #	 define XK_3
#	 define XK_4           #	 define XK_5
#	 define XK_6           #	 define XK_7
#	 define XK_8           #	 define XK_9
#	 define XK_section
#	        */
#	include <stdlib.h> /*
#	   void free(void *);
#	        */
#	include <unistd.h> /*
#	    int usleep(useconds_t);
#	        */
#	include <time.h> /*
#	 define CLOCK_MONOTONIC
#	 struct timespec;
#	    int clock_gettime(clockid_t, struct timespec *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] MACROS [v] ***************************** */
#	ifndef Button6
#		define Button6 6
#	endif /* !Button6 */
#	ifndef Button7
#		define Button7 7
#	endif /* !Button7 */
/* ***************************** [^] MACROS [^] ***************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static int	__APP_LOOP__(struct S_APP *const APP);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	APP_LOOP(struct S_APP *APP)
{
	int	RESULT;
	int	FRAME_TIME_LIMITER;

	RESULT = 0;

	if (APP-> FPS > 0)
		FRAME_TIME_LIMITER = (1000000 / APP->FPS);
	else
		FRAME_TIME_LIMITER = 0;

	if (!!APP->FUNCTION_LOOP)
	{
		while (!__APP_LOOP__(APP) && !RESULT)
		{
			struct timespec	START_TIMER;
			struct timespec	END_TIMER;
			register long	ELAPSED;

			clock_gettime(CLOCK_MONOTONIC, &START_TIMER);
			RESULT = APP->FUNCTION_LOOP(APP->FUNCTION_LOOP_ARG);
			clock_gettime(CLOCK_MONOTONIC, &END_TIMER);
			ELAPSED = (
				(END_TIMER.tv_sec - START_TIMER.tv_sec) * 1000000L + 
				(END_TIMER.tv_nsec - START_TIMER.tv_nsec) / 1000
			);

			if (ELAPSED < FRAME_TIME_LIMITER)
				usleep(FRAME_TIME_LIMITER - ELAPSED);
		}
	}
	else
	{
		while (!__APP_LOOP__(APP))
			usleep(FRAME_TIME_LIMITER);
	}

	return (RESULT);
}

static int
	__APP_LOOP__(struct S_APP *const APP)
{
	XEvent	EVENT;

	if (!APP->DISPLAY || !APP->XWINDOW || !APP->IMAGE)
		return (1);

	XPutImage(
		APP->DISPLAY,
		APP->XWINDOW,
		APP->GRAPHICS_CONTEXT,
		APP->IMAGE,
		0,
		0,
		0,
		0,
		APP->WIDTH,
		APP->HEIGHT
	);
	XFlush(APP->DISPLAY);

	while (XPending(APP->DISPLAY))
	{
		APP->MOUSE.LEFT_UP = 0;
		APP->MOUSE.RIGHT_UP = 0;
		APP->MOUSE.VALUE = 0;
		APP->MOUSE.MIDDLE_UP = 0;
		APP->MOUSE.WHEEL = 0;
		APP->MOUSE.HORIZANTAL_WHEEL = 0;
		XNextEvent(APP->DISPLAY, &EVENT);

		if (EVENT.type == ButtonPress)
		{
			switch (EVENT.xbutton.button)
			{ // "switch case" is speed! Wrom wrommmm!!!
				case (Button1):
				{
					APP->MOUSE.LEFT_DOWN = 1;
					APP->MOUSE.VALUE = 1;
					break ;
				}
				case (Button2):
				{
					APP->MOUSE.MIDDLE_DOWN = 1;
					APP->MOUSE.VALUE = 3;
					break ;
				}
				case (Button3):
				{
					APP->MOUSE.RIGHT_DOWN = 1;
					APP->MOUSE.VALUE = 2;
					break ;
				}
				case (Button4):
				{
					APP->MOUSE.WHEEL = -1;
					APP->MOUSE.VALUE = 4;
					break ;
				}
				case (Button5):
				{
					APP->MOUSE.WHEEL = 1;
					APP->MOUSE.VALUE = 5;
					break ;
				}
				case (Button6):
				{
					APP->MOUSE.HORIZANTAL_WHEEL = -1;
					APP->MOUSE.VALUE = 6;
					break ;
				}
				case (Button7):
				{
					APP->MOUSE.HORIZANTAL_WHEEL = 1;
					APP->MOUSE.VALUE = 7;
					break ;
				}
			}

			if (!!APP->FUNCTION_MOUSE)
			{
				APP->FUNCTION_MOUSE(
					APP->MOUSE.X,
					APP->MOUSE.Y,
					APP->MOUSE.VALUE,
					APP->FUNCTION_MOUSE_ARG
				);
			}
		}
		else if (EVENT.type == ButtonRelease)
		{
			if (EVENT.xbutton.button == Button1)
			{
				APP->MOUSE.LEFT_DOWN = 0;
				APP->MOUSE.LEFT_UP = 1;
			}
			else if (EVENT.xbutton.button == Button2)
			{
				APP->MOUSE.MIDDLE_DOWN = 0;
				APP->MOUSE.MIDDLE_UP = 1;
			}
			else if (EVENT.xbutton.button == Button3)
			{
				APP->MOUSE.RIGHT_DOWN = 0;
				APP->MOUSE.RIGHT_UP = 1;
			}

			if (!!APP->FUNCTION_MOUSE)
			{
				APP->FUNCTION_MOUSE(
					APP->MOUSE.X,
					APP->MOUSE.Y,
					APP->MOUSE.VALUE,
					APP->FUNCTION_MOUSE_ARG
				);
			}
		}
		else if (EVENT.type == ClientMessage)
		{
			if (
				(Atom)EVENT.xclient.data.l[0] ==
				XInternAtom(APP->DISPLAY, "WM_DELETE_WINDOW", 0)
			)
			{
				if (!APP->FUNCTION_CLOSE)
				{
					XCloseDisplay(APP->DISPLAY);

					if (!!APP->BUFFER)
					{
						free(APP->BUFFER);
						APP->BUFFER = ((void *)0);
					}
				}
				else
					APP->FUNCTION_CLOSE(APP->FUNCTION_CLOSE_ARG);
			}
		}
		else if (EVENT.type == MotionNotify)
		{
			APP->MOUSE.X = EVENT.xmotion.x;
			APP->MOUSE.Y = EVENT.xmotion.y;

			if (!!APP->FUNCTION_MOUSE)
			{
				APP->FUNCTION_MOUSE(
					APP->MOUSE.X,
					APP->MOUSE.Y,
					APP->MOUSE.VALUE,
					APP->FUNCTION_MOUSE_ARG
				);
			}
		}
		else if (EVENT.type == KeyPress || EVENT.type == KeyRelease)
		{
			register int	KEY;

			KEY = XkbKeycodeToKeysym(
				APP->DISPLAY,
				EVENT.xkey.keycode,
				0,
				0
			);

			switch (KEY) // "switch case" is speed! Wrom wrommmm!!!
			{ // https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
				case (XK_BackSpace):
				{
					APP->KEY.BACKSPACE = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 8;
					else
						APP->KEY.UP = 8;

					break ;
				}
				case (XK_Delete):
				{
					APP->KEY.DEL = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 127;
					else
						APP->KEY.UP = 127;

					break ;
				}
				case (XK_Down):
				{
					APP->KEY.ARROW_DOWN = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 18;
					else
						APP->KEY.UP = 18;

					break ;
				}
				case (XK_End):
				{
					APP->KEY.END = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 5;
					else
						APP->KEY.UP = 5;

					break ;
				}
				case (XK_Escape):
				{
					APP->KEY.ESC = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 27;
					else
						APP->KEY.UP = 27;

					break ;
				}
				case (XK_Home):
				{
					APP->KEY.HOME = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 2;
					else
						APP->KEY.UP = 2;

					break ;
				}
				case (XK_Insert):
				{
					APP->KEY.INSERT = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 26;
					else
						APP->KEY.UP = 26;

					break ;
				}
				case (XK_Left):
				{
					APP->KEY.ARROW_LEFT = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 20;
					else
						APP->KEY.UP = 20;

					break ;
				}
				case (XK_Page_Down):
				{
					APP->KEY.PAGE_DOWN = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 4;
					else
						APP->KEY.UP = 4;

					break ;
				}
				case (XK_Page_Up):
				{
					APP->KEY.PAGE_UP = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 3;
					else
						APP->KEY.UP = 3;

					break ;
				}
				case (XK_Return):
				{
					APP->KEY.ENTER = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 10;
					else
						APP->KEY.UP = 10;

					break ;
				}
				case (XK_Right):
				{
					APP->KEY.ARROW_RIGHT = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 19;
					else
						APP->KEY.UP = 19;

					break ;
				}
				case (XK_Tab):
				{
					APP->KEY.TAB = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 9;
					else
						APP->KEY.UP = 9;

					break ;
				}
				case (XK_Up):
				{
					APP->KEY.ARROW_UP = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 17;
					else
						APP->KEY.UP = 17;

					break ;
				}
				case (XK_apostrophe):
				{
					APP->KEY.APOSTROPHE = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 39;
					else
						APP->KEY.UP = 39;

					break ;
				}
				case (XK_backslash):
				{
					APP->KEY.BACKSLASH = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 92;
					else
						APP->KEY.UP = 92;

					break ;
				}
				case (XK_bracketleft):
				{
					APP->KEY.LEFT_BRACKET = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 91;
					else
						APP->KEY.UP = 91;

					break ;
				}
				case (XK_bracketright):
				{
					APP->KEY.RIGHT_BRACKET = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 93;
					else
						APP->KEY.UP = 93;

					break ;
				}
				case (XK_comma):
				{
					APP->KEY.COMMA = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 44;
					else
						APP->KEY.UP = 44;

					break ;
				}
				case (XK_equal):
				{
					APP->KEY.EQUAL = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 61;
					else
						APP->KEY.UP = 61;

					break ;
				}
				case (XK_grave):
				{
					APP->KEY.GRAVE = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 96;
					else
						APP->KEY.UP = 96;

					break ;
				}
				case (XK_minus):
				{
					APP->KEY.MINUS = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 45;
					else
						APP->KEY.UP = 45;

					break ;
				}
				case (XK_period):
				{
					APP->KEY.DOT = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 46;
					else
						APP->KEY.UP = 46;

					break ;
				}
				case (XK_semicolon):
				{
					APP->KEY.SEMICOLON = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 59;
					else
						APP->KEY.UP = 59;

					break ;
				}
				case (XK_slash):
				{
					APP->KEY.SLASH = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 47;
					else
						APP->KEY.UP = 47;

					break ;
				}
				case (XK_space):
				{
					APP->KEY.SPACEBAR = (EVENT.type == KeyPress);
					APP->KEY.SPACE = APP->KEY.SPACEBAR;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 32;
					else
						APP->KEY.UP = 32;

					break ;
				}
				case (XK_asterisk):
				{
					APP->KEY.ASTERISK = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 42;
					else
						APP->KEY.UP = 42;

					break ;
				}
				case (XK_plus):
				{
					APP->KEY.PLUS = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 43;
					else
						APP->KEY.UP = 43;

					break ;
				}
				case (XK_a):
				{
					APP->KEY.A = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 65;
					else
						APP->KEY.UP = 65;

					break ;
				}
				case (XK_b):
				{
					APP->KEY.B = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 66;
					else
						APP->KEY.UP = 66;

					break ;
				}
				case (XK_c):
				{
					APP->KEY.C = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 67;
					else
						APP->KEY.UP = 67;

					break ;
				}
				case (XK_d):
				{
					APP->KEY.D = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 68;
					else
						APP->KEY.UP = 68;

					break ;
				}
				case (XK_e):
				{
					APP->KEY.E = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 69;
					else
						APP->KEY.UP = 69;

					break ;
				}
				case (XK_f):
				{
					APP->KEY.F = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 70;
					else
						APP->KEY.UP = 70;

					break ;
				}
				case (XK_g):
				{
					APP->KEY.G = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 71;
					else
						APP->KEY.UP = 71;

					break ;
				}
				case (XK_h):
				{
					APP->KEY.H = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 72;
					else
						APP->KEY.UP = 72;

					break ;
				}
				case (XK_i):
				{
					APP->KEY.I = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 73;
					else
						APP->KEY.UP = 73;

					break ;
				}
				case (XK_j):
				{
					APP->KEY.J = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 74;
					else
						APP->KEY.UP = 74;

					break ;
				}
				case (XK_k):
				{
					APP->KEY.K = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 75;
					else
						APP->KEY.UP = 75;

					break ;
				}
				case (XK_l):
				{
					APP->KEY.L = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 76;
					else
						APP->KEY.UP = 76;

					break ;
				}
				case (XK_m):
				{
					APP->KEY.M = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 77;
					else
						APP->KEY.UP = 77;

					break ;
				}
				case (XK_n):
				{
					APP->KEY.N = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 78;
					else
						APP->KEY.UP = 78;

					break ;
				}
				case (XK_o):
				{
					APP->KEY.O = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 79;
					else
						APP->KEY.UP = 79;

					break ;
				}
				case (XK_p):
				{
					APP->KEY.P = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 80;
					else
						APP->KEY.UP = 80;

					break ;
				}
				case (XK_q):
				{
					APP->KEY.Q = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 81;
					else
						APP->KEY.UP = 81;

					break ;
				}
				case (XK_r):
				{
					APP->KEY.R = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 82;
					else
						APP->KEY.UP = 82;

					break ;
				}
				case (XK_s):
				{
					APP->KEY.S = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 83;
					else
						APP->KEY.UP = 83;

					break ;
				}
				case (XK_t):
				{
					APP->KEY.T = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 84;
					else
						APP->KEY.UP = 84;

					break ;
				}
				case (XK_u):
				{
					APP->KEY.U = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 85;
					else
						APP->KEY.UP = 85;

					break ;
				}
				case (XK_v):
				{
					APP->KEY.V = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 86;
					else
						APP->KEY.UP = 86;

					break ;
				}
				case (XK_w):
				{
					APP->KEY.W = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 87;
					else
						APP->KEY.UP = 87;

					break ;
				}
				case (XK_x):
				{
					APP->KEY.X = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 88;
					else
						APP->KEY.UP = 88;

					break ;
				}
				case (XK_y):
				{
					APP->KEY.Y = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 89;
					else
						APP->KEY.UP = 89;

					break ;
				}
				case (XK_z):
				{
					APP->KEY.Z = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 90;
					else
						APP->KEY.UP = 90;

					break ;
				}
				case (XK_0):
				{
					APP->KEY._0 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 48;
					else
						APP->KEY.UP = 48;

					break ;
				}
				case (XK_1):
				{
					APP->KEY._1 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 49;
					else
						APP->KEY.UP = 49;

					break ;
				}
				case (XK_2):
				{
					APP->KEY._2 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 50;
					else
						APP->KEY.UP = 50;

					break ;
				}
				case (XK_3):
				{
					APP->KEY._3 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 51;
					else
						APP->KEY.UP = 51;

					break ;
				}
				case (XK_4):
				{
					APP->KEY._4 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 52;
					else
						APP->KEY.UP = 52;

					break ;
				}
				case (XK_5):
				{
					APP->KEY._5 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 53;
					else
						APP->KEY.UP = 53;

					break ;
				}
				case (XK_6):
				{
					APP->KEY._6 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 54;
					else
						APP->KEY.UP = 54;

					break ;
				}
				case (XK_7):
				{
					APP->KEY._7 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 55;
					else
						APP->KEY.UP = 55;

					break ;
				}
				case (XK_8):
				{
					APP->KEY._8 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 56;
					else
						APP->KEY.UP = 56;

					break ;
				}
				case (XK_9):
				{
					APP->KEY._9 = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 57;
					else
						APP->KEY.UP = 57;

					break ;
				}
				case (XK_section):
				{
					APP->KEY.SELECTION_SIGN = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 245;
					else
						APP->KEY.UP = 245;

					break ;
				}
				case (XK_Shift_L):
				{
					APP->KEY.SHIFT = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 16;
					else
						APP->KEY.UP = 16;

					break ;
				}
				case (XK_Shift_R):
				{
					APP->KEY.SHIFT = (EVENT.type == KeyPress);

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 16;
					else
						APP->KEY.UP = 16;

					break ;
				}
				case (XK_Control_L):
				{
					APP->KEY.CONTROL = (EVENT.type == KeyPress);
					APP->KEY.CTRL = APP->KEY.CONTROL;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 17;
					else
						APP->KEY.UP = 17;

					break ;
				}
				case (XK_Control_R):
				{
					APP->KEY.CONTROL = (EVENT.type == KeyPress);
					APP->KEY.CTRL = APP->KEY.CONTROL;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 17;
					else
						APP->KEY.UP = 17;

					break ;
				}
				case (XK_Alt_L):
				{
					APP->KEY.OPTION = (EVENT.type == KeyPress);
					APP->KEY.ALT = APP->KEY.OPTION;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 18;
					else
						APP->KEY.UP = 18;

					break ;
				}
				case (XK_Alt_R):
				{
					APP->KEY.OPTION = (EVENT.type == KeyPress);
					APP->KEY.ALT = APP->KEY.OPTION;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 18;
					else
						APP->KEY.UP = 18;

					break ;
				}
				case (XK_Meta_L):
				{
					APP->KEY.OPTION = (EVENT.type == KeyPress);
					APP->KEY.ALT = APP->KEY.OPTION;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 18;
					else
						APP->KEY.UP = 18;

					break ;
				}
				case (XK_Meta_R):
				{
					APP->KEY.OPTION = (EVENT.type == KeyPress);
					APP->KEY.ALT = APP->KEY.OPTION;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 18;
					else
						APP->KEY.UP = 18;

					break ;
				}
				case (XK_Super_L):
				{
					APP->KEY.COMMAND = (EVENT.type == KeyPress);
					APP->KEY.WIN = APP->KEY.COMMAND;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 91;
					else
						APP->KEY.UP = 91;

					break ;
				}
				case (XK_Super_R):
				{
					APP->KEY.COMMAND = (EVENT.type == KeyPress);
					APP->KEY.WIN = APP->KEY.COMMAND;

					if (EVENT.type == KeyPress)
						APP->KEY.DOWN = 91;
					else
						APP->KEY.UP = 91;

					break ;
				}
			}

			if (EVENT.type == KeyPress)
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
		}
	}

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_APP_LOOP_C */
