/******************************************************************************\
# H - LIBCGFX/CORE_FUNCTIONS/                    #       Maximum Tension       #
# CLOSE_WINDOW__MACOS_OPENGL                     #                             #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/06/09 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2025/04/04 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../STRUCTURES.h" /*
#	 struct S_APP;
#	        */
#	include <objc/NSObjCRuntime.h> /*
#	typedef id;
#	        */
#	include <objc/objc-runtime.h> /*
#	typedef *SEL;
#	    SEL sel_getUid(const char *);
#	        */
#	include <stdlib.h> /*
#	   void free(void *);
#	        */
#	include <CoreFoundation/CoreFoundation.h> /*
#	   void CFRunLoopTimerInvalidate(CFRunLoopTimerRef);
#	        */
#	include <CoreGraphics/CoreGraphics.h> /*
#	   void CGColorSpaceRelease(CGColorSpaceRef);
#	   void CGDataProviderRelease(CGDataProviderRef);
#	        */
#	include <OpenGL/gl3.h> /*
#	   void glUseProgram(GLuint);
#	   void glDeleteProgram(GLuint);
#	   void glDeleteBuffers(GLsizei, GLuint *);
#	   void glDeleteTextures(GLsizei, GLuint *);
#	        */
#	include <OpenGL/OpenGL.h> /*
v	>>>>>>> (CGLError)
#	^^^^^^^ CGLSetCurrentContext(CGLContextObj);
v	>>>>>>> (CGLError)
#	^^^^^^^ CGLDestroyContext(CGLContextObj);
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
/* ************************* [^] HELPER MACROS [^] ************************** */

void
	CLOSE_WINDOW(struct S_APP *const APP)
{
	glUseProgram(0);

	if (!!APP->VERTEX_BUFFER_OBJECT)
	{
		glDeleteBuffers(1, &APP->VERTEX_BUFFER_OBJECT);
		APP->VERTEX_BUFFER_OBJECT = 0;
	}

	if (!!APP->TEXTURE)
	{
		glDeleteTextures(1, &APP->TEXTURE);
		APP->TEXTURE = 0;
	}

	if (!!APP->PROGRAM)
		glDeleteProgram(APP->PROGRAM);

	if (!!APP->WINDOW_MODULE)
	{
		OBJC(void, APP->WINDOW_MODULE, "close");
		OBJC(void, APP->WINDOW_MODULE, "release");
		APP->WINDOW_MODULE = ((void *)0);
	}

	if (!!APP->CONTEXT)
	{
		CGLSetCurrentContext(((void *)0));
		CGLDestroyContext(APP->CONTEXT);
		APP->CONTEXT = ((void *)0);
	}

	if (!!APP->BUFFER)
	{
		free(APP->BUFFER);
		APP->BUFFER = ((void *)0);
	}

	if (!!APP->TIMER_ID)
	{
		CFRunLoopTimerInvalidate(APP->TIMER_ID);
		OBJC(void, (id)APP->TIMER_ID, "release"); // Thx MiniLibX!!!
		APP->TIMER_ID = ((void *)0);
	}

	if (!!APP->OBSERVER_ID)
	{
		CFRunLoopObserverInvalidate(APP->OBSERVER_ID);
		OBJC(void, (id)APP->OBSERVER_ID, "release");
		APP->OBSERVER_ID = ((void *)0);
	}
}

#else
#	error "Please do not include this header directly!"
#endif /* LOCALMACRO__LIBCGFX_CORE_FUNCTIONS_CLOSE_WINDOW_C */
