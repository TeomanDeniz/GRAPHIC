
#include "GRAPHIC.h"

#include <stdio.h>

// Windows: gcc test.c -lwinmm -lgdi32

// MACOS: gcc test.c -framework Cocoa -framework AudioToolbox

// Unix: gcc test.c -lX11 -lasound

int
	test(void *arg)
{
	struct graphic	*graphic;

	graphic = arg;

	if (graphic->mouse.x - 15 >= 0 && graphic->mouse.x - 15 < graphic->width && \
		graphic->mouse.y - 15 >= 0 && graphic->mouse.y - 15 < graphic->height)
		put_pixel(graphic, graphic->mouse.x - 15, graphic->mouse.y - 15, 0XFF0000);

	if (graphic->key.esc)
		window_close(graphic);

	return (0);
}

int
	main(void)
{
	struct graphic	graphic;

	graphic_setup(&graphic);
	window_open(&graphic, 700, 700);
	event_hook_loop(&graphic, test, (void *)&graphic);
	graphic_loop(&graphic);
	return (0);
}