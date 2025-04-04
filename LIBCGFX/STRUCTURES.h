/******************************************************************************\
# H - LIBCGFX/STRUCTURES                         #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/04/26 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************
 * ____ ____ ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ *
 *||K |||E |||Y |||B |||O |||A |||R |||D |||       |||I |||N |||P |||U |||T ||*
 *||__|||__|||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__||*
 *|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|*
 ******************************************************************************/

#ifndef LIBCGFX_STRUCTURES_H
#	define LIBCGFX_STRUCTURES_H 202504
/* **************************** [v] INCLUDES [v] **************************** */
#	ifdef __APPLE__
#		include <objc/NSObjCRuntime.h> /*
#		typedef id;
#		        */
#		include <CoreGraphics/CoreGraphics.h> /*
#		typedef CGRect;
#		        */
#		ifdef __APPLE_OPENGL__
#			include <OpenGL/gl3.h> /*
#			typedef GLuint;
#			        */
#			include <OpenGL/OpenGL.h> /*
#			typedef CGLContextObj;
#			        */
#		else /* CORE GRAPHICS */
#			include <pthread.h> /*
#			typedef pthread_mutex_t;
#			typedef pthread_t;
#			        */
#		endif /* __APPLE_OPENGL__ */
#	else
#		ifdef _WIN32
#			include <windows.h> /*
#			typedef HWND;
#			    int SetWindowText(HWND, LPCSTR);
#			        */
#		else /* UNIX (PROBABLY) */
#			if (defined(__linux__) || defined(__gnu_linux__) || \
				defined(__FreeBSD__) || defined(__NetBSD__) || \
				defined(__OpenBSD__) || defined(__DragonFly__) || \
				defined(__sun)) /* __sun IS SOLARIS SYSTEMS */
#				include <X11/Xlib.h> /*
#				typedef Display;
#				typedef GC;
#				typedef XImage;
#				        */
#			endif /* UNIX */
#		endif /* WINDOWS */
#	endif /* APPLE */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************** [v] struct S_KEY [v] ************************** */
struct	S_KEY // IT'S ONLY 14 BYTES LOL ;-)
{
	/* [v] ALPHABETIC ------------------------------------------------------- */
	unsigned char	A : 1;
	unsigned char	B : 1;
	unsigned char	C : 1;
	unsigned char	D : 1;
	unsigned char	E : 1;
	unsigned char	F : 1;
	unsigned char	G : 1;
	unsigned char	H : 1;
	unsigned char	I : 1;
	unsigned char	J : 1;
	unsigned char	K : 1;
	unsigned char	L : 1;
	unsigned char	M : 1;
	unsigned char	N : 1;
	unsigned char	O : 1;
	unsigned char	P : 1;
	unsigned char	Q : 1;
	unsigned char	R : 1;
	unsigned char	S : 1;
	unsigned char	T : 1;
	unsigned char	U : 1;
	unsigned char	V : 1;
	unsigned char	W : 1;
	unsigned char	X : 1;
	unsigned char	Y : 1;
	unsigned char	Z : 1;
	/* [^] ALPHABETIC ------------------------------------------------------- */

	/* [v] NUMERIC ---------------------------------------------------------- */
	unsigned char	_1 : 1;
	unsigned char	_2 : 1;
	unsigned char	_3 : 1;
	unsigned char	_4 : 1;
	unsigned char	_5 : 1;
	unsigned char	_6 : 1;
	unsigned char	_7 : 1;
	unsigned char	_8 : 1;
	unsigned char	_9 : 1;
	unsigned char	_0 : 1;
	/* [^] NUMERIC ---------------------------------------------------------- */

	/* [v] FN KEYS ---------------------------------------------------------- */
	unsigned char	F1 : 1;
	unsigned char	F2 : 1;
	unsigned char	F3 : 1;
	unsigned char	F4 : 1;
	unsigned char	F5 : 1;
	unsigned char	F6 : 1;
	unsigned char	F7 : 1;
	unsigned char	F8 : 1;
	unsigned char	F9 : 1;
	unsigned char	F10 : 1;
	unsigned char	F11 : 1;
	unsigned char	F12 : 1;
	/* [^] FN KEYS ---------------------------------------------------------- */

