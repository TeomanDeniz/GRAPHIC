/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/                    #       Maximum Tension       #
# CREATE_WINDOW__MACOS_OPENGL                    #                             #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/06/08 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../../LIBCGFX.h" /*
#	 struct S_APP;
#	   void CLOSE_WINDOW(struct S_APP *);
#	        */
#	include "../../../LIBCMT/FUNCTIONS/PREFETCH.h" /*
#	   void PREFETCH_RANGE(void *, uint);
#	        */
#	include "../../../LIBCMT/KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include "../../../LIBCMT/KEYWORDS/IGNORE_VAR.h" /*
#	 define IGNORE_VAR
#	        */
#	include <stdlib.h> /*
#	   void *malloc(size_t);
#	   void free(void *);
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
#	ifndef OBJC
#		define OBJC(\
			__OBJC_ROUGHNESS__, \
			__OBJC_OPTION__, \
			__OBJC_SIZE__\
		) (\
			(\
				__OBJC_ROUGHNESS__(*)\
				(\
					id, \
					SEL\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC_OPTION__, \
			sel_getUid(__OBJC_SIZE__)\
		)
#	endif /* !OBJC */
#	ifndef OBJC1
#		define OBJC1(\
			__OBJC1_ROUGHNESS__, \
			__OBJC1_OPTION__, \
			__OBJC1_SIZE__, \
			__OBJC1_A__, \
			__OBJC1_a__\
		) (\
			(\
				__OBJC1_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__OBJC1_A__\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC1_OPTION__, \
			sel_getUid(__OBJC1_SIZE__), \
			__OBJC1_a__\
		)
#	endif /* !OBJC1 */
#	ifndef OBJC4
#		define OBJC4(\
			__OBJC4_ROUGHNESS__, \
			__OBJC4_OPTION__, \
			__OBJC4_SIZE__, \
			__OBJC4_A__, \
			__OBJC4_a__, \
			__OBJC4_B__, \
			__OBJC4_b__, \
			__OBJC4_C__, \
			__OBJC4_c__, \
			__OBJC4_D__, \
			__OBJC4_d__\
		) (\
			(\
				__OBJC4_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__OBJC4_A__, \
					__OBJC4_B__, \
					__OBJC4_C__, \
					__OBJC4_D__\
				)\
			)\
			objc_msgSend\
		) (\
			__OBJC4_OPTION__, \
			sel_getUid(__OBJC4_SIZE__), \
			__OBJC4_a__, \
			__OBJC4_b__, \
			__OBJC4_c__, \
			__OBJC4_d__\
		)
