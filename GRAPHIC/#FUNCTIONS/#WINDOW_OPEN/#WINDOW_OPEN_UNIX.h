/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_OPEN_UNIX        #       Maximum Tension       #
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
#	   void WINDOW_CLOSE(struct GRAPHIC *);
#	        */
#	include <stdlib.h> /*
#	typedef size_t;
#	   void *malloc(size_t);
#	        */
#	include "../../LIBCMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
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
#	typedef XSetWindowAttributes
#	typedef XSizeHints
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
#	   void XSetWMNormalHints(Display *, Window, XSizeHints *);
#	    int XSetTransientForHint(Display *, Window, Window);
#	    int XSetInputFocus(Display *, Window, int, Time);
#	   Atom XInternAtom(Display *, char *, Bool);
#	    int XChangeProperty(Display *, Window, Atom, Atom, int, int, uchar *,
>	        	int);
#	 Status XIconifyWindow(Display *, Window, int);
#	 Status XSetWMProtocols(Display *, Window, Atom *, int);
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
	WINDOW_OPEN(
	struct GRAPHIC *GRAPHIC,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
{
	register int			SCREEN;
	register unsigned long	WINDOW_ATTRIBUTES;
	XSetWindowAttributes	X_WINDOW_ATTRIBUTES;
	XSizeHints				SIZE_HINTS;
	Atom					WM_DELETE;

	if (!GRAPHIC || !GRAPHIC->TITLE)
		return (-1);

	GRAPHIC->BUFFER = (unsigned int *)
		malloc(sizeof(unsigned int) * (WIDTH * HEIGHT + 1));

	if (!GRAPHIC->BUFFER)
		return (-2);

	PREFETCH_RANGE(GRAPHIC->BUFFER, WIDTH * HEIGHT);
	WINDOW_ATTRIBUTES = (unsigned long)0;
	GRAPHIC->WIDTH = WIDTH;
	GRAPHIC->HEIGHT = HEIGHT;
	GRAPHIC->WINDOW.WIDTH = WIDTH;
	GRAPHIC->WINDOW.HEIGHT = HEIGHT;
	GRAPHIC->DISPLAY = XOpenDisplay(NULL);
	SIZE_HINTS.flags = PMinSize | PMaxSize;

	if (!GRAPHIC->DISPLAY)
	{
		WINDOW_CLOSE(GRAPHIC);
		return (-3);
	}

	memset(&X_WINDOW_ATTRIBUTES, 0, sizeof(XSetWindowAttributes));
	SCREEN = DefaultScreen(GRAPHIC->DISPLAY);
	X_WINDOW_ATTRIBUTES.event_mask |= StructureNotifyMask;

	if (GRAPHIC->WINDOW.TRANSPARENCY)
	{
		WINDOW_ATTRIBUTES |= CWBackPixel;
		X_WINDOW_ATTRIBUTES.background_pixel = 0;
	}
	else
	{
		X_WINDOW_ATTRIBUTES.background_pixel =
			WhitePixel(GRAPHIC->DISPLAY, SCREEN);
	}

	if (!GRAPHIC->WINDOW.BORDER)
	{
		WINDOW_ATTRIBUTES |= CWBorderPixel;
		X_WINDOW_ATTRIBUTES.border_pixel = 0;
	}
	else
		X_WINDOW_ATTRIBUTES.border_pixel = BlackPixel(GRAPHIC->DISPLAY, SCREEN);

	if (!GRAPHIC->WINDOW.RESIZABLE)
	{
		SIZE_HINTS.min_width = GRAPHIC->WINDOW.WIDTH;
		SIZE_HINTS.max_width = GRAPHIC->WINDOW.WIDTH;
		SIZE_HINTS.min_height = GRAPHIC->WINDOW.HEIGHT;
		SIZE_HINTS.max_height = GRAPHIC->WINDOW.HEIGHT;
	}

	if (GRAPHIC->WINDOW.TOPMOST)
	{
		WINDOW_ATTRIBUTES |= CWOverrideRedirect;
		X_WINDOW_ATTRIBUTES.override_redirect = 1;
	}

	XSetWMNormalHints(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, &SIZE_HINTS);
	GRAPHIC->WINDOW = XCreateWindow(
		GRAPHIC->DISPLAY,
		RootWindow(GRAPHIC->DISPLAY, SCREEN),
		0,
		0,
		GRAPHIC->WINDOW.WIDTH,
		GRAPHIC->WINDOW.HEIGHT,
		0,
		CopyFromParent,
		InputOutput,
		CopyFromParent,
		WINDOW_ATTRIBUTES,
		&X_WINDOW_ATTRIBUTES
	);

	if (!GRAPHIC->WINDOW)
	{
		WINDOW_CLOSE(GRAPHIC);
		return (-4);
	}

	GRAPHIC->GRAPHICS_CONTEXT = XCreateGC(
		GRAPHIC->DISPLAY,
		GRAPHIC->WINDOW,
		0,
		0
	);

	if (!GRAPHIC->GRAPHICS_CONTEXT)
	{
		WINDOW_CLOSE(GRAPHIC);
		return (-5);		
	}

	XSelectInput(
		GRAPHIC->DISPLAY,
		GRAPHIC->WINDOW,
		(
			ExposureMask |
			KeyPressMask |
			KeyReleaseMask |
			ButtonPressMask |
			ButtonReleaseMask |
			PointerMotionMask
		)
	);
	XStoreName(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, GRAPHIC->TITLE);

	if (GRAPHIC->WINDOW.TOOLWINDOW)
	{
		XSetTransientForHint(
			GRAPHIC->DISPLAY,
			GRAPHIC->WINDOW,
			RootWindow(GRAPHIC->DISPLAY, SCREEN)
		);
	}

	WM_DELETE = XInternAtom(GRAPHIC->DISPLAY, "WM_DELETE_WINDOW", 0);
	XSetWMProtocols(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, &WM_DELETE, 1);

	if (GRAPHIC->WINDOW.MINIMIZABLE)
		XIconifyWindow(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, SCREEN);

	if (GRAPHIC->WINDOW.MAXIMIZABLE)
	{
		union U_ATOM_TO_UCHAR__CONVERT	CONVERT;
		Atom							NET_WM_STATE;
		Atom							NET_WM_STATE_MAXIMIZED_HORZ;
		Atom							NET_WM_STATE_MAXIMIZED_VERT;

		NET_WM_STATE = XInternAtom(GRAPHIC->DISPLAY, "_NET_WM_STATE", 0);
		NET_WM_STATE_MAXIMIZED_HORZ = XInternAtom(
			GRAPHIC->DISPLAY,
			"_NET_WM_STATE_MAXIMIZED_HORZ",
			0
		);
		NET_WM_STATE_MAXIMIZED_VERT = XInternAtom(
			GRAPHIC->DISPLAY,
			"_NET_WM_STATE_MAXIMIZED_VERT",
			0
		);
		CONVERT.ATOM = &NET_WM_STATE_MAXIMIZED_HORZ;
		XChangeProperty(
			GRAPHIC->DISPLAY,
			GRAPHIC->WINDOW,
			NET_WM_STATE,
			XA_ATOM,
			32,
			PropModeReplace,
			CONVERT.BYTE,
			1
		);
		CONVERT.ATOM = &NET_WM_STATE_MAXIMIZED_VERT;
		XChangeProperty(
			GRAPHIC->DISPLAY,
			GRAPHIC->WINDOW,
			NET_WM_STATE,
			XA_ATOM,
			32,
			PropModeReplace,
			CONVERT.BYTE,
			1
		);
	}

	if (GRAPHIC->WINDOW.FOCUSABLE)
	{
		XSetInputFocus(
			GRAPHIC->DISPLAY,
			GRAPHIC->WINDOW,
			RevertToParent,
			CurrentTime
		);
	}

	if (!GRAPHIC->WINDOW.HIDEONCREATE)
		XMapWindow(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);

	XSync(GRAPHIC->DISPLAY, 0);
	GRAPHIC->IMAGE = XCreateImage(
		GRAPHIC->DISPLAY,
		DefaultVisual(GRAPHIC->DISPLAY, 0),
		24,
		ZPixmap,
		0,
		(char *)GRAPHIC->BUFFER,
		GRAPHIC->WINDOW.WIDTH,
		GRAPHIC->WINDOW.HEIGHT,
		32,
		0
	);

	if (!GRAPHIC->IMAGE)
	{
		WINDOW_CLOSE(GRAPHIC);
		return (-6);
	}

	return (0);
}

#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_C */
