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
# : License - APACHE 2  :: Update - 2024/05/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_OPEN_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	   void free(void *);
#	        */
#	include "../../CMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
#	        */
#	include <X11/Xlib.h> /*
#	 define DefaultScreen(dpy)
#	 define RootWindow(dpy, scr)
#	 define BlackPixel(dpy, scr)
#	 define WhitePixel(dpy, scr)
#	 define DefaultVisual(dpy, scr)
#	Display *XOpenDisplay(char *);
#	 Window XCreateSimpleWindow(Display *, Window, int, int, uint, uint, uint,
>	        ulong, ulong);
#	     GC XCreateGC(Display *, Drawable, ulong, XGCValues *);
#	    int XSelectInput(Display *, Window, long);
#	    int XStoreName(Display *, Window, char *);
#	    int XMapWindow(Display *, Window);
#	    int XSync(Display *, Bool);
#	 XImage *XCreateImage(Display *, Visual *, uint, int, int, char *, uint,
>	        uint, int, int);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC, register unsigned int WIDTH, \
register unsigned int HEIGHT)
{
	register int (SCREEN);

	GRAPHIC->BUFFER = (unsigned int *)malloc(\
		sizeof(unsigned int) * (WIDTH * HEIGHT + 1)\
	);

	if (!GRAPHIC->BUFFER)
		return (-1);

	PREFETCH_RANGE(GRAPHIC->BUFFER, WIDTH * HEIGHT);
	GRAPHIC->WIDTH = WIDTH;
	GRAPHIC->HEIGHT = HEIGHT;
	GRAPHIC->DISPLAY = XOpenDisplay(NULL);
	SCREEN = DefaultScreen(GRAPHIC->DISPLAY);
	GRAPHIC->WINDOW = XCreateSimpleWindow(\
		GRAPHIC->DISPLAY, \
		RootWindow(GRAPHIC->DISPLAY, SCREEN), \
		0, \
		0, \
		GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, \
		0, \
		BlackPixel(GRAPHIC->DISPLAY, SCREEN), \
		WhitePixel(GRAPHIC->DISPLAY, SCREEN)\
	);
	GRAPHIC->GRAPHICS_CONTEXT = XCreateGC(\
		GRAPHIC->DISPLAY, \
		GRAPHIC->WINDOW, \
		0, \
		0\
	);
	XSelectInput(\
		GRAPHIC->DISPLAY, \
		GRAPHIC->WINDOW, \
		(\
			ExposureMask | \
			KeyPressMask | \
			KeyReleaseMask | \
			ButtonPressMask | \
			ButtonReleaseMask | \
			PointerMotionMask
		)\
	);
	XStoreName(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, GRAPHIC->TITLE);
	XMapWindow(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
	XSync(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
	GRAPHIC->IMAGE = XCreateImage(\
		GRAPHIC->DISPLAY, \
		DefaultVisual(GRAPHIC->DISPLAY, 0), \
		24, \
		ZPixmap, \
		0, \
		(char *)GRAPHIC->BUFFER, \
		GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, \
		32, \
		0\
	);

	if (!GRAPHIC->IMAGE)
	{
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_H */
