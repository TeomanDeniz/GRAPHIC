
#include "LIBCGFX.h"
#include <stdio.h>

// Windows: gcc test.c LIBCGFX.a -lwinmm -lgdi32

// MACOS: gcc LIBCGFX.a test.c -framework Cocoa -framework AudioToolbox

// MACOS_OPENGL: gcc LIBCGFX.a test.c -framework Cocoa -framework AudioToolbox -framework OpenGL

// Unix: gcc LIBCGFX.a test.c -lX11 -lasound

int colorOffset = 0;

int
	loop(void *arg)
{
	struct s_app	*graphic;

	graphic = arg;
	colorOffset = (colorOffset + 5) % 255;

	for (int y = 0; y < graphic->height; y++)
	{
		for (int x = 0; x < graphic->width; x++)
		{
			int a = (x * 255) / graphic->width;
			int r = ((y * 255) / graphic->height) * a / 255;
			int g = ((colorOffset + x) % 255) * a / 255;
			int b = ((colorOffset + y) % 255) * a / 255;

			put_pixel(graphic, x, y, (a << 24) | (r << 16) | (g << 8) | b);
		}
	}

	if (graphic->key.esc)
		close_window(graphic);

	return (0);
}

int
	resize(void *arg)
{
	struct s_app	*graphic;

	graphic = arg;

	for (int y = 0; y < graphic->height; y++)
	{
		for (int x = 0; x < graphic->width; x++)
		{
			int a = (x * 255) / graphic->width;
			int r = ((y * 255) / graphic->height) * a / 255;
			int g = ((colorOffset + x) % 255) * a / 255;
			int b = ((colorOffset + y) % 255) * a / 255;

			put_pixel(graphic, x, y, (a << 24) | (r << 16) | (g << 8) | b);
		}
	}

	if (graphic->key.esc)
		close_window(graphic);

	return (0);
}

int
	main(void)
{
	struct s_app	graphic;

	app_setup(&graphic);
	graphic.window.transparency = 1;
	graphic.fps = 0;
	create_window(&graphic, 600, 600);
	event_hook_loop(&graphic, loop, (void *)&graphic);
	event_hook_resize(&graphic, resize, (void *)&graphic);
	app_loop(&graphic);
	return (0);
}