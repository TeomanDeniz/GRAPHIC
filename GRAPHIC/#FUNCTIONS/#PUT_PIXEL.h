/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#PUT_PIXEL               #       Maximum Tension       #
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

#ifndef GRAPHIC_FUNCTIONS__PUT_PIXEL_H
#	define GRAPHIC_FUNCTIONS__PUT_PIXEL_H 202405
/* **************************** [v] INCLUDES [v] **************************** */
#	ifdef __DJGPP__
#		include <go32.h> /*
#		 define _dos_ds;
#		        */
#		include <sys/farptr.h> /*
#		   void _farpokeb(short, long, char);
#		        */
#	endif /* __DJGPP__ */
/* **************************** [^] INCLUDES [^] **************************** */
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
#endif /* GRAPHIC_FUNCTIONS__PUT_PIXEL_H */
