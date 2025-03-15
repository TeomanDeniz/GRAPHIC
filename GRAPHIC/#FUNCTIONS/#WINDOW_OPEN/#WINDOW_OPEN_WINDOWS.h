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
# : License - APACHE 2  :: Update - 2025/03/13 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_OPEN_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include "../../LIBCMT/KEYWORDS/IGNORE.h" /*
#	 define IGNORE
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
#	 define BI_BITFIELDS
#	 define BI_RGB	
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
#	   BOOL StretchBlt(HDC, int, int, int, int, HDC, int, int, int, int DWORD);
#	   BOOL DeleteObject(HGDIOBJ);
#	   BOOL DeleteDC(HDC);
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
#	 define AC_SRC_OVER
#	 define AC_SRC_ALPHA
#	 define ULW_ALPHA
#	 define GWLP_USERDATA
#	typedef RECT;
#	typedef POINT;
#	typedef SIZE;
#	typedef WNDCLASSEX;
#	typedef PAINTSTRUCT;
#	   void RegisterClassEx(WNDCLASSEX *);
#	   HWND CreateWindowEx(DWORD, LPCTSTR, LPCTSTR, DWORD, int, int, int, int, 
>	        	HWND, HMENU, HINSTANCE, LPVOID);
#	   BOOL ShowWindow(HWND, int);
#	   BOOL UpdateWindow(HWND);
#	   BOOL EndPaint(HWND, PAINTSTRUCT *);
#	   BOOL DestroyWindow(HWND);
#	   void PostQuitMessage(int);
#	   BOOL UpdateLayeredWindow(HWND, HDC, POINT, SIZE, HDC, POINT, COLORREF,
>	        	BLENDFUNCTION, DWORD);
#	HBITMAP CreateDIBSection(HDC, BITMAPINFO, UINT, VOID, HANDLE, DWORD);
#	   BOOL SetWindowPos(HWND, HWND, int, int, int, int, UINT);
#	        */
#	include <stdlib.h> /*
#	typedef size_t;
#	   void *malloc(size_t);
#	   void free(void *);
#	        */
#	include "../../LIBCMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
#	        */
#	include <winbase.h> /*
#	 define GetModuleHandle
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern void				WINDOW_CLOSE(struct GRAPHIC *);
extern void				*memset(void *, int, size_t);
extern void				*memcpy (void *, const void *, size_t);
static LRESULT CALLBACK	GRAPHIC_WINDOW_PROCESS_HANDLE(\
	const HWND WINDOW_HANDLE,
	const UINT MSG,
	const WPARAM W_PARAM,
	const LPARAM L_PARAM
);
extern void				REFRESH_SCREEN(const struct GRAPHIC	*const GRAPHIC);
extern int				IDLE_FUNCTION(void *ARG);
/* *************************** [^] PROTOTYPES [^] *************************** */

/* **************************** [v] STRUCTS [v] ***************************** */
typedef struct BINFO
{
		BITMAPINFOHEADER	BITMAP_HEADER;
		RGBQUAD				BITMAP_COLORS[3];
} BINFO;
/* **************************** [^] STRUCTS [^] ***************************** */

