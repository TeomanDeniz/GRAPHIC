/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/CREATE_WINDOW__X11  #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../LIBCGFX.h" /*
#	 struct S_APP;
#	   void CLOSE_WINDOW(struct S_APP *);
#	        */
#	include "../../../LIBCMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *, uint);
#	        */
#	include <stdlib.h> /*
#	typedef size_t;
#	   void *malloc(size_t);
#	        */
#	include <X11/Xlib.h> /*
#	 define DefaultScreen(dpy)
#	 define RootWindow(dpy, scr)
#	 define BlackPixel(dpy, scr)
#	 define WhitePixel(dpy, scr)
#	 define DefaultVisual(dpy, scr)
#	 define CWBackPixel
#	 define CWBorderPixel
#	 define CWOverrideRedirect
#	 define StructureNotifyMask
#	 define CopyFromParent
#	 define InputOutput
#	 define ZPixmap
#	 define ExposureMask
#	 define KeyPressMask
#	 define KeyReleaseMask
#	 define ButtonPressMask
#	 define ButtonReleaseMask
#	 define PointerMotionMask
#	 define PMinSize
#	 define PMaxSize
#	 define CurrentTime
#	 define PropModeReplace
#	 define RevertToParent
#	typedef XSetWindowAttributes;
#	Display *XOpenDisplay(char *);
#	 Window XCreateWindow(Display *, Window, int, int, uint, uint, uint,
>	        	int, uint, Visual *, ulong, XSetWindowAttributes *);
#	     GC XCreateGC(Display *, Drawable, ulong, XGCValues *);
#	    int XSelectInput(Display *, Window, long);
#	    int XStoreName(Display *, Window, char *);
#	    int XMapWindow(Display *, Window);
#	    int XSync(Display *, Bool);
#	 XImage *XCreateImage(Display *, Visual *, uint, int, int, char *, uint,
>	        	uint, int, int);
#	    int XSetTransientForHint(Display *, Window, Window);
#	    int XSetInputFocus(Display *, Window, int, Time);
#	   Atom XInternAtom(Display *, char *, Bool);
#	    int XChangeProperty(Display *, Window, Atom, Atom, int, int, uchar *,
>	        	int);
#	 Status XIconifyWindow(Display *, Window, int);
#	 Status XSetWMProtocols(Display *, Window, Atom *, int);
#	        */
#	include <X11/Xutil.h> /*
#	typedef XSizeHints;
#	   void XSetWMNormalHints(Display *, Window, XSizeHints *);
#	        */
#	include <X11/Xatom.h> /*
#	 define XA_ATOM
#	typedef Atom;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern void	*memset(void *, int, size_t);
/* *************************** [^] PROTOTYPES [^] *************************** */

/* ***************************** [v] UNIONS [v] ***************************** */
union U_ATOM_TO_UCHAR__CONVERT
{
	Atom			*ATOM;
	unsigned char	*BYTE;
};
/* ***************************** [^] UNIONS [^] ***************************** */