	/* [v] OTHER KEYS ------------------------------------------------------- */
	unsigned char	EQUAL : 1; // =
	unsigned char	MINUS : 1; // -
	unsigned char	SLASH : 1; // /
	unsigned char	BACKSLASH : 1; // Ugh... "/" but mirrored lol
	unsigned char	PLUS : 1; // +
	unsigned char	ASTERISK : 1; // *
	unsigned char	DOT : 1; // .
	unsigned char	GRAVE : 1; // `
	unsigned char	COMMA : 1; // ,
	unsigned char	SEMICOLON : 1; // ;
	unsigned char	APOSTROPHE : 1; // '
	unsigned char	LEFT_BRACKET : 1; // [
	unsigned char	RIGHT_BRACKET : 1; // ]
	unsigned char	SELECTION_SIGN : 1; // §
	/* [^] OTHER KEYS ------------------------------------------------------- */

	/* [v] CONTROL KEYS ----------------------------------------------------- */
	unsigned char	ESC : 1;
	unsigned char	DEL : 1;
	unsigned char	ENTER : 1;
	unsigned char	TAB : 1;
	unsigned char	PAGE_DOWN : 1;
	unsigned char	PAGE_UP : 1;
	unsigned char	END : 1;
	unsigned char	HOME : 1;
	unsigned char	HELP : 1;
	unsigned char	BACKSPACE : 1;
	unsigned char	PRTSC : 1; // WINDOWS
	unsigned char	PAUSE : 1; // WINDOWS
	unsigned char	SPACEBAR : 1;
	unsigned char	SPACE : 1;
	/* [^] CONTROL KEYS ----------------------------------------------------- */

	/* [v] ARROW KEYS ------------------------------------------------------- */
	unsigned char	ARROW_LEFT : 1;
	unsigned char	ARROW_RIGHT : 1;
	unsigned char	ARROW_DOWN : 1;
	unsigned char	ARROW_UP : 1;
	/* [^] ARROW KEYS ------------------------------------------------------- */

	/* [v] SPECIAL KEYS ----------------------------------------------------- */
	unsigned char	SHIFT : 1;
	unsigned char	CAPSLOCK : 1;
	unsigned char	INSERT : 1; // WINDOWS
	unsigned char	FN : 1;
	/* [^] SPECIAL KEYS ----------------------------------------------------- */

	/* [v] COMMAND KEYS (WINDOWS) ------------------------------------------- */
	unsigned char	CTRL : 1; // WINDOWS
	unsigned char	ALT : 1; // WINDOWS
	unsigned char	WIN : 1; // WINDOWS
	/* [^] COMMAND KEYS (WINDOWS) ------------------------------------------- */

	/* [v] COMMAND KEYS (MACOS) --------------------------------------------- */
	unsigned char	CONTROL : 1; // MACOS
	unsigned char	COMMAND : 1; // MACOS
	unsigned char	OPTION : 7; // MACOS
	/* [^] COMMAND KEYS (MACOS) --------------------------------------------- */
	unsigned char	DOWN; // Last key down
	unsigned char	UP; // Last key up
};
/* ************************** [^] struct S_KEY [^] ************************** */

/* ************************** [v] struct s_key [v] ************************** */
struct	s_key // It is 14 Bytes lol ;-)
{
	/* [v] ALPHABETIC ------------------------------------------------------- */
	unsigned char	a : 1;
	unsigned char	b : 1;
	unsigned char	c : 1;
	unsigned char	d : 1;
	unsigned char	e : 1;
	unsigned char	f : 1;
	unsigned char	g : 1;
	unsigned char	h : 1;
	unsigned char	i : 1;
	unsigned char	j : 1;
	unsigned char	k : 1;
	unsigned char	l : 1;
	unsigned char	m : 1;
	unsigned char	n : 1;
	unsigned char	o : 1;
	unsigned char	p : 1;
	unsigned char	q : 1;
	unsigned char	r : 1;
	unsigned char	s : 1;
	unsigned char	t : 1;
	unsigned char	u : 1;
	unsigned char	v : 1;
	unsigned char	w : 1;
	unsigned char	x : 1;
	unsigned char	y : 1;
	unsigned char	z : 1;
	/* [^] ALPHABETIC ------------------------------------------------------- */