int
	WINDOW_OPEN(
	struct GRAPHIC *GRAPHIC,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
{
	RECT				WINDOW_RECTANGLE = {0, 0, WIDTH, HEIGHT};
	WNDCLASSEX			WINDOW_CLASS;
	register HINSTANCE	HANDLE_INSTANCE;
	register DWORD		WINDOW_STYLE;
	register DWORD		EXTENDED_WINDOW_STYLE;

	if (!GRAPHIC || !GRAPHIC->WINDOW.TITLE)
		return (-1);

	GRAPHIC->BUFFER = (unsigned int *)malloc(\
		sizeof(unsigned int) * (WIDTH * HEIGHT + 1)\
	);

	if (!GRAPHIC->BUFFER)
		return (-2);

	if (!GRAPHIC->FUNCTION_LOOP)
		GRAPHIC->FUNCTION_LOOP = IDLE_FUNCTION;

	if (!GRAPHIC->FUNCTION_RESIZE)
		GRAPHIC->FUNCTION_RESIZE = IDLE_FUNCTION;

	PREFETCH_RANGE(GRAPHIC->BUFFER, WIDTH * HEIGHT);
	GRAPHIC->WINDOW.WIDTH = WIDTH;
	GRAPHIC->WINDOW.HEIGHT = HEIGHT;
	GRAPHIC->WIDTH = WIDTH;
	GRAPHIC->HEIGHT = HEIGHT;
	HANDLE_INSTANCE = GetModuleHandle((void *)0);
	WINDOW_STYLE = WS_OVERLAPPEDWINDOW;
	EXTENDED_WINDOW_STYLE = WS_EX_CLIENTEDGE;
	WINDOW_CLASS = (WNDCLASSEX){0};
	WINDOW_CLASS.cbSize = sizeof(WNDCLASSEX);
	WINDOW_CLASS.style = CS_VREDRAW | CS_HREDRAW;
	WINDOW_CLASS.lpfnWndProc = GRAPHIC_WINDOW_PROCESS_HANDLE;
	WINDOW_CLASS.hInstance = HANDLE_INSTANCE;
	WINDOW_CLASS.lpszClassName = GRAPHIC->WINDOW.TITLE;
	WINDOW_CLASS.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	RegisterClassEx(&WINDOW_CLASS);

	if (GRAPHIC->WINDOW.TRANSPARENCY)
	{
		WINDOW_STYLE |= WS_POPUP;
		EXTENDED_WINDOW_STYLE |= WS_EX_LAYERED;
		//EXTENDED_WINDOW_STYLE |= WS_EX_TRANSPARENT;
	}

	if (GRAPHIC->WINDOW.TOPMOST)
		EXTENDED_WINDOW_STYLE |= WS_EX_TOPMOST;

	if (GRAPHIC->WINDOW.CLIENTEDGE)
		EXTENDED_WINDOW_STYLE |= WS_EX_CLIENTEDGE;

	if (GRAPHIC->WINDOW.TOOLWINDOW)
		EXTENDED_WINDOW_STYLE |= WS_EX_TOOLWINDOW;

	if (!GRAPHIC->WINDOW.BORDER)
	{
		WINDOW_STYLE &= ~WS_BORDER;
		WINDOW_STYLE &= ~WS_CAPTION;
	}
	else
	{
		WINDOW_STYLE |= WS_BORDER;
		WINDOW_STYLE |= WS_CAPTION;
	}

	if (!GRAPHIC->WINDOW.RESIZABLE)
		WINDOW_STYLE &= ~WS_SIZEBOX;
	else
		WINDOW_STYLE |= WS_SIZEBOX;

	if (!GRAPHIC->WINDOW.MINIMIZABLE)
		WINDOW_STYLE &= ~WS_MINIMIZEBOX;
	else
		WINDOW_STYLE |= WS_MINIMIZEBOX;

	if (!GRAPHIC->WINDOW.MAXIMIZABLE)
		WINDOW_STYLE &= ~WS_MAXIMIZEBOX;
	else
		WINDOW_STYLE |= WS_MAXIMIZEBOX;

	if (!GRAPHIC->WINDOW.CLOSEBUTTON)
		WINDOW_STYLE &= ~WS_SYSMENU;
	else
		WINDOW_STYLE |= WS_SYSMENU;

	if (!GRAPHIC->WINDOW.FOCUSABLE)
		WINDOW_STYLE &= ~WS_TABSTOP;
	else
		WINDOW_STYLE |= WS_TABSTOP;

	AdjustWindowRectEx(
		&WINDOW_RECTANGLE,
		WINDOW_STYLE,
		0,
		EXTENDED_WINDOW_STYLE
	);

	GRAPHIC->WINDOW_HANDLE = CreateWindowEx(
		EXTENDED_WINDOW_STYLE,
		GRAPHIC->WINDOW.TITLE,
		GRAPHIC->WINDOW.TITLE,
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

	if (!GRAPHIC->WINDOW_HANDLE)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	if (
		SetWindowLongPtr(
			GRAPHIC->WINDOW_HANDLE,
			GWLP_USERDATA,
			(LONG_PTR)GRAPHIC
		)
	)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		DestroyWindow(GRAPHIC->WINDOW_HANDLE);
		GRAPHIC->WINDOW_HANDLE = ((void *)0);
		return (-3);
	}

	SetWindowPos(
		GRAPHIC->WINDOW_HANDLE, 
		NULL,
		0,
		0,
		0,
		0, 
		SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED
	);

	if (GRAPHIC->WINDOW.HIDEONCREATE)
		ShowWindow(GRAPHIC->WINDOW_HANDLE, SW_HIDE);
	else
		ShowWindow(GRAPHIC->WINDOW_HANDLE, SW_SHOW);

	UpdateWindow(GRAPHIC->WINDOW_HANDLE);
	GRAPHIC->REFRESH_SCREEN = REFRESH_SCREEN;
	return (0);
}

extern void
	REFRESH_SCREEN(const struct GRAPHIC *const GRAPHIC)
{
	PAINTSTRUCT	PAINTSTRUCT;
	HDC			HANDLE_DEVICE_CONTEXT;
	HDC			MEMORY_DEVICE_CONTEXT;
	HBITMAP		HANDLE_BITMAP;
	HBITMAP		HANDLE_OLD_BITMAP;

	if (GRAPHIC->WINDOW.TRANSPARENCY)
	{
		BITMAPINFO		BITMAP_HEADER;
		void			*BITMAP_DATA;
		POINT			POINT_SOURCE = {0, 0};
		SIZE			WINDOW_SIZE = {GRAPHIC->WIDTH, GRAPHIC->WINDOW.HEIGHT};
		BLENDFUNCTION	BLEND = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};

		BITMAP_HEADER.bmiHeader.biSize = (DWORD)sizeof(BITMAPINFOHEADER);
		BITMAP_HEADER.bmiHeader.biWidth = (LONG)GRAPHIC->WINDOW.WIDTH;
		BITMAP_HEADER.bmiHeader.biHeight = (LONG)-(GRAPHIC->WINDOW.HEIGHT);
		BITMAP_HEADER.bmiHeader.biPlanes = (WORD)1;
		BITMAP_HEADER.bmiHeader.biBitCount = (WORD)32;
		BITMAP_HEADER.bmiHeader.biCompression = (DWORD)BI_RGB;
		HANDLE_DEVICE_CONTEXT = GetDC(GRAPHIC->WINDOW_HANDLE);
		MEMORY_DEVICE_CONTEXT =
			CreateCompatibleDC(HANDLE_DEVICE_CONTEXT);
		HANDLE_BITMAP = CreateDIBSection(
			MEMORY_DEVICE_CONTEXT,
			&BITMAP_HEADER,
			DIB_RGB_COLORS,
			&BITMAP_DATA,
			((void *)0),
			0
		);

		if (!HANDLE_BITMAP)
			return ;

		memcpy(
			BITMAP_DATA,
			GRAPHIC->BUFFER,
			GRAPHIC->WIDTH * GRAPHIC->HEIGHT * sizeof(unsigned int)
		);
		HANDLE_OLD_BITMAP = SelectObject(
			MEMORY_DEVICE_CONTEXT,
			HANDLE_BITMAP
		);
		UpdateLayeredWindow(
			GRAPHIC->WINDOW_HANDLE,
			HANDLE_DEVICE_CONTEXT,
			((void *)0),
			&WINDOW_SIZE,
			MEMORY_DEVICE_CONTEXT,
			&POINT_SOURCE,
			0,
			&BLEND,
			ULW_ALPHA
		);
		SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_OLD_BITMAP);
		DeleteObject(HANDLE_BITMAP);
		DeleteDC(MEMORY_DEVICE_CONTEXT);
		EndPaint(GRAPHIC->WINDOW_HANDLE, &PAINTSTRUCT);
	}
	else
	{
		BINFO	BITMAP_INFO;

		BITMAP_INFO.BITMAP_HEADER.biSize = (DWORD)sizeof(BITMAP_INFO);
		BITMAP_INFO.BITMAP_HEADER.biWidth = (LONG)GRAPHIC->WINDOW.WIDTH;
		BITMAP_INFO.BITMAP_HEADER.biHeight = (LONG)-(GRAPHIC->WINDOW.HEIGHT);
		BITMAP_INFO.BITMAP_HEADER.biPlanes = (WORD)1;
		BITMAP_INFO.BITMAP_HEADER.biBitCount = (WORD)32;
		BITMAP_INFO.BITMAP_HEADER.biCompression = (DWORD)BI_BITFIELDS;
		HANDLE_DEVICE_CONTEXT =
			BeginPaint(GRAPHIC->WINDOW_HANDLE, &PAINTSTRUCT);
		MEMORY_DEVICE_CONTEXT =
			CreateCompatibleDC(HANDLE_DEVICE_CONTEXT);
		HANDLE_BITMAP = CreateCompatibleBitmap(
			HANDLE_DEVICE_CONTEXT,
			GRAPHIC->WIDTH,
			GRAPHIC->HEIGHT
		);
		HANDLE_OLD_BITMAP = SelectObject(
			MEMORY_DEVICE_CONTEXT,
			HANDLE_BITMAP
		);
		BITMAP_INFO.BITMAP_COLORS[0].rgbRed = 0XFF;
		BITMAP_INFO.BITMAP_COLORS[1].rgbGreen = 0XFF;
		BITMAP_INFO.BITMAP_COLORS[2].rgbBlue = 0XFF;
		SetDIBitsToDevice(
			MEMORY_DEVICE_CONTEXT,
			0,
			0,
			GRAPHIC->WIDTH,
			GRAPHIC->HEIGHT,
			0,
			0,
			0,
			GRAPHIC->WINDOW.HEIGHT,
			GRAPHIC->BUFFER,
			(BITMAPINFO *)&BITMAP_INFO,
			DIB_RGB_COLORS
		);
		StretchBlt(
			HANDLE_DEVICE_CONTEXT,
			0,
			0,
			GRAPHIC->WINDOW.WIDTH,
			GRAPHIC->WINDOW.HEIGHT,
			MEMORY_DEVICE_CONTEXT,
			0,
			0,
			GRAPHIC->WIDTH,
			GRAPHIC->HEIGHT,
			SRCCOPY
		);
		SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_OLD_BITMAP);
		DeleteObject(HANDLE_BITMAP);
		DeleteDC(MEMORY_DEVICE_CONTEXT);
		EndPaint(GRAPHIC->WINDOW_HANDLE, &PAINTSTRUCT);
	}
}

