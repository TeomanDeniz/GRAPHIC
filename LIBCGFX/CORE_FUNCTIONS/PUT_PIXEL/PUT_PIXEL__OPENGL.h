/******************************************************************************\
# H - PUT_PIXEL__OPENGL                          #       Maximum Tension       #
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
#	include <gl/GL.h> /*
#	 define GL_SCISSOR_TEST
#	 define GL_COLOR_BUFFER_BIT
#	typedef GLfloat;
#	   void glEnable(GLenum);
#	   void glClearColor(GLfloat, GLfloat, GLfloat, GLfloat);
#	   void glClear(GLbitfield);
#	   void glScissor(GLint, GLint, GLsizei, GLsizei);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	define PUT_PIXEL(\
		__PUT_PIXEL_GRAPHIC__, \
		__PUT_PIXEL_X__, \
		__PUT_PIXEL_Y__, \
		__PUT_PIXEL_COLOR__\
	) {\
		const GLfloat	OPENGL_PUT_PIXEL__RED = \
			(((__PUT_PIXEL_COLOR__) >> 16) & 0XFF) / 255.0F;\
		const GLfloat	OPENGL_PUT_PIXEL__GREEN = \
			(((__PUT_PIXEL_COLOR__) >> 8)  & 0XFF) / 255.0F;\
		const GLfloat	OPENGL_PUT_PIXEL__BLUE = \
			(((__PUT_PIXEL_COLOR__) >> 0)  & 0XFF) / 255.0F;\
		const GLfloat	OPENGL_PUT_PIXEL__ALPHA = \
			(((__PUT_PIXEL_COLOR__) >> 24) & 0XFF) / 255.0F;\
		\
		glEnable(GL_SCISSOR_TEST);\
		glScissor((__PUT_PIXEL_X__), (__PUT_PIXEL_Y__), 1, 1);\
		glClearColor(\
			OPENGL_PUT_PIXEL__RED, \
			OPENGL_PUT_PIXEL__GREEN, \
			OPENGL_PUT_PIXEL__BLUE, \
			OPENGL_PUT_PIXEL__ALPHA\
		);\
		glClear(GL_COLOR_BUFFER_BIT);\
		glDisable(GL_SCISSOR_TEST);\
	}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_PUT_PIXEL_H */
