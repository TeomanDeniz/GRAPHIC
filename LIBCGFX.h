/******************************************************************************\
# H - LIBCGFX                                    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/05/25 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/05/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifndef LIBCGFX_H
#	define LIBCGFX_H 202505 /* VERSION */

/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		error "TI COMPILER DOES NOT SUPPORT GRAPHIC LIBRARY!!!"
#	endif /* __TI_COMPILER_VERSION__ */
/* *************************** [^] TI CGT CCS [^] *************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
#		define register /* IGNORE REGISTER KEYWORD */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ************* [v] CHECK IF LIBRARY SUPPORTS THIS DEVICE [v] ************** */
#	if !(defined(__APPLE__) || defined(__DJGPP__) || defined(_WIN32) || \
		defined(__linux__) || defined(__gnu_linux__) || \
		defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || \
		defined(__DragonFly__) || defined(__sun))
#		error "THIS OS OR DEVICE DOES NOT SUPPORT ANY GRAPHICS"
#	endif
/* ************* [^] CHECK IF LIBRARY SUPPORTS THIS DEVICE [^] ************** */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include "LIBCGFX/STRUCTURES.h" /*
#	 struct S_APP;
#	 struct s_app;
#	        */
#	include "LIBCGFX/CORE_FUNCTIONS/PUT_PIXEL/PUT_PIXEL.h" /*
#	 define PUT_PIXEL(
>	        	__PUT_PIXEL_GRAPHIC__,
>	        	__PUT_PIXEL_X__,
>	        	__PUT_PIXEL_Y__,
>	        	__PUT_PIXEL_COLOR__
>	        )
#	 define put_pixel(
>	        	__put_pixel_graphic__,
>	        	__put_pixel_x__,
>	        	__put_pixel_y__,
>	        	__put_pixel_color__
>	        )
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifndef KNR_STYLE /* STANDARD C */
/* ************************* [v] CORE_FUNCTIONS [v] ************************* */
extern int	APP_LOOP(struct S_APP *APP);
extern int	app_loop(struct s_app *app);
extern void	APP_SLEEP(register long MILLISECONDS);
extern void	app_sleep(register long milliseconds);
extern long	APP_TIME(void);
extern long	app_time(void);
extern void	CLOSE_WINDOW(struct S_APP *const APP);
extern void	close_window(struct s_app *const app);
extern int	CREATE_WINDOW(
	struct S_APP *const APP,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
);
extern int	create_window(
	struct s_app *const app,
	register unsigned int width,
	register unsigned int height
);
extern int	SET_TITLE(struct S_APP *const APP, char *const TITLE);
extern int	set_title(struct s_app *const app, char *const title);
extern void	*APP_INIT(void);
extern void	*app_init(void);
extern void	APP_SETUP(struct S_APP *const APP);
extern void	app_setup(struct s_app *const app);
extern void	SET_CURSOR(
	struct S_APP *const APP,
	const unsigned char CURSOR_TYPE
);
extern void	set_cursor(
	struct s_app *const app,
	const unsigned char cursor_type
);
extern void	set_cursor_position(
	struct s_app *const app,
	const int x,
	const int y
);
extern void	SET_CURSOR_POSITION(
	struct S_APP *const APP,
	const int X,
	const int Y
);
/* ************************* [^] CORE_FUNCTIONS [^] ************************* */

/* ************************** [v] EVENT_HOOKS [v] *************************** */
extern void	EVENT_HOOK_CLOSE(
	const struct S_APP *const APP,
	int (*F)(void *),
	void *ARG
);
extern void	event_hook_close(
	const struct s_app *const app,
	int (*f)(void *),
	void *arg
);
extern void	EVENT_HOOK_KEY_DOWN(
	const struct S_APP *const APP,
	int (*F)(unsigned int, void *),
	void *ARG
);
extern void	event_hook_key_down(
	struct s_app *const app,
	int (*f)(unsigned int, void *),
	void *arg
);
extern void	EVENT_HOOK_KEY_UP(
	struct S_APP *const APP,
	int (*F)(unsigned int, void *),
	void *ARG
);
extern void	event_hook_key_up(
	struct s_app *const app,
	int (*f)(unsigned int, void *),
	void *arg
);
extern void	EVENT_HOOK_LOOP(
	struct S_APP *const APP,
	int (*F)(void *),
	void *ARG
);
extern void	event_hook_loop(
	struct s_app *const app,
	int (*f)(void *),
	void *arg
);
extern void	EVENT_HOOK_MOUSE(
	struct S_APP *const APP,
	int (*F)(unsigned int, unsigned int, unsigned char, void *),
	void *ARG
);
extern void	event_hook_mouse(
	struct s_app *const app,
	int (*f)(unsigned int, unsigned int, unsigned char, void *),
	void *arg
);
extern void	EVENT_HOOK_RESIZE(
	struct S_APP *const APP,
	int (*F)(void *),
	void *ARG
);
extern void	event_hook_resize(
	struct s_app *const app,
	int (*f)(void *),
	void *arg);
/* ************************** [^] EVENT_HOOKS [^] *************************** */
#	else /* K&R */
/* ************************* [v] CORE_FUNCTIONS [v] ************************* */
extern int	APP_LOOP();
extern int	app_loop();
extern void	APP_SLEEP()
extern void	app_sleep();
extern long	APP_TIME();
extern long	app_time();
extern void	CLOSE_WINDOW();
extern void	close_window();
extern int	CREATE_WINDOW();
extern int	create_window();
extern int	SET_TITLE();
extern int	set_title();
extern void	*APP_INIT();
extern void	*app_init();
extern void	APP_SETUP();
extern void	app_setup();
extern void	SET_CURSOR();
extern void	set_cursor();
extern void	set_cursor_position();
extern void	SET_CURSOR_POSITION();
/* ************************* [^] CORE_FUNCTIONS [^] ************************* */

/* ************************** [v] EVENT_HOOKS [v] *************************** */
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
/* ************************** [^] EVENT_HOOKS [^] *************************** */
#	endif /* !KNR_STYLE */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

#endif /* LIBCGFX_H */
