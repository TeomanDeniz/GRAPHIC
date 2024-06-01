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
# : License - APACHE 2  :: Update - 2024/05/25 : #                             #
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

		GRAPHIC_PIXEL(&GRAPHIC, 200, 200, 0XFFFFFF); // PUT A WHITE PIXEL

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
#	define GRAPHIC_H 202405 /* VERSION */
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
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] FUNCTIONS [v] **************************** */
#	include "GRAPHIC/#FUNCTIONS/#WINDOW_CLOSE/#WINDOW_CLOSE.h" /*
#	 define window_close(struct graphic *)
#	   void WINDOW_CLOSE(struct GRAPHIC *);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#GRAPHIC_TIME/#GRAPHIC_TIME.h" /*
#	 define graphic_time
#	   long GRAPHIC_TIME(void);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#GRAPHIC_SLEEP/#GRAPHIC_SLEEP.h" /*
#	 define graphic_sleep(long)
#	   void GRAPHIC_SLEEP(long);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#WINDOW_TITLE/#WINDOW_TITLE.h" /*
#	 define window_title(struct graphic *, char *)
#	    int WINDOW_TITLE(struct GRAPHIC *, char *);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#GRAPHIC_LOOP/#GRAPHIC_LOOP.h" /*
#	 define graphic_loop(struct graphic *)
#	    int GRAPHIC_LOOP(struct GRAPHIC *);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#GRAPHIC_SETUP.h" /*
#	 define graphic_setup(struct graphic *)
#	   void GRAPHIC_SETUP(struct GRAPHIC *);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#GRAPHIC_INIT.h" /*
v	>>>>>>> (struct GRAPHIC)
#	^^^^^^^ *GRAPHIC_INIT(void);
v	>>>>>>> (struct graphic)
#	^^^^^^^ *graphic_init(void);
#	        */
#	include "GRAPHIC/#FUNCTIONS/#PUT_PIXEL.h" /*
#	 define PUT_PIXEL(struct GRAPHIC *, int, int, uint)
#	 define put_pixel(struct graphic *, int, int, uint)
#	        */
#	include "GRAPHIC/#FUNCTIONS/#WINDOW_OPEN/#WINDOW_OPEN.h" /*
#	 define window_open(struct graphic *, uint, uint)
#	    int WINDOW_OPEN(struct GRAPHIC *, uint, uint);
#	        */
/* *************************** [^] FUNCTIONS [^] **************************** */
/* ************************** [v] EVENT HOOKS [v] *************************** */
#	include "GRAPHIC/#EVENT_HOOKS/#EVENT_HOOK_KEY_DOWN.h" /*
#	   void EVENT_HOOK_KEY_DOWN(struct GRAPHIC *, int (*f)(int, void *),
>	        void *);
#	   void event_hook_key_down(struct graphic *, int (*f)(int, void *),
>	        void *);
#	        */
#	include "GRAPHIC/#EVENT_HOOKS/#EVENT_HOOK_KEY_UP.h" /*
#	   void EVENT_HOOK_KEY_UP(struct GRAPHIC *, int (*f)(int, void *), void *);
#	   void event_hook_key_up(struct graphic *, int (*f)(int, void *), void *);
#	        */
#	include "GRAPHIC/#EVENT_HOOKS/#EVENT_HOOK_CLOSE.h" /*
#	   void EVENT_HOOK_CLOSE(struct GRAPHIC *, int (*f)(void *), void *);
#	   void event_hook_close(struct graphic *, int (*f)(void *), void *);
#	        */
#	include "GRAPHIC/#EVENT_HOOKS/#EVENT_HOOK_LOOP.h" /*
#	   void EVENT_HOOK_LOOP(struct GRAPHIC *, int (*f)(void *), void *);
#	   void event_hook_loop(struct graphic *, int (*f)(void *), void *);
#	        */
#	include "GRAPHIC/#EVENT_HOOKS/#EVENT_HOOK_MOUSE.h" /*
#	   void EVENT_HOOK_MOUSE(struct GRAPHIC *, \
>	        int (*F)(uint, uint, uchar, void *), void *);
#	   void event_hook_mouse(struct graphic *, \
>	        int (*F)(uint, uint, uchar, void *), void *);
#	        */
/* ************************** [^] EVENT HOOKS [^] *************************** */
/* *************************** [V] C++ CLASS [V] **************************** */
#	ifdef __cplusplus /* C++ */
		} /* C++ */
/* TODO:
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
