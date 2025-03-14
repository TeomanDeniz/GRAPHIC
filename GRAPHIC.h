/******************************************************************************\
# H - GRAPHIC                                    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
# ---------------------------------------------- #  :!:    : :: : :  :  ::::!: #
# Serge Zaitsev (Aka: zserge)                    #   :!:: :!:!1:!:!::1:::!!!:  #
# Dimitri Sokolyuk (Aka: dim13)                  #   ::!::!!1001010!:!11!!::   #
# Ian Bryant (Aka: recidivism5)                  #   :!1!!11000000000011!!:    #
# Kirill (Aka: dartvader316)                     #    ::::!!!1!!1!!!1!!!::     #
# Grauho (Aka: grauho)                           #       ::::!::!:::!::::      #
#                                                #                             #
# +.....................++.....................+ #                             #
# : C - Maximum Tension :: Create - 2023/05/25 : #                             #
# :---------------------::---------------------: #                             #
# : License - APACHE 2  :: Update - 2025/03/13 : #                             #
# +.....................++.....................+ #                             #
\******************************************************************************/

/*
WINDOWS: -lwinmm -lgdi32 -mwindows
*/

/*
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

int
	main(void)
{
	unsigned int	BUFFER[SCREEN_WIDTH * SCREEN_HEIGHT];

	struct GRAPHIC GRAPHIC = {
		.TITLE = "TEST TITLE",
		.WIDTH = SCREEN_WIDTH,
		.HEIGHT = SCREEN_HEIGHT,
		.BUFFER = BUFFER,
	};

	WINDOW_OPEN(&GRAPHIC);  // OPEN WINDOW

		PUT_PIXEL(&GRAPHIC, 200, 200, 0XFFFFFF); // PUT A WHITE PIXEL

		WINDOW_TITLE(&GRAPHIC, "ANOTHER TEST TITLE"); // EDIT WINDOW TITLE

	WINDOW_CLOSE(&GRAPHIC); // CLOSE WINDOW
	return (0);
}
*/

#ifndef GRAPHIC_H

/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		error "TI COMPILER DOES NOT SUPPORT GRAPHIC LIBRARY!!!"
#	endif /* __TI_COMPILER_VERSION__ */
/* *************************** [^] TI CGT CCS [^] *************************** */

#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */
#	define GRAPHIC_H 202503 /* VERSION */

/* ************* [v] CHECK IF LIBRARY SUPPORTS THIS DEVICE [v] ************** */
#	if !(defined(__APPLE__) || defined(__DJGPP__) || defined(_WIN32) || \
		defined(__linux__) || defined(__gnu_linux__) || \
		defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || \
		defined(__DragonFly__) || defined(__sun))
#		error "THIS OS OR DEVICE DOES NOT SUPPORT ANY GRAPHICS"
#	endif
/* ************* [^] CHECK IF LIBRARY SUPPORTS THIS DEVICE [^] ************** */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "GRAPHIC/#STRUCT.h" /*
#	 struct graphic;
#	 struct GRAPHIC;
#	        */
#	ifdef __DJGPP__
#		include <go32.h> /*
#		 define _dos_ds;
#		        */
#		include <sys/farptr.h> /*
#		   void _farpokeb(short, long, char);
#		        */
#	endif /* __DJGPP__ */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PUT_PIXEL [v] **************************** */
#	ifdef __DJGPP__
#		define PUT_PIXEL(\
			__PUT_PIXEL_GRAPHIC__, \
			__PUT_PIXEL_X__, \
			__PUT_PIXEL_Y__, \
			__PUT_PIXEL_COLOR__\
		) (\
			_farpokeb(\
				_dos_ds, \
				0XA0000 + (__PUT_PIXEL_Y__ * 320) + __PUT_PIXEL_X__, \
				__PUT_PIXEL_COLOR__\
			);\
		)
#		define put_pixel(\
			__put_pixel_graphic__, \
			__put_pixel_x__, \
			__put_pixel_y__, \
			__put_pixel_color__\
		) (\
			_farpokeb(\
				_dos_ds, \
				0XA0000 + (__put_pixel_y__ * 320) + __put_pixel_x__, \
				__put_pixel_color__\
			);\
		)
