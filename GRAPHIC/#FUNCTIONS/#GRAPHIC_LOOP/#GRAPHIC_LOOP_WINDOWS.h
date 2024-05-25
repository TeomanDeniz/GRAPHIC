/******************************************************************************\
# H - GRAPHIC/#FUNCIONS/#GRAPHIC_LOOP_WINDOWS    #       Maximum Tension       #
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

#ifdef GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H
/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../#STRUCT.h" /*
#	 struct GRAPHIC;
#	        */
#	include <winuser.h> /*
#	 define PeekMessage
#	 define PM_REMOVE
#	 define WM_QUIT
#	 define DispatchMessage
#	typedef MSG;
#	   BOOL TranslateMessage(MSG *);
#	   BOOL InvalidateRect(HWND, LPCRECT, BOOL);
#	        */
#	include <windef.h> /*
#	 define TRUE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
static int	__GRAPHIC_LOOP__(struct GRAPHIC *GRAPHIC);
/* *************************** [^] PROTOTYPES [^] *************************** */
int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	if (!!GRAPHIC->FUNCTION_LOOP)
	{
		while (!__GRAPHIC_LOOP__(GRAPHIC))
			GRAPHIC->FUNCTION_LOOP(GRAPHIC->FUNCTION_LOOP_ARG);
	}
	else
		while (!__GRAPHIC_LOOP__(GRAPHIC))
			(void)0;
	return (0);
}

static int
	__GRAPHIC_LOOP__(struct GRAPHIC *GRAPHIC)
{
	MSG (MSG);

	while (PeekMessage(&MSG, NULL, 0, 0, PM_REMOVE))
	{
		if (MSG.message == WM_QUIT)
			return (1);

		TranslateMessage(&MSG);
		DispatchMessage(&MSG);
	}

	InvalidateRect(GRAPHIC->WINDOW_HANDLE, NULL, TRUE);
	return (0);
}
#else
#	error "Please do not include this header directly!"
#endif /* GRAPHIC_FUNCTIONS__GRAPHIC_LOOP_H */
