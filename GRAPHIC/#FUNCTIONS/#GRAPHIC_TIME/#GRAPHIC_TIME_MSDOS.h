/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_TIME_MSDOS      #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_TIME_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include <dos.h> /*
#	 struct time;
#	   void gettime(struct time *);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
#	ifdef __STDC__ /* STANDARD C */
long
	GRAPHIC_TIME(void)
#	else /* K&R */
long
	GRAPHIC_TIME()
#	endif /* __STDC__ */
{
	struct time (TIME);
	long      (RESULT);

	gettime(&TIME);
	RESULT = (long)TIME.ti_hund;
	RESULT += (long)TIME.ti_sec * 100L;
	RESULT += (long)TIME.ti_min * 6000L;
	RESULT += (long)TIME.ti_hour * 360000L;
	return (RESULT);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_TIME_H */
