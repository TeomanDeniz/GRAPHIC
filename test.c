
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

	static int i = 0;
	static int j = 0;
	register int x;
	register int y;

	y = -1;
	while (++y, y < graphic->height)
	{
		x = -1;
		while (++x, x < graphic->width)
		{
			put_pixel(graphic, x, y, 0XFF0000 - (i + j));
			j++;
		}
		++i;
	}

	if (graphic->key.esc)
		window_close(graphic);

	return (0);
}

int
	main(void)
{
	struct graphic	graphic;

	graphic_setup(&graphic);
	window_open(&graphic, 1000, 754);
	event_hook_loop(&graphic, test, (void *)&graphic);
	graphic_loop(&graphic);
	return (0);
}