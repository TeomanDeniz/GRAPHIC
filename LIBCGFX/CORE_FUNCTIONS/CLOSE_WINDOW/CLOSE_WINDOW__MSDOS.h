/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/CLOSE_WINDOW__MSDOS #       Maximum Tension       #
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

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C

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
void
	CLOSE_WINDOW(struct S_APP *const APP)
#	else /* STANDARD C */
void
	CLOSE_WINDOW(APP)

	struct S_APP	*APP;
#	endif /* !KNR_STYLE */
{
	IGNORE_VAR	APP; // TODO: DON'T IGNORE AND USE IT ON... SOMETHING. IDK

	__dpmi_regs	__REGISTER__;

	__REGISTER__.x.ax = 0X03;
	__dpmi_int(0X10, &__REGISTER__);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C */