static LRESULT CALLBACK
	GRAPHIC_WINDOW_PROCESS_HANDLE(
	const HWND WINDOW_HANDLE,
	const UINT MSG,
	const WPARAM W_PARAM,
	const LPARAM L_PARAM
)
{
	struct GRAPHIC	*GRAPHIC;

	GRAPHIC = (struct GRAPHIC *)GetWindowLongPtr(WINDOW_HANDLE, GWLP_USERDATA);

	if (!GRAPHIC)
		return (1);

	memset(&GRAPHIC->MOUSE, 0, sizeof(GRAPHIC->MOUSE));

	switch (MSG)
	{ // "switch case" is speed! Wrom wrommmm!!!
		case (WM_TIMER):
		{
			if (GRAPHIC->WINDOW.TRANSPARENCY)
				REFRESH_SCREEN(GRAPHIC);
			else
				InvalidateRect(WINDOW_HANDLE, ((void *)0), 1);

			UpdateWindow(WINDOW_HANDLE);

			if (GRAPHIC->WINDOW.TRANSPARENCY)
			{
				if (!GRAPHIC->WINDOW_RESIZING)
					GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);
			}
			else
				GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);

			if (!GRAPHIC->WINDOW_HANDLE)
				PostQuitMessage(0);

			break ;
		}
		case (WM_ENTERSIZEMOVE):
		{
			GRAPHIC->WINDOW_RESIZING = 1;
			break ;
		}
		case (WM_EXITSIZEMOVE):
		{
			GRAPHIC->WINDOW_RESIZING = 0;
			break ;
		}
		case (WM_SIZE):
		{
			if (W_PARAM != SIZE_MINIMIZED)
			{
				GRAPHIC->WINDOW.WIDTH = LOWORD(L_PARAM);
				GRAPHIC->WINDOW.HEIGHT = HIWORD(L_PARAM);
				GRAPHIC->WIDTH = GRAPHIC->WINDOW.WIDTH;
				GRAPHIC->HEIGHT = GRAPHIC->WINDOW.HEIGHT;

				free(GRAPHIC->BUFFER);

				GRAPHIC->BUFFER = (unsigned int *)malloc(
					sizeof(unsigned int) *
					(GRAPHIC->WIDTH * GRAPHIC->HEIGHT + 1)
				);

				if (!GRAPHIC->BUFFER)
				{
					WINDOW_CLOSE(GRAPHIC);
					return (1);
				}

				GRAPHIC->FUNCTION_RESIZE(GRAPHIC->FUNCTION_RESIZE_ARG);

				if (GRAPHIC->WINDOW.TRANSPARENCY)
				{
					GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);
					REFRESH_SCREEN(GRAPHIC);
				}
				else
					InvalidateRect(WINDOW_HANDLE, ((void *)0), 1);

				UpdateWindow(WINDOW_HANDLE);
			}

			break ;
		}
		case (WM_DESTROY): // 0X0002
		{
			PostQuitMessage(0);
			break ;
		}
		case (WM_PAINT): // 0X000F
		{
			PAINTSTRUCT	PAINTSTRUCT;
			HDC			HANDLE_DEVICE_CONTEXT;
			HDC			MEMORY_DEVICE_CONTEXT;
			HBITMAP		HANDLE_BITMAP;
			HBITMAP		HANDLE_OLD_BITMAP;

			if (GRAPHIC->WINDOW.TRANSPARENCY)
			{
				BITMAPINFO		BITMAP_HEADER;
				void			*BITMAP_DATA;
				POINT			POINT_SOURCE = {0, 0};
				SIZE			WINDOW_SIZE = {
					GRAPHIC->WINDOW.WIDTH,
					GRAPHIC->WINDOW.HEIGHT
				};
				BLENDFUNCTION	BLEND = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};

				BITMAP_HEADER.bmiHeader.biSize =
					(DWORD)sizeof(BITMAPINFOHEADER);
				BITMAP_HEADER.bmiHeader.biWidth = (LONG)GRAPHIC->WINDOW.WIDTH;
				BITMAP_HEADER.bmiHeader.biHeight =
					(LONG)-(GRAPHIC->WINDOW.HEIGHT);
				BITMAP_HEADER.bmiHeader.biPlanes = (WORD)1;
				BITMAP_HEADER.bmiHeader.biBitCount = (WORD)32;
				BITMAP_HEADER.bmiHeader.biCompression = (DWORD)BI_RGB;
				HANDLE_DEVICE_CONTEXT = GetDC(WINDOW_HANDLE);
				MEMORY_DEVICE_CONTEXT =
					CreateCompatibleDC(HANDLE_DEVICE_CONTEXT);
				HANDLE_BITMAP = CreateDIBSection(
					MEMORY_DEVICE_CONTEXT,
					&BITMAP_HEADER,
					DIB_RGB_COLORS,
					&BITMAP_DATA,
					((void *)0),
					0
				);

				if (!HANDLE_BITMAP)
					break ;

				memcpy(
					BITMAP_DATA,
					GRAPHIC->BUFFER,
					GRAPHIC->WIDTH * GRAPHIC->HEIGHT * sizeof(unsigned int)
				);
				HANDLE_OLD_BITMAP = SelectObject(
					MEMORY_DEVICE_CONTEXT,
					HANDLE_BITMAP
				);
				UpdateLayeredWindow(
					WINDOW_HANDLE,
					HANDLE_DEVICE_CONTEXT,
					((void *)0),
					&WINDOW_SIZE,
					MEMORY_DEVICE_CONTEXT,
					&POINT_SOURCE,
					0,
					&BLEND,
					ULW_ALPHA
				);
				SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_OLD_BITMAP);
				DeleteObject(HANDLE_BITMAP);
				DeleteDC(MEMORY_DEVICE_CONTEXT);
				EndPaint(WINDOW_HANDLE, &PAINTSTRUCT);
			}
			else
			{
				BINFO	BITMAP_INFO;

				BITMAP_INFO.BITMAP_HEADER.biSize = (DWORD)sizeof(BITMAP_INFO);
				BITMAP_INFO.BITMAP_HEADER.biWidth = (LONG)GRAPHIC->WINDOW.WIDTH;
				BITMAP_INFO.BITMAP_HEADER.biHeight =
					(LONG)-(GRAPHIC->WINDOW.HEIGHT);
				BITMAP_INFO.BITMAP_HEADER.biPlanes = (WORD)1;
				BITMAP_INFO.BITMAP_HEADER.biBitCount = (WORD)32;
				BITMAP_INFO.BITMAP_HEADER.biCompression = (DWORD)BI_BITFIELDS;
				HANDLE_DEVICE_CONTEXT = BeginPaint(WINDOW_HANDLE, &PAINTSTRUCT);
				MEMORY_DEVICE_CONTEXT =
					CreateCompatibleDC(HANDLE_DEVICE_CONTEXT);
				HANDLE_BITMAP = CreateCompatibleBitmap(
					HANDLE_DEVICE_CONTEXT,
					GRAPHIC->WIDTH,
					GRAPHIC->HEIGHT
				);
				HANDLE_OLD_BITMAP = SelectObject(
					MEMORY_DEVICE_CONTEXT,
					HANDLE_BITMAP
				);
				BITMAP_INFO.BITMAP_COLORS[0].rgbRed = 0XFF;
				BITMAP_INFO.BITMAP_COLORS[1].rgbGreen = 0XFF;
				BITMAP_INFO.BITMAP_COLORS[2].rgbBlue = 0XFF;
				SetDIBitsToDevice(
					MEMORY_DEVICE_CONTEXT,
					0,
					0,
					GRAPHIC->WIDTH,
					GRAPHIC->HEIGHT,
					0,
					0,
					0,
					GRAPHIC->WINDOW.HEIGHT,
					GRAPHIC->BUFFER,
					(BITMAPINFO *)&BITMAP_INFO,
					DIB_RGB_COLORS
				);
				StretchBlt(
					HANDLE_DEVICE_CONTEXT,
					0,
					0,
					GRAPHIC->WINDOW.WIDTH,
					GRAPHIC->WINDOW.HEIGHT,
					MEMORY_DEVICE_CONTEXT,
					0,
					0,
					GRAPHIC->WIDTH,
					GRAPHIC->HEIGHT,
					SRCCOPY
				);
				SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_OLD_BITMAP);
				DeleteObject(HANDLE_BITMAP);
				DeleteDC(MEMORY_DEVICE_CONTEXT);
				EndPaint(WINDOW_HANDLE, &PAINTSTRUCT);
			}

			break ;
		}
		case (WM_CLOSE): // CLICKING "X" BUTTON // 0X0010
		{
			if (!!GRAPHIC->FUNCTION_CLOSE)
				GRAPHIC->FUNCTION_CLOSE(GRAPHIC->FUNCTION_CLOSE_ARG);
			else
				WINDOW_CLOSE(GRAPHIC);

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
					GRAPHIC->KEY.BACKSPACE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (9):
				{
					GRAPHIC->KEY.TAB = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (13):
				{
					GRAPHIC->KEY.ENTER = !((L_PARAM >> 31) & 1);
					KEY = 10;
					break ;
				}
				case (16):
				{
					GRAPHIC->KEY.SHIFT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (17):
				{
					GRAPHIC->KEY.CTRL = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (18):
				{
					GRAPHIC->KEY.ALT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (19):
				{
					GRAPHIC->KEY.PAUSE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (20):
				{
					GRAPHIC->KEY.CAPSLOCK = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (27):
				{
					GRAPHIC->KEY.ESC = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (32):
				{
					GRAPHIC->KEY.SPACEBAR = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (33):
				{
					GRAPHIC->KEY.PAGE_UP = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (34):
				{
					GRAPHIC->KEY.PAGE_DOWN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (35):
				{
					GRAPHIC->KEY.END = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (36):
				{
					GRAPHIC->KEY.HOME = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (37):
				{
					GRAPHIC->KEY.ARROW_LEFT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (38):
				{
					GRAPHIC->KEY.ARROW_UP = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (39):
				{
					GRAPHIC->KEY.ARROW_RIGHT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (40):
				{
					GRAPHIC->KEY.ARROW_DOWN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (44):
				{
					GRAPHIC->KEY.PRTSC = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (45):
				{
					GRAPHIC->KEY.INSERT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (46):
				{
					GRAPHIC->KEY.DEL = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (47):
				{
					GRAPHIC->KEY.HELP = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (48):
				{
					GRAPHIC->KEY._0 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (49):
				{
					GRAPHIC->KEY._1 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (50):
				{
					GRAPHIC->KEY._2 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (51):
				{
					GRAPHIC->KEY._3 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (52):
				{
					GRAPHIC->KEY._4 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (53):
				{
					GRAPHIC->KEY._5 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (54):
				{
					GRAPHIC->KEY._6 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (55):
				{
					GRAPHIC->KEY._7 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (56):
				{
					GRAPHIC->KEY._8 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (57):
				{
					GRAPHIC->KEY._9 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (65):
				{
					GRAPHIC->KEY.A = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (66):
				{
					GRAPHIC->KEY.B = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (67):
				{
					GRAPHIC->KEY.C = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (68):
				{
					GRAPHIC->KEY.D = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (69):
				{
					GRAPHIC->KEY.E = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (70):
				{
					GRAPHIC->KEY.F = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (71):
				{
					GRAPHIC->KEY.G = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (72):
				{
					GRAPHIC->KEY.H = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (73):
				{
					GRAPHIC->KEY.I = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (74):
				{
					GRAPHIC->KEY.J = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (75):
				{
					GRAPHIC->KEY.K = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (76):
				{
					GRAPHIC->KEY.L = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (77):
				{
					GRAPHIC->KEY.M = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (78):
				{
					GRAPHIC->KEY.N = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (79):
				{
					GRAPHIC->KEY.O = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (80):
				{
					GRAPHIC->KEY.P = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (81):
				{
					GRAPHIC->KEY.Q = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (82):
				{
					GRAPHIC->KEY.R = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (83):
				{
					GRAPHIC->KEY.S = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (84):
				{
					GRAPHIC->KEY.T = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (85):
				{
					GRAPHIC->KEY.U = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (86):
				{
					GRAPHIC->KEY.V = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (87):
				{
					GRAPHIC->KEY.W = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (88):
				{
					GRAPHIC->KEY.X = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (89):
				{
					GRAPHIC->KEY.Y = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (90):
				{
					GRAPHIC->KEY.Z = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (91):
				case (92):
				{
					GRAPHIC->KEY.WIN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (112):
				{
					GRAPHIC->KEY.F1 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (113):
				{
					GRAPHIC->KEY.F2 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (114):
				{
					GRAPHIC->KEY.F3 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (115):
				{
					GRAPHIC->KEY.F4 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (116):
				{
					GRAPHIC->KEY.F5 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (117):
				{
					GRAPHIC->KEY.F6 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (118):
				{
					GRAPHIC->KEY.F7 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (119):
				{
					GRAPHIC->KEY.F8 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (120):
				{
					GRAPHIC->KEY.F9 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (121):
				{
					GRAPHIC->KEY.F10 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (122):
				{
					GRAPHIC->KEY.F11 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (123):
				{
					GRAPHIC->KEY.F12 = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (186):
				{
					GRAPHIC->KEY.SEMICOLON = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (187):
				{
					GRAPHIC->KEY.EQUAL = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (188):
				{
					GRAPHIC->KEY.COMMA = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (189):
				{
					GRAPHIC->KEY.MINUS = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (190):
				{
					GRAPHIC->KEY.DOT = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (191):
				{
					GRAPHIC->KEY.SLASH = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (192):
				{
					GRAPHIC->KEY.GRAVE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (219):
				{
					GRAPHIC->KEY.LEFT_BRACKET = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (220):
				{
					GRAPHIC->KEY.BACKSLASH = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (221):
				{
					GRAPHIC->KEY.RIGHT_BRACKET = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (222):
				{
					GRAPHIC->KEY.APOSTROPHE = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (223):
				{
					GRAPHIC->KEY.SELECTION_SIGN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (226):
				{
					GRAPHIC->KEY.SELECTION_SIGN = !((L_PARAM >> 31) & 1);
					break ;
				}
				case (255):
				{
					GRAPHIC->KEY.FN = !((L_PARAM >> 31) & 1);
					break ;
				}
			}

			if (GRAPHIC->KEY.DOWN)
				GRAPHIC->KEY.DOWN = 0;

			if (GRAPHIC->KEY.UP)
				GRAPHIC->KEY.UP = 0;

			if (MSG == WM_KEYDOWN)
			{
				GRAPHIC->KEY.DOWN = KEY;
				if (!!GRAPHIC->FUNCTION_KEY_DOWN)
				{
					GRAPHIC->FUNCTION_KEY_DOWN(
						GRAPHIC->KEY.DOWN,
						GRAPHIC->FUNCTION_KEY_DOWN_ARG
					);
				}
			}
			else // KEY UP
			{
				GRAPHIC->KEY.UP = KEY;
				if (!!GRAPHIC->FUNCTION_KEY_UP)
				{
					GRAPHIC->FUNCTION_KEY_UP(
						GRAPHIC->KEY.UP,
						GRAPHIC->FUNCTION_KEY_UP_ARG
					);
				}
			}

			break ;
		}
		case (WM_MOUSEMOVE): // 0X0200
		{
			GRAPHIC->MOUSE.Y = HIWORD(L_PARAM);
			GRAPHIC->MOUSE.X = LOWORD(L_PARAM);

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
		case (WM_LBUTTONDOWN): // 0X0201
		{
			GRAPHIC->MOUSE.LEFT_DOWN = 1;
			GRAPHIC->MOUSE.VALUE = 1;

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
		case (WM_LBUTTONUP): // 0X0202
		{
			GRAPHIC->MOUSE.LEFT_DOWN = 0;
			GRAPHIC->MOUSE.LEFT_UP = 1;
			break ;
		}
		case (WM_RBUTTONDOWN): // 0X0204
		{
			GRAPHIC->MOUSE.RIGHT_DOWN = 1;
			GRAPHIC->MOUSE.VALUE = 2;

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
		case (WM_RBUTTONUP): // 0X0205
		{
			GRAPHIC->MOUSE.RIGHT_DOWN = 0;
			GRAPHIC->MOUSE.RIGHT_UP = 1;
			break ;
		}
		case (WM_MBUTTONDOWN): // 0X0207
		{
			GRAPHIC->MOUSE.MIDDLE_DOWN = 1;
			GRAPHIC->MOUSE.VALUE = 3;

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
		case (WM_MBUTTONUP): // 0X0208
		{
			GRAPHIC->MOUSE.MIDDLE_DOWN = 0;
			GRAPHIC->MOUSE.MIDDLE_UP = 1;
			break ;
		}
		case (WM_MOUSEWHEEL): // 0X020A
		{
			if (GRAPHIC->KEY.SHIFT)
			{
				GRAPHIC->MOUSE.HORIZANTAL_WHEEL =
					GET_WHEEL_DELTA_WPARAM(W_PARAM);

				if (GRAPHIC->MOUSE.HORIZANTAL_WHEEL < 0)
					GRAPHIC->MOUSE.VALUE = 6;
				else
					GRAPHIC->MOUSE.VALUE = 7;

				if (!!GRAPHIC->FUNCTION_MOUSE)
				{
					GRAPHIC->FUNCTION_MOUSE(
						GRAPHIC->MOUSE.X,
						GRAPHIC->MOUSE.Y,
						GRAPHIC->MOUSE.VALUE,
						GRAPHIC->FUNCTION_MOUSE_ARG
					);
				}
			}
			else
			{
				GRAPHIC->MOUSE.WHEEL = GET_WHEEL_DELTA_WPARAM(W_PARAM);

				if (GRAPHIC->MOUSE.WHEEL < 0)
					GRAPHIC->MOUSE.VALUE = 4;
				else
					GRAPHIC->MOUSE.VALUE = 5;

				if (!!GRAPHIC->FUNCTION_MOUSE)
				{
					GRAPHIC->FUNCTION_MOUSE(
						GRAPHIC->MOUSE.X,
						GRAPHIC->MOUSE.Y,
						GRAPHIC->MOUSE.VALUE,
						GRAPHIC->FUNCTION_MOUSE_ARG
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
	IGNORE	ARG;

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_C */
