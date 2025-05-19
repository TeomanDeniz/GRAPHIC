/******************************************************************************\
# H - PUT_PIXEL__BITMAP                          #       Maximum Tension       #
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

#	define PUT_PIXEL(\
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

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_PUT_PIXEL_H */
