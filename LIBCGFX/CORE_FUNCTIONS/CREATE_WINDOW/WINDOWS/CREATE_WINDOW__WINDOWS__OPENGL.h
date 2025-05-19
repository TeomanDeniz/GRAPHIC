/******************************************************************************\
# H - CREATE_WINDOW__WINDOWS__OPENGL             #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../../LIBCGFX.h" /*
#	 struct S_APP;
#	   void CLOSE_WINDOW(struct S_APP *);
#	   void SET_CURSOR(struct S_APP *, uchar);
#	        */
#	include "../../../../LIBCMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *, uint);
#	        */
#	include "../../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include <windef.h> /*
#	 define CALLBACK
#	 define HWND
#	 define HDC
#	 define HBITMAP
#	 define HIWORD(l)
#	 define LOWORD(l)
#	typedef LRESULT;
#	typedef UINT;
#	typedef WPARAM;
#	typedef LPARAM;
#	typedef HINSTANCE;
#	typedef LONG_PTR;
#	typedef DWORD;
#	typedef LONG;
#	typedef WORD;
#	        */
#	include <wingdi.h> /*	
#	 define PFD_DRAW_TO_WINDOW
#	 define PFD_SUPPORT_OPENGL
#	 define PFD_DOUBLEBUFFER
#	 define PFD_TYPE_RGBA
#	 define PFD_MAIN_PLANE
#	typedef PIXELFORMATDESCRIPTOR;
#	   BOOL SetPixelFormat(HDC, int, PIXELFORMATDESCRIPTOR *);
#	    int ChoosePixelFormat(HDC, PIXELFORMATDESCRIPTOR *);
#	   BOOL wglMakeCurrent(HDC, HGLRC);
#	  HGLRC wglCreateContext(HDC);
#	        */
#	include <winuser.h> /*
#	 define GetWindowLongPtr(hWnd, nIndex)
#	 define SetWindowLongPtr(hWnd, nIndex, dwNewLong)
#	 define DefWindowProc(hWnd, Msg, wParam, lParam)
#	 define CS_VREDRAW
#	 define CS_HREDRAW
#	 define SW_SHOW
#	 define SW_HIDE
#	 define WM_PAINT
#	 define WM_CLOSE
#	 define WM_LBUTTONDOWN
#	 define WM_LBUTTONUP
#	 define WM_MOUSEMOVE
#	 define WM_KEYDOWN
#	 define WM_KEYUP
#	 define WM_DESTROY
#	 define WS_EX_LAYERED
#	 define WS_EX_TOPMOST
#	 define WS_EX_CLIENTEDGE
#	 define WS_EX_TOOLWINDOW
#	 define WS_BORDER
#	 define WS_SIZEBOX
#	 define WS_MINIMIZEBOX
#	 define WS_MAXIMIZEBOX
#	 define WS_SYSMENU
#	 define WS_TABSTOP
#	 define WM_TIMER
#	 define WM_ENTERSIZEMOVE
#	 define WM_EXITSIZEMOVE
#	 define WM_SIZE
#	 define SWP_NOSIZE
#	 define SWP_NOMOVE
#	 define SWP_FRAMECHANGED
#	 define GWLP_USERDATA
#	 define SIZE_MINIMIZED
#	typedef RECT;
#	typedef WNDCLASSEX;
#	   void RegisterClassEx(WNDCLASSEX *);
#	   HWND CreateWindowEx(DWORD, LPCTSTR, LPCTSTR, DWORD, int, int, int, int, 
>	        	HWND, HMENU, HINSTANCE, LPVOID);
#	   BOOL ShowWindow(HWND, int);
#	   BOOL UpdateWindow(HWND);
#	   BOOL DestroyWindow(HWND);
#	   void PostQuitMessage(int);
#	   BOOL SetWindowPos(HWND, HWND, int, int, int, int, UINT);
#	   BOOL InvalidateRect(HWND, LPCRECT, BOOL);
#	        */
#	include <stdlib.h> /*
#	typedef size_t;
#	        */
#	include <winbase.h> /*
#	 define GetModuleHandle
#	        */
#	include <gl/GL.h> /*
#	 define GL_DEPTH_TEST
#	 define GL_TEXTURE_2D
#	 define GL_PROJECTION
#	 define GL_MODELVIEW
#	   void glEnable(GLenum);
#	   void glViewport(GLint, GLint, GLsizei, GLsizei);
#	   void glMatrixMode(GLenum);
#	   void glLoadIdentity();
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern void				*memset(void *, int, size_t);
static LRESULT CALLBACK	APP_WINDOW_PROCESS_HANDLE(\
	const HWND WINDOW_HANDLE,
	const UINT MSG,
	const WPARAM W_PARAM,
	const LPARAM L_PARAM
);
extern void				REFRESH_SCREEN(const struct S_APP *const APP);
extern int				IDLE_FUNCTION(void *ARG);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	CREATE_WINDOW(
	struct S_APP *APP,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
{
	HDC						HANDLE_DEVICE_CONTEXT;
	PIXELFORMATDESCRIPTOR	PIXEL_FORMAT_DESCRIPTOR;
	RECT					WINDOW_RECTANGLE = {0, 0, WIDTH, HEIGHT};
	WNDCLASSEX				WINDOW_CLASS;
	register HINSTANCE		HANDLE_INSTANCE;
	register DWORD			WINDOW_STYLE;
	register DWORD			EXTENDED_WINDOW_STYLE;

	if (!APP || !APP->WINDOW.TITLE)
		return (-1);

	APP->BUFFER = (unsigned int *)0;

	if (!APP->FUNCTION_LOOP)
		APP->FUNCTION_LOOP = IDLE_FUNCTION;

	if (!APP->FUNCTION_RESIZE)
		APP->FUNCTION_RESIZE = IDLE_FUNCTION;

	APP->WINDOW.WIDTH = WIDTH;
	APP->WINDOW.HEIGHT = HEIGHT;
	APP->WIDTH = WIDTH;
	APP->HEIGHT = HEIGHT;
	HANDLE_INSTANCE = GetModuleHandle((void *)0);
	WINDOW_STYLE = WS_OVERLAPPEDWINDOW;
	EXTENDED_WINDOW_STYLE = WS_EX_CLIENTEDGE;
	WINDOW_CLASS = (WNDCLASSEX){0};
	WINDOW_CLASS.cbSize = sizeof(WNDCLASSEX);
	WINDOW_CLASS.style = CS_VREDRAW | CS_HREDRAW;
	WINDOW_CLASS.lpfnWndProc = APP_WINDOW_PROCESS_HANDLE;
	WINDOW_CLASS.hInstance = HANDLE_INSTANCE;
	WINDOW_CLASS.lpszClassName = APP->WINDOW.TITLE;
	WINDOW_CLASS.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	RegisterClassEx(&WINDOW_CLASS);

	if (APP->WINDOW.TRANSPARENCY)
	{
		WINDOW_STYLE |= WS_POPUP;
		EXTENDED_WINDOW_STYLE |= WS_EX_LAYERED;
		//EXTENDED_WINDOW_STYLE |= WS_EX_TRANSPARENT;
	}

	if (APP->WINDOW.TOPMOST)
		EXTENDED_WINDOW_STYLE |= WS_EX_TOPMOST;

	if (APP->WINDOW.CLIENTEDGE)
		EXTENDED_WINDOW_STYLE |= WS_EX_CLIENTEDGE;

	if (APP->WINDOW.TOOLWINDOW)
		EXTENDED_WINDOW_STYLE |= WS_EX_TOOLWINDOW;

	if (!APP->WINDOW.BORDER)
	{
		WINDOW_STYLE &= ~WS_BORDER;
		WINDOW_STYLE &= ~WS_CAPTION;
	}
	else
	{
		WINDOW_STYLE |= WS_BORDER;
		WINDOW_STYLE |= WS_CAPTION;
	}

	if (!APP->WINDOW.RESIZABLE)
		WINDOW_STYLE &= ~WS_SIZEBOX;
	else
		WINDOW_STYLE |= WS_SIZEBOX;

	if (!APP->WINDOW.MINIMIZABLE)
		WINDOW_STYLE &= ~WS_MINIMIZEBOX;
	else
		WINDOW_STYLE |= WS_MINIMIZEBOX;

	if (!APP->WINDOW.MAXIMIZABLE)
		WINDOW_STYLE &= ~WS_MAXIMIZEBOX;
	else
		WINDOW_STYLE |= WS_MAXIMIZEBOX;

	if (!APP->WINDOW.CLOSEBUTTON)
		WINDOW_STYLE &= ~WS_SYSMENU;
	else
		WINDOW_STYLE |= WS_SYSMENU;

	if (!APP->WINDOW.FOCUSABLE)
		WINDOW_STYLE &= ~WS_TABSTOP;
	else
		WINDOW_STYLE |= WS_TABSTOP;

	AdjustWindowRectEx(
		&WINDOW_RECTANGLE,
		WINDOW_STYLE,
		0,
		EXTENDED_WINDOW_STYLE
	);

	APP->WINDOW_HANDLE = CreateWindowEx(
		EXTENDED_WINDOW_STYLE,
		APP->WINDOW.TITLE,
		APP->WINDOW.TITLE,
		WINDOW_STYLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(WINDOW_RECTANGLE.right - WINDOW_RECTANGLE.left),
		(WINDOW_RECTANGLE.bottom - WINDOW_RECTANGLE.top),
		((void *)0),
		((void *)0),
		HANDLE_INSTANCE,
		((void *)0)
	);

	if (!APP->WINDOW_HANDLE)
		return (-1);

	if (
		SetWindowLongPtr(
			APP->WINDOW_HANDLE,
			GWLP_USERDATA,
			(LONG_PTR)APP
		)
	)
	{
		DestroyWindow(APP->WINDOW_HANDLE);
		APP->WINDOW_HANDLE = ((void *)0);
		return (-3);
	}

	SetWindowPos(
		APP->WINDOW_HANDLE, 
		NULL,
		0,
		0,
		0,
		0, 
		SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED
	);

	PIXEL_FORMAT_DESCRIPTOR.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	PIXEL_FORMAT_DESCRIPTOR.nVersion = 1;
	PIXEL_FORMAT_DESCRIPTOR.dwFlags =
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	PIXEL_FORMAT_DESCRIPTOR.iPixelType = PFD_TYPE_RGBA;
	PIXEL_FORMAT_DESCRIPTOR.cColorBits = 32;
	PIXEL_FORMAT_DESCRIPTOR.cRedBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cRedShift = 0;
	PIXEL_FORMAT_DESCRIPTOR.cGreenBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cGreenShift = 0;
	PIXEL_FORMAT_DESCRIPTOR.cBlueBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cBlueShift = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAlphaBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAlphaShift = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAccumBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAccumRedBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAccumGreenBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAccumBlueBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cAccumAlphaBits = 0;
	PIXEL_FORMAT_DESCRIPTOR.cDepthBits = 24;
	PIXEL_FORMAT_DESCRIPTOR.cStencilBits = 8;
	PIXEL_FORMAT_DESCRIPTOR.cAuxBuffers = 0;
	PIXEL_FORMAT_DESCRIPTOR.iLayerType = PFD_MAIN_PLANE;
	PIXEL_FORMAT_DESCRIPTOR.bReserved = 0;
	PIXEL_FORMAT_DESCRIPTOR.dwLayerMask = 0;
	PIXEL_FORMAT_DESCRIPTOR.dwVisibleMask = 0;
	PIXEL_FORMAT_DESCRIPTOR.dwDamageMask = 0;
	HANDLE_DEVICE_CONTEXT = GetDC(APP->WINDOW_HANDLE);
	SetPixelFormat(
		HANDLE_DEVICE_CONTEXT,
		ChoosePixelFormat(
			HANDLE_DEVICE_CONTEXT,
			&PIXEL_FORMAT_DESCRIPTOR
		),
		&PIXEL_FORMAT_DESCRIPTOR
	);
	wglMakeCurrent(
		HANDLE_DEVICE_CONTEXT,
		wglCreateContext(HANDLE_DEVICE_CONTEXT)
	);

	if (APP->WINDOW.HIDEONCREATE)
		ShowWindow(APP->WINDOW_HANDLE, SW_HIDE);
	else
		ShowWindow(APP->WINDOW_HANDLE, SW_SHOW);

	UpdateWindow(APP->WINDOW_HANDLE);
	APP->REFRESH_SCREEN = (REFRESH_SCREEN);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glViewport(0, 0, APP->WIDTH, APP->HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	return (0);
}

extern void
	REFRESH_SCREEN(const struct S_APP *const APP)
{
	IGNORE_VAR	APP;
}

static LRESULT CALLBACK
	APP_WINDOW_PROCESS_HANDLE(
	const HWND WINDOW_HANDLE,
	const UINT MSG,
	const WPARAM W_PARAM,
	const LPARAM L_PARAM
)
{
	struct S_APP	*APP;

	APP = (struct S_APP *)GetWindowLongPtr(WINDOW_HANDLE, GWLP_USERDATA);

	if (!APP)
		return (1);

	{
		register unsigned char	CURSOR;

		CURSOR = APP->MOUSE.CURSOR;
		memset(&APP->MOUSE, 0, sizeof(APP->MOUSE));
		APP->MOUSE.CURSOR = CURSOR;
	}

	switch (MSG)
	{ // "switch case" is speed! Wrom wrommmm!!!
		case (WM_TIMER):
		{
			if (!APP->WINDOW.TRANSPARENCY)
				InvalidateRect(WINDOW_HANDLE, ((void *)0), 1);

			UpdateWindow(WINDOW_HANDLE);

			if (APP->WINDOW.TRANSPARENCY)
			{
				if (!APP->WINDOW_RESIZING)
					APP->FUNCTION_LOOP(APP->FUNCTION_LOOP_ARG);
			}
			else
				APP->FUNCTION_LOOP(APP->FUNCTION_LOOP_ARG);

			if (!APP->WINDOW_HANDLE)
				PostQuitMessage(0);

			break ;
		}
		case (WM_ENTERSIZEMOVE):
		{
			APP->WINDOW_RESIZING = 1;
			break ;
		}
		case (WM_EXITSIZEMOVE):
		{
			APP->WINDOW_RESIZING = 0;
			break ;
		}
		case (WM_SIZE):
		{
			if (W_PARAM != SIZE_MINIMIZED)
			{
				APP->WINDOW.WIDTH = LOWORD(L_PARAM);
				APP->WINDOW.HEIGHT = HIWORD(L_PARAM);
				APP->WIDTH = APP->WINDOW.WIDTH;
				APP->HEIGHT = APP->WINDOW.HEIGHT;

				glViewport(0, 0, APP->WIDTH, APP->HEIGHT);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();

				APP->FUNCTION_RESIZE(APP->FUNCTION_RESIZE_ARG);

				if (APP->WINDOW.TRANSPARENCY)
					APP->FUNCTION_LOOP(APP->FUNCTION_LOOP_ARG);
				else
					InvalidateRect(WINDOW_HANDLE, ((void *)0), 1);

				glMatrixMode(GL_MODELVIEW);
				UpdateWindow(WINDOW_HANDLE);
			}

			break ;
		}
		case (WM_DESTROY): // 0X0002
		{
			PostQuitMessage(0);
			break ;
		}
		case (WM_CLOSE): // CLICKING "X" BUTTON // 0X0010
		{
			if (!!APP->FUNCTION_CLOSE)
				APP->FUNCTION_CLOSE(APP->FUNCTION_CLOSE_ARG);
			else
				CLOSE_WINDOW(APP);

			break ;
		}
		case (WM_KEYDOWN): // 0X0100
		case (WM_KEYUP): // 0X0101
		{
			register unsigned char (KEY);

			KEY = (unsigned char)W_PARAM;

			switch (KEY)
			{
				case (8):
				{
					APP->KEY.BACKSPACE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (9):
				{
					APP->KEY.TAB = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (13):
				{
					APP->KEY.ENTER = !((L_PARAM >> 31) & 1);
					KEY = 10;
					break ;
				}
				case (16):
				{
					APP->KEY.SHIFT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (17):
				{
					APP->KEY.CTRL = !((L_PARAM >> 31) & 1);
					APP->KEY.CONTROL = APP->KEY.CTRL;
					break ;
				}
				case (18):
				{
					APP->KEY.ALT = !((L_PARAM >> 31) & 1);
					APP->KEY.OPTION = APP->KEY.ALT;
					break ;
				}
				case (19):
				{
					APP->KEY.PAUSE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (20):
				{
					APP->KEY.CAPSLOCK = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (27):
				{
					APP->KEY.ESC = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (32):
				{
					APP->KEY.SPACEBAR = !((L_PARAM >> 31) & 1);
					APP->KEY.SPACE = APP->KEY.SPACEBAR;
					break ;
				}
				case (33):
				{
					APP->KEY.PAGE_UP = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (34):
				{
					APP->KEY.PAGE_DOWN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (35):
				{
					APP->KEY.END = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (36):
				{
					APP->KEY.HOME = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (37):
				{
					APP->KEY.ARROW_LEFT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (38):
				{
					APP->KEY.ARROW_UP = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (39):
				{
					APP->KEY.ARROW_RIGHT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (40):
				{
					APP->KEY.ARROW_DOWN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (44):
				{
					APP->KEY.PRTSC = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (45):
				{
					APP->KEY.INSERT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (46):
				{
					APP->KEY.DEL = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (47):
				{
					APP->KEY.HELP = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (48):
				{
					APP->KEY._0 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (49):
				{
					APP->KEY._1 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (50):
				{
					APP->KEY._2 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (51):
				{
					APP->KEY._3 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (52):
				{
					APP->KEY._4 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (53):
				{
					APP->KEY._5 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (54):
				{
					APP->KEY._6 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (55):
				{
					APP->KEY._7 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (56):
				{
					APP->KEY._8 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (57):
				{
					APP->KEY._9 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (65):
				{
					APP->KEY.A = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (66):
				{
					APP->KEY.B = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (67):
				{
					APP->KEY.C = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (68):
				{
					APP->KEY.D = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (69):
				{
					APP->KEY.E = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (70):
				{
					APP->KEY.F = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (71):
				{
					APP->KEY.G = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (72):
				{
					APP->KEY.H = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (73):
				{
					APP->KEY.I = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (74):
				{
					APP->KEY.J = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (75):
				{
					APP->KEY.K = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (76):
				{
					APP->KEY.L = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (77):
				{
					APP->KEY.M = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (78):
				{
					APP->KEY.N = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (79):
				{
					APP->KEY.O = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (80):
				{
					APP->KEY.P = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (81):
				{
					APP->KEY.Q = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (82):
				{
					APP->KEY.R = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (83):
				{
					APP->KEY.S = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (84):
				{
					APP->KEY.T = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (85):
				{
					APP->KEY.U = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (86):
				{
					APP->KEY.V = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (87):
				{
					APP->KEY.W = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (88):
				{
					APP->KEY.X = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (89):
				{
					APP->KEY.Y = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (90):
				{
					APP->KEY.Z = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (91):
				{
					APP->KEY.WIN = !((L_PARAM >> 31) & 1);
					APP->KEY.COMMAND = APP->KEY.WIN;
					break ;
				}
				case (92):
				{
					APP->KEY.WIN = !((L_PARAM >> 31) & 1);
					APP->KEY.COMMAND = APP->KEY.WIN;
					break ;
				}
				case (112):
				{
					APP->KEY.F1 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (113):
				{
					APP->KEY.F2 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (114):
				{
					APP->KEY.F3 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (115):
				{
					APP->KEY.F4 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (116):
				{
					APP->KEY.F5 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (117):
				{
					APP->KEY.F6 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (118):
				{
					APP->KEY.F7 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (119):
				{
					APP->KEY.F8 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (120):
				{
					APP->KEY.F9 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (121):
				{
					APP->KEY.F10 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (122):
				{
					APP->KEY.F11 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (123):
				{
					APP->KEY.F12 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (186):
				{
					APP->KEY.SEMICOLON = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (187):
				{
					APP->KEY.EQUAL = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (188):
				{
					APP->KEY.COMMA = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (189):
				{
					APP->KEY.MINUS = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (190):
				{
					APP->KEY.DOT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (191):
				{
					APP->KEY.SLASH = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (192):
				{
					APP->KEY.GRAVE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (219):
				{
					APP->KEY.LEFT_BRACKET = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (220):
				{
					APP->KEY.BACKSLASH = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (221):
				{
					APP->KEY.RIGHT_BRACKET = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (222):
				{
					APP->KEY.APOSTROPHE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (223):
				{
					APP->KEY.SELECTION_SIGN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (226):
				{
					APP->KEY.SELECTION_SIGN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (255):
				{
					APP->KEY.FN = !((L_PARAM >> 31) & 1);
					break ;
				}
			}

			if (APP->KEY.DOWN)
				APP->KEY.DOWN = 0;

			if (APP->KEY.UP)
				APP->KEY.UP = 0;

			if (MSG == WM_KEYDOWN)
			{
				APP->KEY.DOWN = KEY;
				if (!!APP->FUNCTION_KEY_DOWN)
				{
					APP->FUNCTION_KEY_DOWN(
						APP->KEY.DOWN,
						APP->FUNCTION_KEY_DOWN_ARG
					);
				}
			}
			else // KEY UP
			{
				APP->KEY.UP = KEY;
				if (!!APP->FUNCTION_KEY_UP)
				{
					APP->FUNCTION_KEY_UP(
						APP->KEY.UP,
						APP->FUNCTION_KEY_UP_ARG
					);
				}
			}

			break ;
		}
		case (WM_MOUSEMOVE): // 0X0200
		{
			APP->MOUSE.Y = HIWORD(L_PARAM);
			APP->MOUSE.X = LOWORD(L_PARAM);
			SET_CURSOR(APP, APP->MOUSE.CURSOR); // FIX AN ANNOYING BUG

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
		case (WM_LBUTTONDOWN): // 0X0201
		{
			APP->MOUSE.LEFT_DOWN = 1;
			APP->MOUSE.VALUE = 1;

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
		case (WM_LBUTTONUP): // 0X0202
		{
			APP->MOUSE.LEFT_DOWN = 0;
			APP->MOUSE.LEFT_UP = 1;
			break ;
		}
		case (WM_RBUTTONDOWN): // 0X0204
		{
			APP->MOUSE.RIGHT_DOWN = 1;
			APP->MOUSE.VALUE = 2;

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
		case (WM_RBUTTONUP): // 0X0205
		{
			APP->MOUSE.RIGHT_DOWN = 0;
			APP->MOUSE.RIGHT_UP = 1;
			break ;
		}
		case (WM_MBUTTONDOWN): // 0X0207
		{
			APP->MOUSE.MIDDLE_DOWN = 1;
			APP->MOUSE.VALUE = 3;

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
		case (WM_MBUTTONUP): // 0X0208
		{
			APP->MOUSE.MIDDLE_DOWN = 0;
			APP->MOUSE.MIDDLE_UP = 1;
			break ;
		}
		case (WM_MOUSEWHEEL): // 0X020A
		{
			if (APP->KEY.SHIFT)
			{
				APP->MOUSE.HORIZANTAL_WHEEL =
					GET_WHEEL_DELTA_WPARAM(W_PARAM);

				if (APP->MOUSE.HORIZANTAL_WHEEL < 0)
					APP->MOUSE.VALUE = 6;
				else
					APP->MOUSE.VALUE = 7;

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
			else
			{
				APP->MOUSE.WHEEL = GET_WHEEL_DELTA_WPARAM(W_PARAM);

				if (APP->MOUSE.WHEEL < 0)
					APP->MOUSE.VALUE = 4;
				else
					APP->MOUSE.VALUE = 5;

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

			break ;
		}
		default:
		{
			return (DefWindowProc(WINDOW_HANDLE, MSG, W_PARAM, L_PARAM));
			break ;
		}
	}

	return (0);
}

int
	IDLE_FUNCTION(void *ARG)
{
	IGNORE_VAR	ARG;

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C */