#	else /* !__DJGPP__ */
#		define PUT_PIXEL(\
			__PUT_PIXEL_GRAPHIC__, \
			__PUT_PIXEL_X__, \
			__PUT_PIXEL_Y__, \
			__PUT_PIXEL_COLOR__\
		) (\
			(\
				(__PUT_PIXEL_GRAPHIC__)->BUFFER[\
					(\
						(__PUT_PIXEL_Y__) * (__PUT_PIXEL_GRAPHIC__)->WIDTH\
					) + (__PUT_PIXEL_X__)\
				]\
			) = __PUT_PIXEL_COLOR__\
		)
#		define put_pixel(\
			__put_pixel_graphic__, \
			__put_pixel_x__, \
			__PUT_PIXEL_Y__, \
			__put_pixel_color__\
		) (\
			(\
				(__put_pixel_graphic__)->buffer[\
					(\
						(__PUT_PIXEL_Y__) * (__put_pixel_graphic__)->width\
					) + (__put_pixel_x__)\
				]\
			) = __put_pixel_color__\
		)
#	endif /* __DJGPP__ */
/* *************************** [^] PUT_PIXEL [^] **************************** */

#	ifdef __STDC__
/* *************************** [v] FUNCTIONS [v] **************************** */
extern int	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC);
extern int	graphic_loop(struct graphic *graphic);

extern void	GRAPHIC_SLEEP(register long MILLISECONDS);
extern void	graphic_sleep(register long milliseconds);

extern long	GRAPHIC_TIME(void);
extern long	graphic_time(void);

extern void	WINDOW_CLOSE(struct GRAPHIC *const GRAPHIC);
extern void	window_close(struct graphic *const graphic);

extern int	WINDOW_OPEN(
	struct GRAPHIC *const GRAPHIC,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
);
extern int	window_open(
	struct graphic *const graphic,
	register unsigned int width,
	register unsigned int height
);

extern int	WINDOW_TITLE(
	struct GRAPHIC *const GRAPHIC,
	char *const TITLE
);
extern int	window_title(
	struct graphic *const graphic,
	char *const title
);

extern void	*GRAPHIC_INIT(void);

extern void	*graphic_init(void);

extern void	GRAPHIC_SETUP(struct GRAPHIC *const GRAPHIC);

extern void	graphic_setup(struct graphic *const graphic);
/* *************************** [^] FUNCTIONS [^] **************************** */

/* ************************** [v] EVENT HOOKS [v] *************************** */
extern void	EVENT_HOOK_CLOSE(
	const struct GRAPHIC *const GRAPHIC,
	int (*F)(void *),
	void *ARG
);
extern void	event_hook_close(
	const struct graphic *const graphic,
	int (*f)(void *),
	void *arg
);

extern void	EVENT_HOOK_KEY_DOWN(
	const struct GRAPHIC *const GRAPHIC,
	int (*F)(unsigned int, void *),
	void *ARG
);
extern void	event_hook_key_down(
	struct graphic *const graphic,
	int (*f)(unsigned int, void *),
	void *arg
);

extern void	EVENT_HOOK_KEY_UP(
	struct GRAPHIC *const GRAPHIC,
	int (*F)(unsigned int, void *),
	void *ARG
);
extern void	event_hook_key_up(
	struct graphic *const graphic,
	int (*f)(unsigned int, void *),
	void *arg
);

extern void	EVENT_HOOK_LOOP(
	struct GRAPHIC *const GRAPHIC,
	int (*F)(void *),
	void *ARG
);
extern void	event_hook_loop(
	struct graphic *const graphic,
	int (*f)(void *),
	void *arg
);

extern void	EVENT_HOOK_MOUSE(
	struct GRAPHIC *const GRAPHIC,
	int (*F)(unsigned int, unsigned int, unsigned char, void *),
	void *ARG
);
extern void	event_hook_mouse(
	struct graphic *const graphic,
	int (*f)(unsigned int, unsigned int, unsigned char, void *),
	void *arg
);
/* ************************** [^] EVENT HOOKS [^] *************************** */