	/* [v] NUMERIC ---------------------------------------------------------- */
	unsigned char	_1 : 1;
	unsigned char	_2 : 1;
	unsigned char	_3 : 1;
	unsigned char	_4 : 1;
	unsigned char	_5 : 1;
	unsigned char	_6 : 1;
	unsigned char	_7 : 1;
	unsigned char	_8 : 1;
	unsigned char	_9 : 1;
	unsigned char	_0 : 1;
	/* [^] NUMERIC ---------------------------------------------------------- */

	/* [v] FN KEYS ---------------------------------------------------------- */
	unsigned char	f1 : 1;
	unsigned char	f2 : 1;
	unsigned char	f3 : 1;
	unsigned char	f4 : 1;
	unsigned char	f5 : 1;
	unsigned char	f6 : 1;
	unsigned char	f7 : 1;
	unsigned char	f8 : 1;
	unsigned char	f9 : 1;
	unsigned char	f10 : 1;
	unsigned char	f11 : 1;
	unsigned char	f12 : 1;
	/* [^] FN KEYS ---------------------------------------------------------- */

	/* [v] OTHER KEYS ------------------------------------------------------- */
	unsigned char	equal : 1; // =
	unsigned char	minus : 1; // -
	unsigned char	slash : 1; // /
	unsigned char	backslash : 1; // Ugh... "/" but mirrored lol
	unsigned char	plus : 1; // +
	unsigned char	asterisk : 1; // *
	unsigned char	dot : 1; // .
	unsigned char	grave : 1; // `
	unsigned char	comma : 1; // ,
	unsigned char	semicolon : 1; // ;
	unsigned char	apostrophe : 1; // '
	unsigned char	left_bracket : 1; // [
	unsigned char	right_bracket : 1; // ]
	unsigned char	selection_sign : 1; // §
	/* [^] OTHER KEYS ------------------------------------------------------- */

	/* [v] CONTROL KEYS ----------------------------------------------------- */
	unsigned char	esc : 1;
	unsigned char	del : 1;
	unsigned char	enter : 1;
	unsigned char	tab : 1;
	unsigned char	page_down : 1;
	unsigned char	page_up : 1;
	unsigned char	end : 1;
	unsigned char	home : 1;
	unsigned char	help : 1;
	unsigned char	backspace : 1;
	unsigned char	prtsc : 1; // WINDOWS
	unsigned char	pause : 1; // WINDOWS
	unsigned char	spacebar : 1;
	unsigned char	space : 1;
	/* [^] CONTROL KEYS ----------------------------------------------------- */

	/* [v] ARROW KEYS ------------------------------------------------------- */
	unsigned char	arrow_left : 1;
	unsigned char	arrow_right : 1;
	unsigned char	arrow_down : 1;
	unsigned char	arrow_up : 1;
	/* [^] ARROW KEYS ------------------------------------------------------- */

	/* [v] SPECIAL KEYS ----------------------------------------------------- */
	unsigned char	shift : 1;
	unsigned char	capslock : 1;
	unsigned char	insert : 1; // WINDOWS
	unsigned char	fn : 1;
	/* [^] SPECIAL KEYS ----------------------------------------------------- */

	/* [v] COMMAND KEYS (WINDOWS) ------------------------------------------- */
	unsigned char	ctrl : 1; // WINDOWS
	unsigned char	alt : 1; // WINDOWS
	unsigned char	win : 1; // WINDOWS
	/* [^] COMMAND KEYS (WINDOWS) ------------------------------------------- */

	/* [v] COMMAND KEYS (MACOS) --------------------------------------------- */
	unsigned char	control : 1; // MACOS
	unsigned char	command : 1; // MACOS
	unsigned char	option : 7; // MACOS
	/* [^] COMMAND KEYS (MACOS) --------------------------------------------- */
	unsigned char	down; // Last key down
	unsigned char	up; // Last key up
};
/* ************************** [^] struct s_key [^] ************************** */

