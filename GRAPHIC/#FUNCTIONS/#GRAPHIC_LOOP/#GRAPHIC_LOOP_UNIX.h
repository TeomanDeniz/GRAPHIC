/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP_UNIX       #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
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
/* **************************** [^] INCLUDES [^] **************************** */
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
	return (0);
}

static int
	__GRAPHIC_LOOP__(struct GRAPHIC *GRAPHIC)
{
	XEvent (EVENT);

	XPutImage(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, GRAPHIC->GRAPHICS_CONTEXT, \
		GRAPHIC->IMAGE, 0, 0, 0, 0, GRAPHIC->WIDTH, GRAPHIC->HEIGHT);
	XFlush(GRAPHIC->DISPLAY);
	while (XPending(GRAPHIC->DISPLAY))
	{
		GRAPHIC->MOUSE.LEFT_UP = 0;
		GRAPHIC->MOUSE.RIGHT_UP = 0;
		GRAPHIC->MOUSE.VALUE = 0;
		GRAPHIC->MOUSE.MIDDLE_UP = 0;
		GRAPHIC->MOUSE.WHEEL = 0;
		GRAPHIC->MOUSE.HORIZANTAL_WHEEL = 0;
		XNextEvent(GRAPHIC->DISPLAY, &EVENT);
		if (EVENT.type == ButtonPress)
		{
			switch (EVENT.xbutton.button)
			{ // "switch case" is speed! Wrom wrommmm!!!
				case (Button1):
				{
					GRAPHIC->MOUSE.LEFT_DOWN = 1;
					GRAPHIC->MOSUE.VALUE = 1;
					break ;
				}
				case (Button2):
				{
					GRAPHIC->MOUSE.MIDDLE_DOWN = 1;
					GRAPHIC->MOSUE.VALUE = 3;
					break ;
				}
				case (Button3):
				{
					GRAPHIC->MOUSE.RIGHT_DOWN = 1;
					GRAPHIC->MOSUE.VALUE = 2;
					break ;
				}
				case (Button4):
				{
					GRAPHIC->MOUSE.WHEEL = -1;
					GRAPHIC->MOSUE.VALUE = 4;
					break ;
				}
				case (Button5):
				{
					GRAPHIC->MOUSE.WHEEL = 1;
					GRAPHIC->MOSUE.VALUE = 5;
					break ;
				}
				case (Button6):
				{
					GRAPHIC->MOUSE.HORIZANTAL_WHEEL = -1;
					GRAPHIC->MOSUE.VALUE = 6;
					break ;
				}
				case (Button7):
				{
					GRAPHIC->MOUSE.HORIZANTAL_WHEEL = 1;
					GRAPHIC->MOSUE.VALUE = 7;
					break ;
				}
			}

			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->X, \
					GRAPHIC->Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
		}
		else if (EVENT.type == ButtonRelease)
		{
			if (EVENT.xbutton.button == Button1)
			{
				GRAPHIC->MOUSE.LEFT_DOWN = 0;
				GRAPHIC->MOUSE.LEFT_UP = 1;
			}
			else if (EVENT.xbutton.button == Button2)
			{
				GRAPHIC->MOUSE.MIDDLE_DOWN = 0;
				GRAPHIC->MOUSE.MIDDLE_UP = 1;
			}
			else if (EVENT.xbutton.button == Button3)
			{
				GRAPHIC->MOUSE.RIGHT_DOWN = 0;
				GRAPHIC->MOUSE.RIGHT_UP = 1;
			}

			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->X, \
					GRAPHIC->Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
		}
		else if (EVENT.type == ClientMessage)
		{
			if (EVENT.xclient.data.l[0] == \
				XInternAtom(GRAPHIC->DISPLAY, "WM_DELETE_WINDOW", False))
			{
				if (!GRAPHIC->FUNCTION_CLOSE)
				{
					XCloseDisplay(GRAPHIC->DISPLAY);

					if (!!GRAPHIC->BUFFER)
					{
						free(GRAPHIC->BUFFER);
						GRAPHIC->BUFFER = ((void *)0);
					}
				}
				else
					GRAPHIC->FUNCTION_CLOSE(GRAPHIC->FUNCTION_CLOSE_ARG);
			}
		}
		else if (EVENT.type == MotionNotify)
		{
			GRAPHIC->MOUSE.X = EVENT.xmotion.x;
			GRAPHIC->MOUSE.Y = EVENT.xmotion.y;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->X, \
					GRAPHIC->Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
		}
		else if (EVENT.type == KeyPress || EVENT.type == KeyRelease)
		{
			register int (KEY_MODE);
			register int      (KEY);

			KEY_MODE = EVENT.xkey.state;
			KEY = XkbKeycodeToKeysym(GRAPHIC->DISPLAY, \
				EVENT.xkey.keycode, 0, 0);
			GRAPHIC->KEY.CTRL = !!(KEY_MODE & ControlMask);
			GRAPHIC->KEY.SHIFT = !!(KEY_MODE & ShiftMask);
			GRAPHIC->KEY.ALT = !!(KEY_MODE & Mod1Mask);
			GRAPHIC->KEY.COMMAND = !!(KEY_MODE & Mod4Mask);
			switch (KEY) // "switch case" is speed! Wrom wrommmm!!!
			{ // https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
				case XK_BackSpace:
					GRAPHIC->KEY.BACKSPACE = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 8;
					else
						GRAPHIC->KEY.UP = 8;
					break ;
				case XK_Delete:
					GRAPHIC->KEY.DEL = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 127;
					else
						GRAPHIC->KEY.UP = 127;
					break ;
				case XK_Down:
					GRAPHIC->KEY.ARROW_DOWN = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 18;
					else
						GRAPHIC->KEY.UP = 18;
					break ;
				case XK_End:
					GRAPHIC->KEY.END = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 5;
					else
						GRAPHIC->KEY.UP = 5;
					break ;
				case XK_Escape:
					GRAPHIC->KEY.ESC = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 27;
					else
						GRAPHIC->KEY.UP = 27;
					break ;
				case XK_Home:
					GRAPHIC->KEY.HOME = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 2;
					else
						GRAPHIC->KEY.UP = 2;
					break ;
				case XK_Insert:
					GRAPHIC->KEY.INSERT = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 26;
					else
						GRAPHIC->KEY.UP = 26;
					break ;
				case XK_Left:
					GRAPHIC->KEY.ARROW_LEFT = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 20;
					else
						GRAPHIC->KEY.UP = 20;
					break ;
				case XK_Page_Down:
					GRAPHIC->KEY.PAGE_DOWN = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 4;
					else
						GRAPHIC->KEY.UP = 4;
					break ;
				case XK_Page_Up:
					GRAPHIC->KEY.PAGE_UP = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 3;
					else
						GRAPHIC->KEY.UP = 3;
					break ;
				case XK_Return:
					GRAPHIC->KEY.ENTER = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 10;
					else
						GRAPHIC->KEY.UP = 10;
					break ;
				case XK_Right:
					GRAPHIC->KEY.ARROW_RIGHT = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 19;
					else
						GRAPHIC->KEY.UP = 19;
					break ;
				case XK_Tab:
					GRAPHIC->KEY.TAB = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 9;
					else
						GRAPHIC->KEY.UP = 9;
					break ;
				case XK_Up:
					GRAPHIC->KEY.ARROW_UP = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 17;
					else
						GRAPHIC->KEY.UP = 17;
					break ;
				case XK_apostrophe:
					GRAPHIC->KEY.APOSTROPHE = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 39;
					else
						GRAPHIC->KEY.UP = 39;
					break ;
				case XK_backslash:
					GRAPHIC->KEY.BACKSLASH = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 92;
					else
						GRAPHIC->KEY.UP = 92;
					break ;
				case XK_bracketleft:
					GRAPHIC->KEY.LEFT_BRACKET = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 91;
					else
						GRAPHIC->KEY.UP = 91;
					break ;
				case XK_bracketright:
					GRAPHIC->KEY.RIGHT_BRACKET = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 93;
					else
						GRAPHIC->KEY.UP = 93;
					break ;
				case XK_comma:
					GRAPHIC->KEY.COMMA = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 44;
					else
						GRAPHIC->KEY.UP = 44;
					break ;
				case XK_equal:
					GRAPHIC->KEY.EQUAL = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 61;
					else
						GRAPHIC->KEY.UP = 61;
					break ;
				case XK_grave:
					GRAPHIC->KEY.GRAVE = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 96;
					else
						GRAPHIC->KEY.UP = 96;
					break ;
				case XK_minus:
					GRAPHIC->KEY.MINUS = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 45;
					else
						GRAPHIC->KEY.UP = 45;
					break ;
				case XK_period:
					GRAPHIC->KEY.DOT = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 46;
					else
						GRAPHIC->KEY.UP = 46;
					break ;
				case XK_semicolon:
					GRAPHIC->KEY.SEMICOLON = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 59;
					else
						GRAPHIC->KEY.UP = 59;
					break ;
				case XK_slash:
					GRAPHIC->KEY.SLASH = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 47;
					else
						GRAPHIC->KEY.UP = 47;
					break ;
				case XK_space:
					GRAPHIC->KEY.SPACEBAR = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 32;
					else
						GRAPHIC->KEY.UP = 32;
					break ;
				case XK_asterisk:
					GRAPHIC->KEY.ASTERISK = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 42;
					else
						GRAPHIC->KEY.UP = 42;
					break ;
				case XK_plus:
					GRAPHIC->KEY.PLUS = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 43;
					else
						GRAPHIC->KEY.UP = 43;
					break ;
				case XK_a:
					GRAPHIC->KEY.A = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 65;
					else
						GRAPHIC->KEY.UP = 65;
					break ;
				case XK_b:
					GRAPHIC->KEY.B = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 66;
					else
						GRAPHIC->KEY.UP = 66;
					break ;
				case XK_c:
					GRAPHIC->KEY.C = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 67;
					else
						GRAPHIC->KEY.UP = 67;
					break ;
				case XK_d:
					GRAPHIC->KEY.D = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 68;
					else
						GRAPHIC->KEY.UP = 68;
					break ;
				case XK_e:
					GRAPHIC->KEY.E = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 69;
					else
						GRAPHIC->KEY.UP = 69;
					break ;
				case XK_f:
					GRAPHIC->KEY.F = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 70;
					else
						GRAPHIC->KEY.UP = 70;
					break ;
				case XK_g:
					GRAPHIC->KEY.G = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 71;
					else
						GRAPHIC->KEY.UP = 71;
					break ;
				case XK_h:
					GRAPHIC->KEY.H = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 72;
					else
						GRAPHIC->KEY.UP = 72;
					break ;
				case XK_i:
					GRAPHIC->KEY.I = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 73;
					else
						GRAPHIC->KEY.UP = 73;
					break ;
				case XK_j:
					GRAPHIC->KEY.J = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 74;
					else
						GRAPHIC->KEY.UP = 74;
					break ;
				case XK_k:
					GRAPHIC->KEY.K = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 75;
					else
						GRAPHIC->KEY.UP = 75;
					break ;
				case XK_l:
					GRAPHIC->KEY.L = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 76;
					else
						GRAPHIC->KEY.UP = 76;
					break ;
				case XK_m:
					GRAPHIC->KEY.M = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 77;
					else
						GRAPHIC->KEY.UP = 77;
					break ;
				case XK_n:
					GRAPHIC->KEY.N = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 78;
					else
						GRAPHIC->KEY.UP = 78;
					break ;
				case XK_o:
					GRAPHIC->KEY.O = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 79;
					else
						GRAPHIC->KEY.UP = 79;
					break ;
				case XK_p:
					GRAPHIC->KEY.P = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 80;
					else
						GRAPHIC->KEY.UP = 80;
					break ;
				case XK_q:
					GRAPHIC->KEY.Q = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 81;
					else
						GRAPHIC->KEY.UP = 81;
					break ;
				case XK_r:
					GRAPHIC->KEY.R = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 82;
					else
						GRAPHIC->KEY.UP = 82;
					break ;
				case XK_s:
					GRAPHIC->KEY.S = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 83;
					else
						GRAPHIC->KEY.UP = 83;
					break ;
				case XK_t:
					GRAPHIC->KEY.T = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 84;
					else
						GRAPHIC->KEY.UP = 84;
					break ;
				case XK_u:
					GRAPHIC->KEY.U = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 85;
					else
						GRAPHIC->KEY.UP = 85;
					break ;
				case XK_v:
					GRAPHIC->KEY.V = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 86;
					else
						GRAPHIC->KEY.UP = 86;
					break ;
				case XK_w:
					GRAPHIC->KEY.W = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 87;
					else
						GRAPHIC->KEY.UP = 87;
					break ;
				case XK_x:
					GRAPHIC->KEY.X = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 88;
					else
						GRAPHIC->KEY.UP = 88;
					break ;
				case XK_y:
					GRAPHIC->KEY.Y = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 89;
					else
						GRAPHIC->KEY.UP = 89;
					break ;
				case XK_z:
					GRAPHIC->KEY.Z = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 90;
					else
						GRAPHIC->KEY.UP = 90;
					break ;
				case XK_0:
					GRAPHIC->KEY._0 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 48;
					else
						GRAPHIC->KEY.UP = 48;
					break ;
				case XK_1:
					GRAPHIC->KEY._1 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 49;
					else
						GRAPHIC->KEY.UP = 49;
					break ;
				case XK_2:
					GRAPHIC->KEY._2 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 50;
					else
						GRAPHIC->KEY.UP = 50;
					break ;
				case XK_3:
					GRAPHIC->KEY._3 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 51;
					else
						GRAPHIC->KEY.UP = 51;
					break ;
				case XK_4:
					GRAPHIC->KEY._4 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 52;
					else
						GRAPHIC->KEY.UP = 52;
					break ;
				case XK_5:
					GRAPHIC->KEY._5 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 53;
					else
						GRAPHIC->KEY.UP = 53;
					break ;
				case XK_6:
					GRAPHIC->KEY._6 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 54;
					else
						GRAPHIC->KEY.UP = 54;
					break ;
				case XK_7:
					GRAPHIC->KEY._7 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 55;
					else
						GRAPHIC->KEY.UP = 55;
					break ;
				case XK_8:
					GRAPHIC->KEY._8 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 56;
					else
						GRAPHIC->KEY.UP = 56;
					break ;
				case XK_9:
					GRAPHIC->KEY._9 = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 57;
					else
						GRAPHIC->KEY.UP = 57;
					break ;
				case XK_section:
					GRAPHIC->KEY.SELECTION_SIGN = (EVENT.type == KeyPress);
					if (EVENT_TYPE == 10)
						GRAPHIC->KEY.DOWN = 245;
					else
						GRAPHIC->KEY.UP = 245;
					break ;
			}
			if (EVENT.type == KeyPress)
				if (!!GRAPHIC->FUNCTION_KEY_DOWN)
					GRAPHIC->FUNCTION_KEY_DOWN(GRAPHIC->KEY.DOWN, \
						GRAPHIC->FUNCTION_KEY_DOWN_ARG);
			else if (!!GRAPHIC->FUNCTION_KEY_UP)
				GRAPHIC->FUNCTION_KEY_UP(GRAPHIC->KEY.UP, \
					GRAPHIC->FUNCTION_KEY_UP_ARG);
		}
	}

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_C */