#	else /* !__STDC__ */

/* *************************** [v] FUNCTIONS [v] **************************** */
extern int	GRAPHIC_LOOP();
extern int	graphic_loop();
extern void	GRAPHIC_SLEEP()
extern void	graphic_sleep();
extern long	GRAPHIC_TIME();
extern long	graphic_time();
extern void	WINDOW_CLOSE();
extern void	window_close();
extern int	WINDOW_OPEN();
extern int	window_open();
extern int	WINDOW_TITLE();
extern int	window_title();
extern void	*GRAPHIC_INIT();
extern void	*graphic_init();
extern void	GRAPHIC_SETUP();
extern void	graphic_setup();
/* *************************** [^] FUNCTIONS [^] **************************** */

/* ************************** [v] EVENT HOOKS [v] *************************** */
extern void	EVENT_HOOK_CLOSE();
extern void	event_hook_close();
extern void	EVENT_HOOK_KEY_DOWN();
extern void	event_hook_key_down();
extern void	EVENT_HOOK_KEY_UP();
extern void	event_hook_key_up();
extern void	EVENT_HOOK_LOOP();
extern void	event_hook_loop();
extern void	EVENT_HOOK_MOUSE();
extern void	event_hook_mouse();
/* ************************** [^] EVENT HOOKS [^] *************************** */

#	endif /* __STDC__ */

/* *************************** [V] C++ CLASS [V] **************************** */
#	ifdef __cplusplus /* C++ */
		} /* C++ */
/* TODO:

#	include "GRAPHIC.hpp"

class GRAPHIC
{
	struct GRAPHIC (GRAPHIC);
	long               (NOW);

public: * ************************* [v] PUBLIC [v] ************************* *
* ************************** [v] CONSTRUCTOR [v] *************************** *
	GRAPHIC(const unsigned int WIDTH, const unsigned int HEIGHT, char *TITLE)
		: GRAPHIC {.WIDTH = WIDTH, .HEIGHT = HEIGHT, .TITLE = TITLE}
	{
		this->GRAPHIC.BUFFER = new unsigned int [WIDTH * HEIGHT];
		this->NOW = GRAPHIC_TIME();
		WINDOW_OPEN(&this->GRAPHIC);
	}
* ************************** [^] CONSTRUCTOR [^] *************************** *
* *************************** [v] DESTRUCTOR [v] *************************** *
	~GRAPHIC(void)
	{
		WINDOW_CLOSE(&this->GRAPHIC);
		delete [] this->GRAPHIC.BUFFER;
	}
* *************************** [^] DESTRUCTOR [^] *************************** *
	REGPARM(1) bool
		LOOP(const int FPS)
	{
		register long (TIME);

		TIME = GRAPHIC_TIME();

		if (TIME - this->NOW < 1000 / FPS)
			GRAPHIC_SLEEP(TIME - NOW);

		this->NOW = TIME;
		return (GRAPHIC_LOOP(&this->GRAPHIC) == 0);
	}

	REGPARM(3) void
		PIXEL(const unsigned int X, const unsigned int Y, \
			const unsigned long COLOR)
	{
		GRAPHIC_PIXEL(this->GRAPHIC, X, Y, COLOR);
	}

	REGPARM(1) bool
		KEY(int CHARACTER)
	{
		if (CHARACTER >= 0 && CHARACTER < 128)
			return (this->GRAPHIC.KEYS[CHARACTER])

		return (false);
	}

	int
		X(void)
	{
		return (this->GRAPHIC.X);
	}

	int
		Y(void)
	{
		return (this->GRAPHIC.Y);
	}

	int
		MOUSE(void)
	{
		return (this->GRAPHIC.MOUSE);
	}

	int
		KEY_MODE(void)
	{
		return (this->GRAPHIC.KEY_MODE);
	}
*/
/* ***************************** [^] PUBLIC [^] ***************************** */
};

#	endif /* C++ */
/* **************************** [^] C++ CLASS [^] *************************** */
#endif /* GRAPHIC_H */