/* ************************* [v] struct S_MOUSE [v] ************************* */
struct	S_MOUSE
{
	unsigned char	LEFT_DOWN : 1;
	unsigned char	LEFT_UP : 1;
	unsigned char	RIGHT_DOWN : 1;
	unsigned char	RIGHT_UP : 1;
	unsigned char	MIDDLE_DOWN : 1;
	unsigned char	MIDDLE_UP : 3;
	int				WHEEL;
	int				HORIZANTAL_WHEEL;
	unsigned int	X;
	unsigned int	Y;
	unsigned char	VALUE;
};
/* ************************* [^] struct S_MOUSE [^] ************************* */

/* ************************* [v] struct s_mouse [v] ************************* */
struct	s_mouse
{
	unsigned char	left_down : 1;
	unsigned char	left_up : 1;
	unsigned char	right_down : 1;
	unsigned char	right_up : 1;
	unsigned char	middle_down : 1;
	unsigned char	middle_up : 3;
	int				wheel;
	int				horizantal_wheel;
	unsigned int	x;
	unsigned int	y;
	unsigned char	value;
};
/* ************************* [^] struct s_mouse [^] ************************* */

/* ************************ [v] struct S_WINDOW [v] ************************* */
struct	S_WINDOW
{
	char	*TITLE;
	int		WIDTH;
	int		HEIGHT;
	int		BORDER : 1;       // WINDOW HAS A BORDER
	int		TRANSPARENCY : 1; // WINDOW IS TRANSPARENT
	int		RESIZABLE : 1;    // WINDOW IS RESIZABLE
	int		MINIMIZABLE : 1;  // WINDOW CAN BE MINIMIZED
	int		MAXIMIZABLE : 1;  // WINDOW CAN BE MAXIMIZED
	int		CLOSEBUTTON : 1;  // CLOSE BUTTON IS ENABLED
	int		FOCUSABLE : 1;    // WINDOW IS FOCUSABLE
	int		TOPMOST : 1;      // WINDOW IS ALWAYS ON TOP
	int		TOOLWINDOW : 1;   // WINDOW IS A tool window
	int		HIDEONCREATE : 1; // WINDOW IS HIDDEN ON CREATION
	int		CLIENTEDGE : 22;  // WINDOW HAS A CLIENT EDGE(SUNKEN EFFECT)
};
/* ************************ [^] struct S_WINDOW [^] ************************* */

/* ************************ [v] struct s_window [v] ************************* */
struct	s_window
{
	char	*title;
	int		width;
	int		height;
	int		border : 1;       // WINDOW HAS A BORDER
	int		transparency : 1; // WINDOW IS TRANSPARENT
	int		resizable : 1;    // WINDOW IS RESIZABLE
	int		minimizable : 1;  // WINDOW CAN BE MINIMIZED
	int		maximizable : 1;  // WINDOW CAN BE MAXIMIZED
	int		closebutton : 1;  // CLOSE BUTTON IS ENABLED
	int		focusable : 1;    // WINDOW IS FOCUSABLE
	int		topmost : 1;      // WINDOW IS ALWAYS ON TOP
	int		toolwindow : 1;   // WINDOW IS A tool window
	int		hiddencreate : 1; // WINDOW IS HIDDEN ON CREATION
	int		clientedge : 22;  // WINDOW HAS A CLIENT EDGE(SUNKEN EFFECT)
};
/* ************************ [^] struct s_window [^] ************************* */

