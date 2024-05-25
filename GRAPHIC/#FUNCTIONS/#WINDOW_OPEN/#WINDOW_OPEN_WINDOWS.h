/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_OPEN_WINDOWS     #       Maximum Tension       #
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
#	 define BI_BITFIELDS
#	 define DIB_RGB_COLORS
#	 define SRCCOPY
#	typedef BITMAPINFOHEADER;
#	typedef RGBQUAD;
#	typedef BITMAPINFO;
#	    HDC CreateCompatibleDC(HDC);
#	    HDC BeginPaint(HWND, LPPAINTSTRUCT);
#	HBITMAP CreateCompatibleBitmap(HDC, int, int);
#	HGDIOBJ SelectObject(HDC, HGDIOBJ);
#	    int SetDIBitsToDevice(HDC, int, int, DWORD, DWORD, int, int, UINT, UINT,
>	        PCVOID, BITMAPINFO *, UINT);
#	   BOOL BitBlt (HDC, int, int, int, int, HDC, int, int, DWORD);
#	   BOOL DeleteObject(HGDIOBJ);
#	   BOOL DeleteDC(HDC);
#	        */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <winuser.h> /*
#	 define CS_VREDRAW
#	 define CS_HREDRAW
#	 define SetWindowLongPtr
#	 define SW_NORMAL
#	 define GetWindowLongPtr
#	 define WM_PAINT
#	 define WM_CLOSE
#	 define WM_LBUTTONDOWN
#	 define WM_LBUTTONUP
#	 define WM_MOUSEMOVE
#	 define WM_KEYDOWN
#	 define WM_KEYUP
#	 define WM_DESTROY
#	 define DefWindowProc
#	typedef WNDCLASSEX;
#	typedef PAINTSTRUCT;
#	   void RegisterClassEx(WNDCLASSEX *);
#	   HWND CreateWindowEx(DWORD, LPCTSTR, LPCTSTR, DWORD, int, int, int, int, 
>	        HWND, HMENU, HINSTANCE, LPVOID);
#	   BOOL ShowWindow(HWND, int);
#	   BOOL UpdateWindow(HWND);
#	   BOOL EndPaint(HWND, PAINTSTRUCT *);
#	   BOOL DestroyWindow(HWND);
#	   void PostQuitMessage(int);
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	   void free(void *);
#	        */
#	include "../../CMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
#	        */
#	include <winbase.h> /*
#	 define GetModuleHandle
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
static LRESULT CALLBACK	GRAPHIC_WINDOW_PROCESS_HANDLE(\
const HWND WINDOW_HANDLE, const UINT MSG, const WPARAM W_PARAM, \
const LPARAM L_PARAM);
/* *************************** [^] PROTOTYPES [^] *************************** */
/* **************************** [v] STRUCTS [v] ***************************** */
typedef struct BINFO
{
		BITMAPINFOHEADER (BITMAP_HEADER);
		RGBQUAD          (BITMAP_COLORS)[3];
} BINFO;
/* **************************** [^] STRUCTS [^] ***************************** */