int
	CREATE_WINDOW(
	struct S_APP *APP,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
{
	register int			SCREEN;
	register unsigned long	WINDOW_ATTRIBUTES;
	XSetWindowAttributes	X_WINDOW_ATTRIBUTES;
	XSizeHints				SIZE_HINTS;
	Atom					WM_DELETE;

	if (!APP || !APP->WINDOW.TITLE)
		return (-1);

	APP->BUFFER = (unsigned int *)
		malloc(sizeof(unsigned int) * (WIDTH * HEIGHT + 1));

	if (!APP->BUFFER)
		return (-2);

	PREFETCH_RANGE(APP->BUFFER, WIDTH * HEIGHT);
	WINDOW_ATTRIBUTES = (unsigned long)0;
	APP->WIDTH = WIDTH;
	APP->HEIGHT = HEIGHT;
	APP->WINDOW.WIDTH = WIDTH;
	APP->WINDOW.HEIGHT = HEIGHT;
	APP->DISPLAY = XOpenDisplay(NULL);
	SIZE_HINTS.flags = PMinSize | PMaxSize;

	if (!APP->DISPLAY)
	{
		CLOSE_WINDOW(APP);
		return (-3);
	}

	memset(&X_WINDOW_ATTRIBUTES, 0, sizeof(XSetWindowAttributes));
	SCREEN = DefaultScreen(APP->DISPLAY);
	X_WINDOW_ATTRIBUTES.event_mask |= StructureNotifyMask;

	if (APP->WINDOW.TRANSPARENCY)
	{
		WINDOW_ATTRIBUTES |= CWBackPixel;
		X_WINDOW_ATTRIBUTES.background_pixel = 0;
	}
	else
	{
		X_WINDOW_ATTRIBUTES.background_pixel =
			WhitePixel(APP->DISPLAY, SCREEN);
	}

	if (!APP->WINDOW.BORDER)
	{
		WINDOW_ATTRIBUTES |= CWBorderPixel;
		X_WINDOW_ATTRIBUTES.border_pixel = 0;
	}
	else
		X_WINDOW_ATTRIBUTES.border_pixel = BlackPixel(APP->DISPLAY, SCREEN);

	if (!APP->WINDOW.RESIZABLE)
	{
		SIZE_HINTS.min_width = APP->WINDOW.WIDTH;
		SIZE_HINTS.max_width = APP->WINDOW.WIDTH;
		SIZE_HINTS.min_height = APP->WINDOW.HEIGHT;
		SIZE_HINTS.max_height = APP->WINDOW.HEIGHT;
	}

	if (APP->WINDOW.TOPMOST)
	{
		WINDOW_ATTRIBUTES |= CWOverrideRedirect;
		X_WINDOW_ATTRIBUTES.override_redirect = 1;
	}

	APP->XWINDOW = XCreateWindow(
		APP->DISPLAY,
		RootWindow(APP->DISPLAY, SCREEN),
		0,
		0,
		APP->WINDOW.WIDTH,
		APP->WINDOW.HEIGHT,
		0,
		CopyFromParent,
		InputOutput,
		CopyFromParent,
		WINDOW_ATTRIBUTES,
		&X_WINDOW_ATTRIBUTES
	);

	if (!APP->XWINDOW)
	{
		CLOSE_WINDOW(APP);
		return (-4);
	}

	XSetWMNormalHints(APP->DISPLAY, APP->XWINDOW, &SIZE_HINTS);
	APP->GRAPHICS_CONTEXT = XCreateGC(
		APP->DISPLAY,
		APP->XWINDOW,
		0,
		0
	);

	if (!APP->GRAPHICS_CONTEXT)
	{
		CLOSE_WINDOW(APP);
		return (-5);		
	}

	XSelectInput(
		APP->DISPLAY,
		APP->XWINDOW,
		(
			ExposureMask |
			KeyPressMask |
			KeyReleaseMask |
			ButtonPressMask |
			ButtonReleaseMask |
			PointerMotionMask
		)
	);
	XStoreName(APP->DISPLAY, APP->XWINDOW, APP->WINDOW.TITLE);

	if (APP->WINDOW.TOOLWINDOW)
	{
		XSetTransientForHint(
			APP->DISPLAY,
			APP->XWINDOW,
			RootWindow(APP->DISPLAY, SCREEN)
		);
	}

	WM_DELETE = XInternAtom(APP->DISPLAY, "WM_DELETE_WINDOW", 0);
	XSetWMProtocols(APP->DISPLAY, APP->XWINDOW, &WM_DELETE, 1);

	if (APP->WINDOW.MINIMIZABLE)
		XIconifyWindow(APP->DISPLAY, APP->XWINDOW, SCREEN);

	if (APP->WINDOW.MAXIMIZABLE)
	{
		union U_ATOM_TO_UCHAR__CONVERT	CONVERT;
		Atom							NET_WM_STATE;
		Atom							NET_WM_STATE_MAXIMIZED_HORZ;
		Atom							NET_WM_STATE_MAXIMIZED_VERT;

		NET_WM_STATE = XInternAtom(APP->DISPLAY, "_NET_WM_STATE", 0);
		NET_WM_STATE_MAXIMIZED_HORZ = XInternAtom(
			APP->DISPLAY,
			"_NET_WM_STATE_MAXIMIZED_HORZ",
			0
		);
		NET_WM_STATE_MAXIMIZED_VERT = XInternAtom(
			APP->DISPLAY,
			"_NET_WM_STATE_MAXIMIZED_VERT",
			0
		);
		CONVERT.ATOM = &NET_WM_STATE_MAXIMIZED_HORZ;
		XChangeProperty(
			APP->DISPLAY,
			APP->XWINDOW,
			NET_WM_STATE,
			XA_ATOM,
			32,
			PropModeReplace,
			CONVERT.BYTE,
			1
		);
		CONVERT.ATOM = &NET_WM_STATE_MAXIMIZED_VERT;
		XChangeProperty(
			APP->DISPLAY,
			APP->XWINDOW,
			NET_WM_STATE,
			XA_ATOM,
			32,
			PropModeReplace,
			CONVERT.BYTE,
			1
		);
	}

	if (!APP->WINDOW.HIDEONCREATE)
		XMapWindow(APP->DISPLAY, APP->XWINDOW);

	XSync(APP->DISPLAY, 0);
	APP->IMAGE = XCreateImage(
		APP->DISPLAY,
		DefaultVisual(APP->DISPLAY, 0),
		24,
		ZPixmap,
		0,
		(char *)APP->BUFFER,
		APP->WINDOW.WIDTH,
		APP->WINDOW.HEIGHT,
		32,
		0
	);

	if (!APP->IMAGE)
	{
		CLOSE_WINDOW(APP);
		return (-6);
	}

	/*
	if (APP->WINDOW.FOCUSABLE)
	{
		XSetInputFocus(
			APP->DISPLAY,
			APP->XWINDOW,
			RevertToParent,
			CurrentTime
		);
	}
	*/

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C */