/* ************************** [v] struct S_APP [v] ************************** */
typedef struct	S_APP
{
	int						WIDTH;
	int						HEIGHT;
	unsigned int			*BUFFER;
	struct S_KEY			KEY;
	struct S_MOUSE			MOUSE;
	int						*GRAPHIC_ERRORLEVEL;
	int	(*FUNCTION_KEY_DOWN)(unsigned int, void *);
	void					*FUNCTION_KEY_DOWN_ARG;
	int	(*FUNCTION_KEY_UP)(unsigned int, void *);
	void					*FUNCTION_KEY_UP_ARG;
	int	(*FUNCTION_CLOSE)(void *);
	void					*FUNCTION_CLOSE_ARG;
	int	(*FUNCTION_LOOP)(void *);
	void					*FUNCTION_LOOP_ARG;
	int	(*FUNCTION_RESIZE)(void *);
	void					*FUNCTION_RESIZE_ARG;
	int	(*FUNCTION_MOUSE)(unsigned int, unsigned int, unsigned char, void *);
	void					*FUNCTION_MOUSE_ARG;
	unsigned int			FPS_START_TIME;
	unsigned int			FPS;
	char					WINDOW_RESIZING;
	struct S_WINDOW			WINDOW;
#	ifdef __APPLE__
	id						WINDOW_MODULE;
	id						EVENT;
	void					*TIMER_ID;
	void					*OBSERVER_ID;
	CGRect					CANVAS_INFO;
#		ifdef __APPLE_OPENGL__
	GLuint					PROGRAM;
	GLuint					VERTEX_BUFFER_OBJECT;
	GLuint					TEXTURE;
	CGLContextObj			CONTEXT;
#		else /* CORE GRAPHICS */
	// NOTE: IT'S SLOW! EVEN WITH FUCKING THREADS!!!! FUCK YOU MACOS!!!!
	pthread_mutex_t			CLOSE_THREAD_MUTEX;
	pthread_t				THREAD_UPDATE_WINDOW;
	CGColorSpaceRef			COLOR_SPACE;
	CGDataProviderRef		IMAGE_PROVIDER;
	char					CLOSE_THREAD; // BOOL
#		endif /* __APPLE_OPENGL__ */
#	else
#		ifdef _WIN32
	HWND					WINDOW_HANDLE;
	void	(*REFRESH_SCREEN)(const struct S_APP *const);
#		else /* UNIX */
	Display					*DISPLAY;
	Window					XWINDOW;
	GC						GRAPHICS_CONTEXT;
	XImage					*IMAGE;
#		endif /* WINDOWS */
#	endif /* APPLE */
}	T_APP;
/* ************************** [^] struct S_APP [^] ************************** */

/* ************************** [v] struct s_app [v] ************************** */
typedef struct	s_app
{
	int						width;
	int						height;
	unsigned int			*buffer;
	struct s_key			key;
	struct s_mouse			mouse;
	int						*graphic_errorlevel;
	int	(*FUNCTION_KEY_DOWN)(unsigned int, void *);
	void					*FUNCTION_KEY_DOWN_ARG;
	int	(*FUNCTION_KEY_UP)(unsigned int, void *);
	void					*FUNCTION_KEY_UP_ARG;
	int	(*FUNCTION_CLOSE)(void *);
	void					*FUNCTION_CLOSE_ARG;
	int	(*FUNCTION_LOOP)(void *);
	void					*FUNCTION_LOOP_ARG;
	int	(*FUNCTION_RESIZE)(void *);
	void					*FUNCTION_RESIZE_ARG;
	int	(*FUNCTION_MOUSE)(unsigned int, unsigned int, unsigned char, void *);
	void					*FUNCTION_MOUSE_ARG;
	unsigned int			FPS_START_TIME;
	unsigned int			fps;
	char					window_resizing;
	struct s_window			window;
#	ifdef __APPLE__
	id						WINDOW_MODULE;
	id						EVENT;
	void					*TIMER_ID;
	void					*OBSERVER_ID;
	CGRect					CANVAS_INFO;
#		ifdef __APPLE_OPENGL__
	GLuint					PROGRAM;
	GLuint					VERTEX_BUFFER_OBJECT;
	GLuint					TEXTURE;
	CGLContextObj			CONTEXT;
#		else /* CORE GRAPHICS */
	// NOTE: IT'S SLOW! EVEN WITH FUCKING THREADS!!!! FUCK YOU MACOS!!!!
	pthread_mutex_t			CLOSE_THREAD_MUTEX;
	pthread_t				THREAD_UPDATE_WINDOW;
	CGColorSpaceRef			COLOR_SPACE;
	CGDataProviderRef		IMAGE_PROVIDER;
	int						CLOSE_THREAD; // BOOL
#		endif /* __APPLE_OPENGL__ */
#	else
#		ifdef _WIN32
	HWND					WINDOW_HANDLE;
	void	(*REFRESH_SCREEN)(const struct S_APP *const);
#		else /* UNIX */
	Display					*DISPLAY;
	Window					XWINDOW;
	GC						GRAPHICS_CONTEXT;
	XImage					*IMAGE;
#		endif /* WINDOWS */
#	endif /* APPLE */
}	t_app;
/* ************************** [^] struct s_app [^] ************************** */
#endif /* LIBCGFX_STRUCTURES_H */