int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC, register unsigned int WIDTH, \
register unsigned int HEIGHT)
{
	WNDCLASSEX            (WINDOW_CLASS);
	register HINSTANCE (HANDLE_INSTANCE);

	if (!GRAPHIC || !GRAPHIC->TITLE)
		return (-1);

	GRAPHIC->BUFFER = (unsigned int *)malloc(\
		sizeof(unsigned int) * (WIDTH * HEIGHT + 1)\
	);

	if (!GRAPHIC->BUFFER)
		return (-1);

	PREFETCH_RANGE(GRAPHIC->BUFFER, WIDTH * HEIGHT);
	GRAPHIC->WIDTH = WIDTH;
	GRAPHIC->HEIGHT = HEIGHT;
	HANDLE_INSTANCE = GetModuleHandle(NULL);
	WINDOW_CLASS = (WNDCLASSEX){0};
	WINDOW_CLASS.cbSize = sizeof(WNDCLASSEX);
	WINDOW_CLASS.style = CS_VREDRAW | CS_HREDRAW;
	WINDOW_CLASS.lpfnWndProc = GRAPHIC_WINDOW_PROCESS_HANDLE;
	WINDOW_CLASS.hInstance = HANDLE_INSTANCE;
	WINDOW_CLASS.lpszClassName = GRAPHIC->TITLE;
	RegisterClassEx(&WINDOW_CLASS);
	GRAPHIC->WINDOW_HANDLE = CreateWindowEx(\
		WS_EX_CLIENTEDGE, /* TODO: https://learn.microsoft.com/en-us/previous-versions/ms960010(v=msdn.10) */ \
		GRAPHIC->TITLE, \
		GRAPHIC->TITLE, \
		WS_OVERLAPPEDWINDOW, \
		CW_USEDEFAULT, \
		CW_USEDEFAULT, \
		GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, \
		NULL, \
		NULL, \
		HANDLE_INSTANCE, \
		NULL\
	);

	if (!GRAPHIC->WINDOW_HANDLE)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	if (SetWindowLongPtr(\
		GRAPHIC->WINDOW_HANDLE, \
		GWLP_USERDATA, \
		(LONG_PTR)GRAPHIC)\
	)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		DestroyWindow(GRAPHIC->WINDOW_HANDLE);
		GRAPHIC->WINDOW_HANDLE = ((void *)0);
		return (-1);
	}

	ShowWindow(GRAPHIC->WINDOW_HANDLE, SW_NORMAL);
	UpdateWindow(GRAPHIC->WINDOW_HANDLE);
	GRAPHIC->WINDOW_EXIST = 1;
	return (0);
}

