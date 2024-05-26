/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_CLOSE_MSDOS      #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__WINDOW_CLOSE_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <dpmi.h> /*
#	 struct __dpmi_regs;
#	    int __dpmi_int(int, __dpmi_regs *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	ifdef __STDC__ /* STANDARD C */
void
	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC)
#	else /* K&R */
void
	WINDOW_CLOSE(GRAPHIC)

	struct GRAPHIC *(GRAPHIC);
#	endif /* __STDC__ */
{
	(void)GRAPHIC; // TODO

	__dpmi_regs (__REGISTER__);

	__REGISTER__.x.ax = 0X03;
	__dpmi_int(0X10, &__REGISTER__);
	GRAPHIC->WINDOW_EXIST = 0;
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_CLOSE_H */
