/******************************************************************************\
# H - PUT_PIXEL__MSDOS                           #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/05/19 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/05/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_PUT_PIXEL_H

/* **************************** [v] INCLUDES [v] **************************** */
#	include <go32.h> /*
#	 define _dos_ds;
#	        */
#	include <sys/farptr.h> /*
#	   void _farpokeb(short, long, char);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	define PUT_PIXEL(\
		__PUT_PIXEL_GRAPHIC__, \
		__PUT_PIXEL_X__, \
		__PUT_PIXEL_Y__, \
		__PUT_PIXEL_COLOR__\
	) (\
		_farpokeb(\
			_dos_ds, \
			(0XA0000 + ((__PUT_PIXEL_Y__) * 320) + (__PUT_PIXEL_X__)), \
			(__PUT_PIXEL_COLOR__)\
		)\
	)

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_PUT_PIXEL_H */