static LRESULT CALLBACK
	GRAPHIC_WINDOW_PROCESS_HANDLE(const HWND WINDOW_HANDLE, const UINT MSG, \
const WPARAM W_PARAM, const LPARAM L_PARAM)
{
	struct GRAPHIC *(GRAPHIC) = ((void *)0);

	GRAPHIC = (struct GRAPHIC *)GetWindowLongPtr(\
		WINDOW_HANDLE, GWLP_USERDATA);

	if (!GRAPHIC)
		return (1);

	GRAPHIC->MOUSE.LEFT_UP = 0;
	GRAPHIC->MOUSE.RIGHT_UP = 0;
	GRAPHIC->MOUSE.VALUE = 0;
	GRAPHIC->MOUSE.MIDDLE_UP = 0;
	GRAPHIC->MOUSE.WHEEL = 0;
	GRAPHIC->MOUSE.HORIZANTAL_WHEEL = 0;
	switch (MSG)
	{ // "switch case" is speed! Wrom wrommmm!!!
		case (WM_DESTROY): // 0X0002
		{
			PostQuitMessage(0);
			break ;
		}
		case (WM_PAINT): // 0X000F
		{
			PAINTSTRUCT   (PAINTSTRUCT);
			HDC (HANDLE_DEVICE_CONTEXT);
			HDC (MEMORY_DEVICE_CONTEXT);
			HBITMAP     (HANDLE_BITMAP);
			HBITMAP (HANDLE_OLD_BITMAP);
			BINFO         (BITMAP_INFO);

			BITMAP_INFO.BITMAP_HEADER.biSize = (DWORD) sizeof(BITMAP_INFO);
			BITMAP_INFO.BITMAP_HEADER.biWidth = (LONG) GRAPHIC->WIDTH;
			BITMAP_INFO.BITMAP_HEADER.biHeight = (LONG) -(GRAPHIC->HEIGHT);
			BITMAP_INFO.BITMAP_HEADER.biPlanes = (WORD) 1;
			BITMAP_INFO.BITMAP_HEADER.biBitCount = (WORD) 32;
			BITMAP_INFO.BITMAP_HEADER.biCompression = (DWORD) BI_BITFIELDS;
			HANDLE_DEVICE_CONTEXT = BeginPaint(WINDOW_HANDLE, &PAINTSTRUCT);
			MEMORY_DEVICE_CONTEXT = CreateCompatibleDC(HANDLE_DEVICE_CONTEXT);
			HANDLE_BITMAP = CreateCompatibleBitmap(\
				HANDLE_DEVICE_CONTEXT, \
				GRAPHIC->WIDTH, \
				GRAPHIC->HEIGHT\
			);
			HANDLE_OLD_BITMAP = SelectObject(MEMORY_DEVICE_CONTEXT, \
				HANDLE_BITMAP);	
			BITMAP_INFO.BITMAP_COLORS[0].rgbRed = 0XFF;
			BITMAP_INFO.BITMAP_COLORS[1].rgbGreen = 0XFF;
			BITMAP_INFO.BITMAP_COLORS[2].rgbBlue = 0XFF;
			SetDIBitsToDevice(\
				MEMORY_DEVICE_CONTEXT, \
				0, \
				0, \
				GRAPHIC->WIDTH, \
				GRAPHIC->HEIGHT, \
				0, \
				0, \
				0, \
				GRAPHIC->HEIGHT, \
				GRAPHIC->BUFFER, \
				(BITMAPINFO *)&BITMAP_INFO, \
				DIB_RGB_COLORS\
			);
			BitBlt(HANDLE_DEVICE_CONTEXT, 0, 0, GRAPHIC->WIDTH, \
				GRAPHIC->HEIGHT, MEMORY_DEVICE_CONTEXT, 0, 0, SRCCOPY);
			SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_OLD_BITMAP);
			DeleteObject(HANDLE_BITMAP);
			DeleteDC(MEMORY_DEVICE_CONTEXT);
			EndPaint(WINDOW_HANDLE, &PAINTSTRUCT);
			break ;
		}
		case (WM_CLOSE): // CLICKING "X" BUTTON // 0X0010
		{
			if (!!GRAPHIC->FUNCTION_CLOSE)
				GRAPHIC->FUNCTION_CLOSE(GRAPHIC->FUNCTION_CLOSE_ARG);
			else
			{
				if (!!GRAPHIC->BUFFER)
				{
					free(GRAPHIC->BUFFER);
					GRAPHIC->BUFFER = ((void *)0);
				}
				DestroyWindow(WINDOW_HANDLE);
			}
			GRAPHIC = ((void *)0);
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
					GRAPHIC->KEY.BACKSPACE = !((L_PARAM >> 31) & 1);
					break ;
				case (9):
					GRAPHIC->KEY.TAB = !((L_PARAM >> 31) & 1);
					break ;
				case (13):
					GRAPHIC->KEY.ENTER = !((L_PARAM >> 31) & 1);
					KEY = 10;
					break ;
				case (16):
					GRAPHIC->KEY.SHIFT = !((L_PARAM >> 31) & 1);
					break ;
				case (17):
					GRAPHIC->KEY.CTRL = !((L_PARAM >> 31) & 1);
					break ;
				case (18):
					GRAPHIC->KEY.ALT = !((L_PARAM >> 31) & 1);
					break ;
				case (19):
					GRAPHIC->KEY.PAUSE = !((L_PARAM >> 31) & 1);
					break ;
				case (20):
					GRAPHIC->KEY.CAPSLOCK = !((L_PARAM >> 31) & 1);
					break ;
				case (27):
					GRAPHIC->KEY.ESC = !((L_PARAM >> 31) & 1);
					break ;
				case (32):
					GRAPHIC->KEY.SPACEBAR = !((L_PARAM >> 31) & 1);
					break ;
				case (33):
					GRAPHIC->KEY.PAGE_UP = !((L_PARAM >> 31) & 1);
					break ;
				case (34):
					GRAPHIC->KEY.PAGE_DOWN = !((L_PARAM >> 31) & 1);
					break ;
				case (35):
					GRAPHIC->KEY.END = !((L_PARAM >> 31) & 1);
					break ;
				case (36):
					GRAPHIC->KEY.HOME = !((L_PARAM >> 31) & 1);
					break ;
				case (37):
					GRAPHIC->KEY.ARROW_LEFT = !((L_PARAM >> 31) & 1);
					break ;
				case (38):
					GRAPHIC->KEY.ARROW_UP = !((L_PARAM >> 31) & 1);
					break ;
				case (39):
					GRAPHIC->KEY.ARROW_RIGHT = !((L_PARAM >> 31) & 1);
					break ;
				case (40):
					GRAPHIC->KEY.ARROW_DOWN = !((L_PARAM >> 31) & 1);
					break ;
				case (44):
					GRAPHIC->KEY.PRTSC = !((L_PARAM >> 31) & 1);
					break ;
				case (45):
					GRAPHIC->KEY.INSERT = !((L_PARAM >> 31) & 1);
					break ;
				case (46):
					GRAPHIC->KEY.DEL = !((L_PARAM >> 31) & 1);
					break ;
				case (47):
					GRAPHIC->KEY.HELP = !((L_PARAM >> 31) & 1);
					break ;
				case (48):
					GRAPHIC->KEY._0 = !((L_PARAM >> 31) & 1);
					break ;
				case (49):
					GRAPHIC->KEY._1 = !((L_PARAM >> 31) & 1);
					break ;
				case (50):
					GRAPHIC->KEY._2 = !((L_PARAM >> 31) & 1);
					break ;
				case (51):
					GRAPHIC->KEY._3 = !((L_PARAM >> 31) & 1);
					break ;
				case (52):
					GRAPHIC->KEY._4 = !((L_PARAM >> 31) & 1);
					break ;
				case (53):
					GRAPHIC->KEY._5 = !((L_PARAM >> 31) & 1);
					break ;
				case (54):
					GRAPHIC->KEY._6 = !((L_PARAM >> 31) & 1);
					break ;
				case (55):
					GRAPHIC->KEY._7 = !((L_PARAM >> 31) & 1);
					break ;
				case (56):
					GRAPHIC->KEY._8 = !((L_PARAM >> 31) & 1);
					break ;
				case (57):
					GRAPHIC->KEY._9 = !((L_PARAM >> 31) & 1);
					break ;
				case (65):
					GRAPHIC->KEY.A = !((L_PARAM >> 31) & 1);
					break ;
				case (66):
					GRAPHIC->KEY.B = !((L_PARAM >> 31) & 1);
					break ;
				case (67):
					GRAPHIC->KEY.C = !((L_PARAM >> 31) & 1);
					break ;
				case (68):
					GRAPHIC->KEY.D = !((L_PARAM >> 31) & 1);
					break ;
				case (69):
					GRAPHIC->KEY.E = !((L_PARAM >> 31) & 1);
					break ;
				case (70):
					GRAPHIC->KEY.F = !((L_PARAM >> 31) & 1);
					break ;
				case (71):
					GRAPHIC->KEY.G = !((L_PARAM >> 31) & 1);
					break ;
				case (72):
					GRAPHIC->KEY.H = !((L_PARAM >> 31) & 1);
					break ;
				case (73):
					GRAPHIC->KEY.I = !((L_PARAM >> 31) & 1);
					break ;
				case (74):
					GRAPHIC->KEY.J = !((L_PARAM >> 31) & 1);
					break ;
				case (75):
					GRAPHIC->KEY.K = !((L_PARAM >> 31) & 1);
					break ;
				case (76):
					GRAPHIC->KEY.L = !((L_PARAM >> 31) & 1);
					break ;
				case (77):
					GRAPHIC->KEY.M = !((L_PARAM >> 31) & 1);
					break ;
				case (78):
					GRAPHIC->KEY.N = !((L_PARAM >> 31) & 1);
					break ;
				case (79):
					GRAPHIC->KEY.O = !((L_PARAM >> 31) & 1);
					break ;
				case (80):
					GRAPHIC->KEY.P = !((L_PARAM >> 31) & 1);
					break ;
				case (81):
					GRAPHIC->KEY.Q = !((L_PARAM >> 31) & 1);
					break ;
				case (82):
					GRAPHIC->KEY.R = !((L_PARAM >> 31) & 1);
					break ;
				case (83):
					GRAPHIC->KEY.S = !((L_PARAM >> 31) & 1);
					break ;
				case (84):
					GRAPHIC->KEY.T = !((L_PARAM >> 31) & 1);
					break ;
				case (85):
					GRAPHIC->KEY.U = !((L_PARAM >> 31) & 1);
					break ;
				case (86):
					GRAPHIC->KEY.V = !((L_PARAM >> 31) & 1);
					break ;
				case (87):
					GRAPHIC->KEY.W = !((L_PARAM >> 31) & 1);
					break ;
				case (88):
					GRAPHIC->KEY.X = !((L_PARAM >> 31) & 1);
					break ;
				case (89):
					GRAPHIC->KEY.Y = !((L_PARAM >> 31) & 1);
					break ;
				case (90):
					GRAPHIC->KEY.Z = !((L_PARAM >> 31) & 1);
					break ;
				case (91):
				case (92):
					GRAPHIC->KEY.WIN = !((L_PARAM >> 31) & 1);
					break ;
				case (112):
					GRAPHIC->KEY.F1 = !((L_PARAM >> 31) & 1);
					break ;
				case (113):
					GRAPHIC->KEY.F2 = !((L_PARAM >> 31) & 1);
					break ;
				case (114):
					GRAPHIC->KEY.F3 = !((L_PARAM >> 31) & 1);
					break ;
				case (115):
					GRAPHIC->KEY.F4 = !((L_PARAM >> 31) & 1);
					break ;
				case (116):
					GRAPHIC->KEY.F5 = !((L_PARAM >> 31) & 1);
					break ;
				case (117):
					GRAPHIC->KEY.F6 = !((L_PARAM >> 31) & 1);
					break ;
				case (118):
					GRAPHIC->KEY.F7 = !((L_PARAM >> 31) & 1);
					break ;
				case (119):
					GRAPHIC->KEY.F8 = !((L_PARAM >> 31) & 1);
					break ;
				case (120):
					GRAPHIC->KEY.F9 = !((L_PARAM >> 31) & 1);
					break ;
				case (121):
					GRAPHIC->KEY.F10 = !((L_PARAM >> 31) & 1);
					break ;
				case (122):
					GRAPHIC->KEY.F11 = !((L_PARAM >> 31) & 1);
					break ;
				case (123):
					GRAPHIC->KEY.F12 = !((L_PARAM >> 31) & 1);
					break ;
				case (186):
					GRAPHIC->KEY.SEMICOLON = !((L_PARAM >> 31) & 1);
					break ;
				case (187):
					GRAPHIC->KEY.EQUAL = !((L_PARAM >> 31) & 1);
					break ;
				case (188):
					GRAPHIC->KEY.COMMA = !((L_PARAM >> 31) & 1);
					break ;
				case (189):
					GRAPHIC->KEY.MINUS = !((L_PARAM >> 31) & 1);
					break ;
				case (190):
					GRAPHIC->KEY.DOT = !((L_PARAM >> 31) & 1);
					break ;
				case (191):
					GRAPHIC->KEY.SLASH = !((L_PARAM >> 31) & 1);
					break ;
				case (192):
					GRAPHIC->KEY.GRAVE = !((L_PARAM >> 31) & 1);
					break ;
				case (219):
					GRAPHIC->KEY.LEFT_BRACKET = !((L_PARAM >> 31) & 1);
					break ;
				case (220):
					GRAPHIC->KEY.BACKSLASH = !((L_PARAM >> 31) & 1);
					break ;
				case (221):
					GRAPHIC->KEY.RIGHT_BRACKET = !((L_PARAM >> 31) & 1);
					break ;
				case (222):
					GRAPHIC->KEY.APOSTROPHE = !((L_PARAM >> 31) & 1);
					break ;
				case (223):
					GRAPHIC->KEY.SELECTION_SIGN = !((L_PARAM >> 31) & 1);
					break ;
				case (226):
					GRAPHIC->KEY.SELECTION_SIGN = !((L_PARAM >> 31) & 1);
					break ;
				case (255):
					GRAPHIC->KEY.FN = !((L_PARAM >> 31) & 1);
					break ;
			}

			if (GRAPHIC->KEY.DOWN)
				GRAPHIC->KEY.DOWN = 0;

			if (GRAPHIC->KEY.UP)
				GRAPHIC->KEY.UP = 0;

			if (MSG == WM_KEYDOWN)
			{
				GRAPHIC->KEY.DOWN = KEY;
				if (!!GRAPHIC->FUNCTION_KEY_DOWN)
					GRAPHIC->FUNCTION_KEY_DOWN(GRAPHIC->KEY.DOWN, \
						GRAPHIC->FUNCTION_KEY_DOWN_ARG);
			}
			else // KEY UP
			{
				GRAPHIC->KEY.UP = KEY;
				if (!!GRAPHIC->FUNCTION_KEY_UP)
					GRAPHIC->FUNCTION_KEY_UP(GRAPHIC->KEY.UP, \
						GRAPHIC->FUNCTION_KEY_UP_ARG);
			}

			break ;
		}
		case (WM_MOUSEMOVE): // 0X0200
		{
			GRAPHIC->MOUSE.Y = HIWORD(L_PARAM);
			GRAPHIC->MOUSE.X = LOWORD(L_PARAM);
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_LBUTTONDOWN): // 0X0201
		{
			GRAPHIC->MOUSE.LEFT_DOWN = 1;
			GRAPHIC->MOUSE.VALUE = 1;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_LBUTTONUP): // 0X0202
		{
			GRAPHIC->MOUSE.LEFT_DOWN = 0;
			GRAPHIC->MOUSE.LEFT_UP = 1;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_LBUTTONDBLCLK): // 0X0203
		{
			GRAPHIC->MOUSE.LEFT_DOUBLE_CLICK = 1;
			GRAPHIC->MOUSE.VALUE = 1;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_RBUTTONDOWN): // 0X0204
		{
			GRAPHIC->MOUSE.RIGHT_DOWN = 1;
			GRAPHIC->MOUSE.VALUE = 2;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_RBUTTONUP): // 0X0205
		{
			GRAPHIC->MOUSE.RIGHT_DOWN = 0;
			GRAPHIC->MOUSE.RIGHT_UP = 1;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_RBUTTONDBLCLK): // 0X0206
		{
			GRAPHIC->MOUSE.RIGHT_DOUBLE_CLICK = 1;
			GRAPHIC->MOUSE.VALUE = 2;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_MBUTTONDOWN): // 0X0207
		{
			GRAPHIC->MOUSE.MIDDLE_DOWN = 1;
			GRAPHIC->MOUSE.VALUE = 3;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_MBUTTONUP): // 0X0208
		{
			GRAPHIC->MOUSE.MIDDLE_DOWN = 0;
			GRAPHIC->MOUSE.MIDDLE_UP = 1;
			if (!!GRAPHIC->FUNCTION_MOUSE)
				GRAPHIC->FUNCTION_MOUSE(\
					GRAPHIC->MOUSE.X, \
					GRAPHIC->MOUSE.Y, \
					GRAPHIC->MOUSE.VALUE, \
					GRAPHIC->FUNCTION_MOUSE_ARG\
				);
			break ;
		}
		case (WM_MOUSEWHEEL): // 0X020A
		{
			if (GRAPHIC->KEY.SHIFT)
			{
				GRAPHIC->MOUSE.HORIZANTAL_WHEEL = \
					GET_WHEEL_DELTA_WPARAM(W_PARAM);
				if (GRAPHIC->MOUSE.HORIZANTAL_WHEEL < 0)
					GRAPHIC->MOUSE.VALUE = 6;
				else
					GRAPHIC->MOUSE.VALUE = 7;
				if (!!GRAPHIC->FUNCTION_MOUSE)
					GRAPHIC->FUNCTION_MOUSE(\
						GRAPHIC->MOUSE.X, \
						GRAPHIC->MOUSE.Y, \
						GRAPHIC->MOUSE.VALUE, \
						GRAPHIC->FUNCTION_MOUSE_ARG\
					);
			}
			else
			{
				GRAPHIC->MOUSE.WHEEL = GET_WHEEL_DELTA_WPARAM(W_PARAM);
				if (GRAPHIC->MOUSE.WHEEL < 0)
						GRAPHIC->MOUSE.VALUE = 4;
				else
						GRAPHIC->MOUSE.VALUE = 5;
				if (!!GRAPHIC->FUNCTION_MOUSE)
					GRAPHIC->FUNCTION_MOUSE(\
						GRAPHIC->MOUSE.X, \
						GRAPHIC->MOUSE.Y, \
						GRAPHIC->MOUSE.VALUE, \
						GRAPHIC->FUNCTION_MOUSE_ARG\
					);
			}

			break ;
		}
		default :
		{
			return (DefWindowProc(WINDOW_HANDLE, MSG, W_PARAM, L_PARAM));
			break ;
		}
	}
	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_H */
