/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/                    #       Maximum Tension       #
# CREATE_WINDOW__MSDOS                           #                             #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/05/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include "../../../LIBCMT/ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include <dpmi.h> /*
#	typedef __dpmi_regs;
#	    int __dpmi_int(int, __dpmi_regs *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifndef KNR_STYLE /* K&R */
int
	CREATE_WINDOW(
	struct S_APP *APP,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
#	else /* STANDARD C */
void
	CREATE_WINDOW(APP, WIDTH, HEIGHT)

	struct S_APP	*APP;
	register int	WIDTH;
	register int	HEIGHT;
#	endif /* !KNR_STYLE */
{
	IGNORE_VAR	WIDTH;
	IGNORE_VAR	HEIGHT;
	IGNORE_VAR	APP;

	__dpmi_regs	__REGISTER__;

	__REGISTER__.x.ax = 19; /* 0X13 | 13H */
	__dpmi_int(0X10, &__REGISTER__);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C */