#	endif /* !OBJC4 */
#	ifndef REFRESH_SCREEN
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)
#	endif /* !REFRESH_SCREEN */
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
	CREATE_WINDOW(
	struct S_APP *APP,
	register unsigned int WIDTH,
	register unsigned int HEIGHT
)
{
	Class					VOYAGER;
	id						TITLE;
	CGLPixelFormatObj		PIXEL_FORMAT;
	GLint					NUMBER;
	CGLPixelFormatAttribute	GL_ATTRIBUTES[4];
	register GLuint			FRAGMENT_SHADER;
	register GLuint			VERTEX_SHADER;

	IGNORE_VAR	NUMBER;

	if (!APP || !APP->TITLE)
		return (-1);

	GL_ATTRIBUTES[0] = (CGLPixelFormatAttribute)kCGLPFAAllRenderers;
	GL_ATTRIBUTES[1] = (CGLPixelFormatAttribute)kCGLPFAOpenGLProfile;
	GL_ATTRIBUTES[2] = (CGLPixelFormatAttribute)kCGLOGLPVersion_GL3_Core;
	GL_ATTRIBUTES[3] = (CGLPixelFormatAttribute)0;

	if (CGLChoosePixelFormat(GL_ATTRIBUTES, &PIXEL_FORMAT, &NUMBER))
		return (-2);

	if (CGLCreateContext(PIXEL_FORMAT, ((void *)0), &APP->CONTEXT))
	{
		CGLDestroyPixelFormat(PIXEL_FORMAT);
		return (-3);
	}

	VERTEX_SHADER = glCreateShader(GL_VERTEX_SHADER);
	CGLDestroyPixelFormat(PIXEL_FORMAT);
	glShaderSource(
		VERTEX_SHADER,
		1,
		(const GLchar *const *)&VERTEX_SHADER_SOURCE,
		((GLint *)0)
	);
	glCompileShader(VERTEX_SHADER);
	FRAGMENT_SHADER = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(
		FRAGMENT_SHADER,
		1,
		(const GLchar *const *)&FRAGMENT_SHADER_SOURCE,
		((GLint *)0)
	);
	glCompileShader(FRAGMENT_SHADER);
	CGLSetCurrentContext(APP->CONTEXT);
	APP->PROGRAM = glCreateProgram();

	if (!APP->PROGRAM)
	{
		GLenum (GL_ERROR);

		GL_ERROR = glGetError();
		glDeleteShader(VERTEX_SHADER);
		glDeleteShader(FRAGMENT_SHADER);

		if (GL_ERROR != GL_NO_ERROR)
			return (GL_ERROR);
		else
			return (-4);
	}

	glAttachShader(APP->PROGRAM, VERTEX_SHADER);
	glAttachShader(APP->PROGRAM, FRAGMENT_SHADER);
	glLinkProgram(APP->PROGRAM);
	glDeleteShader(VERTEX_SHADER);
	glDeleteShader(FRAGMENT_SHADER);
	glGenBuffers(1, &APP->VERTEX_BUFFER_OBJECT);

	if (APP->VERTEX_BUFFER_OBJECT == 0)
	{
		glDeleteProgram(APP->PROGRAM);
		return (-5);
	}

	glBindBuffer(GL_ARRAY_BUFFER, APP->VERTEX_BUFFER_OBJECT);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(VERTEX_BUFFER),
		VERTEX_BUFFER,
		GL_STATIC_DRAW
	);
	glGenTextures(1, &APP->TEXTURE);

	if (APP->TEXTURE == 0)
	{
		glDeleteBuffers(1, &APP->VERTEX_BUFFER_OBJECT);
		APP->VERTEX_BUFFER_OBJECT = 0;
		glDeleteProgram(APP->PROGRAM);
		return (-6);
	}

	glBindTexture(GL_TEXTURE_2D, APP->TEXTURE);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		APP->WIDTH,
		APP->HEIGHT,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		((void *)0)
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	APP->BUFFER = (unsigned int *)
		malloc(sizeof(unsigned int) * ((WIDTH * HEIGHT) + 1));

	if (!APP->BUFFER)
	{
		glDeleteTextures(1, &APP->TEXTURE);
		APP->TEXTURE = 0;
		glDeleteBuffers(1, &APP->VERTEX_BUFFER_OBJECT);
		APP->VERTEX_BUFFER_OBJECT = 0;
		glDeleteProgram(APP->PROGRAM);
		return (-7);
	}

	PREFETCH_RANGE(APP->BUFFER, WIDTH * HEIGHT);
	APP->WIDTH = WIDTH;
	APP->HEIGHT = HEIGHT;
	OBJC(id, REFRESH_SCREEN("NSApplication"), "sharedApplication");
	OBJC1(void, NSApp, "setActivationPolicy:", NSInteger, 0);
	APP->WINDOW_MODULE = OBJC4(
		id,
		OBJC(
			id,
			REFRESH_SCREEN("NSWindow"),
			"alloc"
		),
		"initWithContentRect:styleMask:backing:defer:",
		CGRect,
		CGRectMake(
			0,
			0,
			APP->WIDTH,
			APP->HEIGHT
		),
		NSUInteger,
		3,
		NSUInteger,
		2,
		BOOL,
		NO
	);

	if (!APP->WINDOW_MODULE)
	{
		glDeleteTextures(1, &APP->TEXTURE);
		APP->TEXTURE = 0;
		glDeleteBuffers(1, &APP->VERTEX_BUFFER_OBJECT);
		APP->VERTEX_BUFFER_OBJECT = 0;
		glDeleteProgram(APP->PROGRAM);
		free(APP->BUFFER);
		APP->BUFFER = ((void *)0);
		return (-8);
	}

	VOYAGER = objc_allocateClassPair(
		(Class)REFRESH_SCREEN("NSObject"),
		"WindowDelegate",
		0
	);

	if (!VOYAGER)
	{
		CLOSE_WINDOW(APP);
		return (-9);
	}

	class_addMethod(
		VOYAGER,
		sel_getUid("windowShouldClose:"),
		(IMP)WINDOW_SHOULD_CLOSE,
		"c@:@"
	);
	objc_registerClassPair(VOYAGER);
	OBJC1(
		void,
		APP->WINDOW_MODULE,
		"setDelegate:",
		id,
		OBJC(
			id,
			OBJC(
				id,
				(id)VOYAGER,
				"alloc"
			),
			"init"
		)
	);
	TITLE = OBJC1(
		id,
		REFRESH_SCREEN("NSString"),
		"stringWithUTF8String:",
		const char *,
		APP->TITLE
	);
	OBJC1(void, APP->WINDOW_MODULE, "setTitle:", id, TITLE);
	OBJC1(
		void,
		APP->WINDOW_MODULE,
		"makeKeyAndOrderFront:",
		id,
		((void *)0)
	);
	OBJC(void, APP->WINDOW_MODULE, "center");
	OBJC1(void, NSApp, "activateIgnoringOtherApps:", BOOL, YES);
	glFlush();
	return (0);
}

extern INLINE BOOL
	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, const id WINDOW)
{
	IGNORE_VAR	VIEW;
	IGNORE_VAR	SELECTOR;
	IGNORE_VAR	WINDOW;

	OBJC1(void, NSApp, "terminate:", id, NSApp);
	return (YES);
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CREATE_WINDOW_C */
