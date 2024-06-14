/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#WINDOW_OPEN_MACOS_OPENGL#       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/06/08 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/06/08 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef GRAPHIC_FUNCTIONS__WINDOW_OPEN_C
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../GRAPHIC.h" /*
#	 struct GRAPHIC;
#	   void WINDOW_CLOSE(struct GRAPHIC *);
#	        */
#	include "../../CMT/KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	   void free(void *);
#	        */
#	include "../../CMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	 define NO
#	 define YES
#	typedef BOOL;
#	typedef id;
#	typedef Class;
#	typedef NSInteger;
#	typedef NSUInteger;
#	        */
#	include <objc/objc-runtime.h> /*
#	typedef *SEL;
#	typedef *IMP;
#	    SEL sel_getUid(const char *);
#	  Class objc_getClass(const char *);
#	  Class objc_allocateClassPair(Class, char *, size_t);
#	   BOOL class_addMethod(Class, SEL, IMP, char *);
#	   void objc_registerClassPair(Class);
#	        */
#	include <CoreGraphics/CoreGraphics.h> /*
#	typedef CGRect;
#	 CGRect CGRectMake(float, float, float, float);
#	        */
#	include "../../CMT/KEYWORDS/IGNORE.h" /*
#	 define IGNORE
#	        */
#	include <OpenGL/gl3.h> /*
#	 define GL_NO_ERROR
#	 define GL_ARRAY_BUFFER
#	 define GL_STATIC_DRAW
#	 define GL_TEXTURE_2D
#	 define GL_RGBA
#	 define GL_UNSIGNED_BYTE
#	 define GL_TEXTURE_MIN_FILTER
#	 define GL_NEAREST
#	 define GL_TEXTURE_MAG_FILTER
#	typedef GLenum;
#	   void glDeleteProgram(GLuint);
#	 GLuint glCreateShader(GLenum);
#	   void glShaderSource(GLuint, GLsizei, GLchar **, GLint *);
#	   void glCompileShader(GLuint);
#	 GLuint glCreateProgram(void);
#	 GLenum glGetError(void);
#	   void glAttachShader(GLuint, GLuint);
#	   void glLinkProgram(GLuint);
#	   void glDeleteShader(GLuint);
#	   void glGenBuffers(GLsizei, GLuint *);
#	   void glBindBuffer(GLenum, GLuint);
#	   void glBufferData(GLenum, GLsizeiptr, GLvoid *, GLenum);
#	   void glGenTextures(GLsizei, GLuint *);
#	   void glBindTexture(GLenum, GLuint);
#	   void glTexImage2D(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum,
>	        GLenum, GLvoid *);
#	   void glTexParameteri(GLenum, GLenum, GLint);
#	   void glDeleteBuffers(GLsizei, GLuint *);
#	   void glDeleteTextures(GLsizei, GLuint *);
#	   void glFlush(void);
#	        */
#	include <OpenGL/OpenGL.h> /*
#	typedef CGLPixelFormatObj;
#	typedef GLint;
#	typedef CGLPixelFormatAttribute;
#	typedef GLuint;
v	>>>>>>> (CGLError)
#	^^^^^^^ CGLChoosePixelFormat(CGLPixelFormatAttribute *, CGLPixelFormatObj *,
>	        GLint *);
v	>>>>>>> (CGLError)
#	^^^^^^^ CGLCreateContext(CGLPixelFormatObj, CGLContextObj, CGLContextObj *);
v	>>>>>>> (CGLError)
#	^^^^^^^ CGLDestroyPixelFormat(CGLPixelFormatObj);
v	>>>>>>> (CGLError)
#	^^^^^^^ CGLSetCurrentContext(CGLContextObj);
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
extern id const NSApp;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */
/* ************************* [v] HELPER MACROS [v] ************************** */
#	ifndef MSG
#		define MSG(\
			__MSG_ROUGHNESS__, \
			__MSG_OPTION__, \
			__MSG_SIZE__\
		) (\
			(\
				__MSG_ROUGHNESS__(*)\
				(\
					id, \
					SEL\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG_OPTION__, \
			sel_getUid(__MSG_SIZE__)\
		)
#	endif /* MSG */
#	ifndef MSG1
#		define MSG1(\
			__MSG1_ROUGHNESS__, \
			__MSG1_OPTION__, \
			__MSG1_SIZE__, \
			__MSG1_A__, \
			__MSG1_a__\
		) (\
			(\
				__MSG1_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG1_A__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG1_OPTION__, \
			sel_getUid(__MSG1_SIZE__), \
			__MSG1_a__\
		)
#	endif /* MSG1 */
#	ifndef MSG4
#		define MSG4(\
			__MSG4_ROUGHNESS__, \
			__MSG4_OPTION__, \
			__MSG4_SIZE__, \
			__MSG4_A__, \
			__MSG4_a__, \
			__MSG4_B__, \
			__MSG4_b__, \
			__MSG4_C__, \
			__MSG4_c__, \
			__MSG4_D__, \
			__MSG4_d__\
		) (\
			(\
				__MSG4_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG4_A__, \
					__MSG4_B__, \
					__MSG4_C__, \
					__MSG4_D__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG4_OPTION__, \
			sel_getUid(__MSG4_SIZE__), \
			__MSG4_a__, \
			__MSG4_b__, \
			__MSG4_c__, \
			__MSG4_d__\
		)
#	endif /* MSG4 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* REFRESH_SCREEN */
#	define VERTEX_SHADER_SOURCE \
		"#version 110 \n"\
		"attribute vec2 position;\n"\
		"varying vec2 texcoord;\n"\
		"void main()\n"\
		"{\n"\
		"    gl_Position = vec4(position, 0.0, 1.0);\n"\
		"    texcoord = vec2(position[0] + 1.0, 1.0 - position[1]) / 2.0;\n"\
		"}\n"
#	define FRAGMENT_SHADER_SOURCE \
		"#version 110 \n"\
		"uniform sampler2D texture;\n"\
		"varying vec2 texcoord;\n"\
		"void main()\n"\
		"{\n"\
		"    gl_FragColor = texture2D(texture, texcoord);\n"\
		"}\n"
#	define VERTEX_BUFFER (float [16]){\
		/* Position    Texcoords */ \
		-1.0F,  1.0F,  0.0F, 1.0F, \
		-1.0F, -1.0F,  0.0F, 0.0F, \
		 1.0F, -1.0F,  1.0F, 0.0F, \
		 1.0F,  1.0F,  1.0F, 1.0F}
/* ************************* [^] HELPER MACROS [^] ************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern INLINE BOOL	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, \
const id WINDOW);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC, register unsigned int WIDTH, \
register unsigned int HEIGHT)
{
	Class                         (VOYAGER);
	id                              (TITLE);
	CGLPixelFormatObj        (PIXEL_FORMAT);
	GLint                          (NUMBER);
	CGLPixelFormatAttribute (GL_ATTRIBUTES)[4];
	register GLuint       (FRAGMENT_SHADER);
	register GLuint         (VERTEX_SHADER);

	IGNORE NUMBER;

	GL_ATTRIBUTES[0] = (CGLPixelFormatAttribute)kCGLPFAAllRenderers;
	GL_ATTRIBUTES[1] = (CGLPixelFormatAttribute)kCGLPFAOpenGLProfile;
	GL_ATTRIBUTES[2] = (CGLPixelFormatAttribute)kCGLOGLPVersion_GL3_Core;
	GL_ATTRIBUTES[3] = (CGLPixelFormatAttribute)0;

	if (CGLChoosePixelFormat(GL_ATTRIBUTES, &PIXEL_FORMAT, &NUMBER))
		return (-1);

	if (CGLCreateContext(PIXEL_FORMAT, ((void *)0), &GRAPHIC->CONTEXT))
	{
		CGLDestroyPixelFormat(PIXEL_FORMAT);
		return (-1);
	}

	VERTEX_SHADER = glCreateShader(GL_VERTEX_SHADER);
	CGLDestroyPixelFormat(PIXEL_FORMAT);
	glShaderSource(VERTEX_SHADER, 1, \
		(const GLchar *const *)&VERTEX_SHADER_SOURCE, ((GLint *)0));
	glCompileShader(VERTEX_SHADER);
	FRAGMENT_SHADER = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FRAGMENT_SHADER, 1, \
		(const GLchar *const *)&FRAGMENT_SHADER_SOURCE, ((GLint *)0));
	glCompileShader(FRAGMENT_SHADER);
	CGLSetCurrentContext(GRAPHIC->CONTEXT);
	GRAPHIC->PROGRAM = glCreateProgram();

	if (!GRAPHIC->PROGRAM)
	{
		GLenum (GL_ERROR);

		GL_ERROR = glGetError();
		glDeleteShader(VERTEX_SHADER);
		glDeleteShader(FRAGMENT_SHADER);

		if (GL_ERROR != GL_NO_ERROR)
			return (GL_ERROR);
		else
			return (-1);
	}

	glAttachShader(GRAPHIC->PROGRAM, VERTEX_SHADER);
	glAttachShader(GRAPHIC->PROGRAM, FRAGMENT_SHADER);
	glLinkProgram(GRAPHIC->PROGRAM);
	glDeleteShader(VERTEX_SHADER);
	glDeleteShader(FRAGMENT_SHADER);
	glGenBuffers(1, &GRAPHIC->VERTEX_BUFFER_OBJECT);

	if (GRAPHIC->VERTEX_BUFFER_OBJECT == 0)
	{
		glDeleteProgram(GRAPHIC->PROGRAM);
		return (-1);
	}

	glBindBuffer(GL_ARRAY_BUFFER, GRAPHIC->VERTEX_BUFFER_OBJECT);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VERTEX_BUFFER), VERTEX_BUFFER, \
		GL_STATIC_DRAW);
	glGenTextures(1, &GRAPHIC->TEXTURE);

	if (GRAPHIC->TEXTURE == 0)
	{
		glDeleteBuffers(1, &GRAPHIC->VERTEX_BUFFER_OBJECT);
		GRAPHIC->VERTEX_BUFFER_OBJECT = 0;
		glDeleteProgram(GRAPHIC->PROGRAM);
		return (-1);
	}

	glBindTexture(GL_TEXTURE_2D, GRAPHIC->TEXTURE);
	glTexImage2D(\
		GL_TEXTURE_2D, \
		0, \
		GL_RGBA, \
		GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, \
		0, \
		GL_RGBA, \
		GL_UNSIGNED_BYTE, \
		((void *)0)\
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	GRAPHIC->BUFFER = (unsigned int *)malloc(\
		sizeof(unsigned int) * ((WIDTH * HEIGHT) + 1));

	if (!GRAPHIC->BUFFER)
	{
		glDeleteTextures(1, &GRAPHIC->TEXTURE);
		GRAPHIC->TEXTURE = 0;
		glDeleteBuffers(1, &GRAPHIC->VERTEX_BUFFER_OBJECT);
		GRAPHIC->VERTEX_BUFFER_OBJECT = 0;
		glDeleteProgram(GRAPHIC->PROGRAM);
		return (-1);
	}

	PREFETCH_RANGE(GRAPHIC->BUFFER, WIDTH * HEIGHT);
	GRAPHIC->WIDTH = WIDTH;
	GRAPHIC->HEIGHT = HEIGHT;
	MSG(id, REFRESH_SCREEN("NSApplication"), "sharedApplication");
	MSG1(void, NSApp, "setActivationPolicy:", NSInteger, 0);
	GRAPHIC->WINDOW_MODULE = MSG4(\
		id, \
		MSG(\
			id, \
			REFRESH_SCREEN("NSWindow"), \
			"alloc"\
		), \
		"initWithContentRect:styleMask:backing:defer:", \
		CGRect, \
		CGRectMake(\
			0, \
			0, \
			GRAPHIC->WIDTH, \
			GRAPHIC->HEIGHT\
		), \
		NSUInteger, \
		3, \
		NSUInteger, \
		2, \
		BOOL, \
		NO\
	);

	if (!GRAPHIC->WINDOW_MODULE)
	{
		glDeleteTextures(1, &GRAPHIC->TEXTURE);
		GRAPHIC->TEXTURE = 0;
		glDeleteBuffers(1, &GRAPHIC->VERTEX_BUFFER_OBJECT);
		GRAPHIC->VERTEX_BUFFER_OBJECT = 0;
		glDeleteProgram(GRAPHIC->PROGRAM);
		free(GRAPHIC->BUFFER);
		GRAPHIC->BUFFER = ((void *)0);
		return (-1);
	}

	VOYAGER = objc_allocateClassPair(\
		(Class)REFRESH_SCREEN("NSObject"), \
		"WindowDelegate", \
		0\
	);

	if (!VOYAGER)
	{
		WINDOW_CLOSE(GRAPHIC);
		return (-1);
	}

	class_addMethod(\
		VOYAGER, \
		sel_getUid("windowShouldClose:"), \
		(IMP)WINDOW_SHOULD_CLOSE, \
		"c@:@"\
	);
	objc_registerClassPair(VOYAGER);
	MSG1(\
		void, \
		GRAPHIC->WINDOW_MODULE, \
		"setDelegate:", \
		id, \
		MSG(\
			id, \
			MSG(\
				id, \
				(id)VOYAGER, \
				"alloc"\
			), \
			"init"\
		)\
	);
	TITLE = MSG1(\
		id, \
		REFRESH_SCREEN("NSString"), \
		"stringWithUTF8String:", \
		const char *, \
		GRAPHIC->TITLE\
	);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "setTitle:", id, TITLE);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "makeKeyAndOrderFront:", id, \
		((void *)0));
	MSG(void, GRAPHIC->WINDOW_MODULE, "center");
	MSG1(void, NSApp, "activateIgnoringOtherApps:", BOOL, YES);
	glFlush();
	return (0);
}

extern INLINE BOOL
	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, const id WINDOW)
{
	IGNORE VIEW;
	IGNORE SELECTOR;
	IGNORE WINDOW;

	MSG1(void, NSApp, "terminate:", id, NSApp);
	return (YES);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__WINDOW_OPEN_C */
