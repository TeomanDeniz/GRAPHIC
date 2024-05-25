#include "GRAPHIC.h"

#include <stdio.h>

// Windows: gcc test.c -lwinmm -lgdi32

// MACOS: gcc test.c -framework Cocoa -framework AudioToolbox

// Unix: gcc test.c -lX11 -lasound

int
	test(unsigned int x, unsigned int y, unsigned char value, void *arg)
{
	struct graphic	*graphic;

	graphic = arg;

	printf("%d - %d - %d %d\n", x, y, graphic->mouse.left_down, graphic->mouse.left_up);

	if (graphic->key.esc)
	{
		window_close(graphic);
	}
	return (0);
}

int
	main(void)
{
	struct graphic	graphic;

	graphic_setup(&graphic);
	window_open(&graphic, 700, 700);
	event_hook_mouse(&graphic, test, (void *)&graphic);
	graphic_loop(&graphic);
	return (0);
}