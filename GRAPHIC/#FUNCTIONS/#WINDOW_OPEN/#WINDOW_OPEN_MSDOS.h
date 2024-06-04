/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_OPEN_MSDOS       #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_OPEN_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include "../../CMT/KEYWORDS/IGNORE.h" /*
#	 define IGNORE
#	        */
#	include <dpmi.h> /*
#	typedef __dpmi_regs;
#	    int __dpmi_int(int, __dpmi_regs *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	ifdef __STDC__ /* STANDARD C */
int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC, register unsigned int WIDTH, \
register unsigned int HEIGHT)
#	else /* K&R */
void
	WINDOW_OPEN(GRAPHIC, WIDTH, HEIGHT)

	struct GRAPHIC *(GRAPHIC);
	register int      (WIDTH);
	register int     (HEIGHT);
#	endif /* __STDC__ */
{
	IGNORE WIDTH;
	IGNORE HEIGHT;

	__dpmi_regs (__REGISTER__);

	__REGISTER__.x.ax = 19; /* 0X13 | 13H */
	__dpmi_int(0X10, &__REGISTER__);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_C */
