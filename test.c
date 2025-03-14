
#include "GRAPHIC.h"

// Windows: gcc test.c graphic.a -lwinmm -lgdi32

// MACOS: gcc graphic.a test.c -framework Cocoa -framework AudioToolbox

// MACOS_OPENGL: gcc graphic.a test.c -framework Cocoa -framework AudioToolbox -framework OpenGL

// Unix: gcc graphic.a test.c -lX11 -lasound

int colorOffset = 0;

int
	test(void *arg)
{
	struct graphic	*graphic;

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
		window_close(graphic);

	return (0);
}

int
	main(void)
{
	struct graphic	graphic;

	graphic_setup(&graphic);
	graphic.WINDOW_STYLE.TRANSPARENCY = 1;
	graphic.FPS = 120;
	window_open(&graphic, 1400, 800);
	event_hook_loop(&graphic, test, (void *)&graphic);
	graphic_loop(&graphic);
	return (0);
}