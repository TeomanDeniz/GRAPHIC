
#include "LIBCGFX.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Windows: gcc test_voxel.c LIBCGFX.a -lwinmm -lgdi32

// MACOS: gcc LIBCGFX.a test_voxel.c -framework Cocoa -framework AudioToolbox

// MACOS_OPENGL: gcc LIBCGFX.a test_voxel.c -framework Cocoa -framework AudioToolbox -framework OpenGL

// Unix: gcc LIBCGFX.a test_voxel.c -lX11 -lasound

#define CUBE_SIZE     20
#define MAP_SIZE      10
#define PERSPECTIVE      0.661 // 65 degree

typedef struct
{
	int				visible;
	unsigned int	color;
} t_block;

t_block example_3d_map[MAP_SIZE][MAP_SIZE][MAP_SIZE] = {0};

float camera_pos_x = 2.0f;
float camera_pos_y = 2.0f;
float camera_pos_z = 1.0f;
float camera_radiant_x = 0.0f; // I think it must be look right. So the value seems true.
float camera_radiant_y = 0.0f; // I don't know... Maybe 0.0...

void draw_line(struct s_app *app, int x1, int y1, int x2, int y2, unsigned int color)
{
	int dx, dy, sx, sy, err, e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;

	while (1)
	{
		if (x1 >= 0 && y1 >= 0 && x1 < app->width && y1 < app->height)
			put_pixel(app, x1, y1, color);

		if (x1 == x2 && y1 == y2)
			break;

		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void project_point(struct s_app *app, float x, float y, float z, int *screen_x, int *screen_y)
{
	const float epsilon = 0.01f; 
	float scale;

	// Translate to camera space
	float dx = x - camera_pos_x;
	float dy = y - camera_pos_y;
	float dz = z - camera_pos_z;

	// Rotate around the X-axis (yaw)
	float rotated_x = dx * cosf(camera_radiant_x) - dz * sinf(camera_radiant_x);
	float rotated_z = dx * sinf(camera_radiant_x) + dz * cosf(camera_radiant_x);

	// Rotate around the Y-axis (pitch)
	float rotated_y = dy * cosf(camera_radiant_y) - rotated_z * sinf(camera_radiant_y);
	rotated_z = dy * sinf(camera_radiant_y) + rotated_z * cosf(camera_radiant_y);

	// Apply perspective projection
	if (rotated_z < 0.0f)
		scale = 10.0;
	else
		scale = PERSPECTIVE / (rotated_z + epsilon);

	*screen_x = (int)(app->width / 2 + rotated_x * scale * app->width);
	*screen_y = (int)(app->height / 2 - rotated_y * scale * app->height);
}


void draw_cube(struct s_app *app, float x, float y, float z, unsigned int color)
{
	int			px[8];
	int			py[8];
	const float	vertices[8][3] = {
		{x, y, z},
		{x + CUBE_SIZE, y, z},
		{x + CUBE_SIZE, y + CUBE_SIZE, z},
		{x, y + CUBE_SIZE, z},
		{x, y, z + CUBE_SIZE},
		{x + CUBE_SIZE, y, z + CUBE_SIZE},
		{x + CUBE_SIZE, y + CUBE_SIZE, z + CUBE_SIZE},
		{x, y + CUBE_SIZE, z + CUBE_SIZE}
	};
	
	for (int i = 0; i < 8; i++)
		project_point(app, vertices[i][0], vertices[i][1], vertices[i][2], &px[i], &py[i]);
	
	// Draw cube edges
	draw_line(app, px[0], py[0], px[1], py[1], color);
	draw_line(app, px[1], py[1], px[2], py[2], color);
	draw_line(app, px[2], py[2], px[3], py[3], color);
	draw_line(app, px[3], py[3], px[0], py[0], color);
	
	draw_line(app, px[4], py[4], px[5], py[5], color);
	draw_line(app, px[5], py[5], px[6], py[6], color);
	draw_line(app, px[6], py[6], px[7], py[7], color);
	draw_line(app, px[7], py[7], px[4], py[4], color);
	
	draw_line(app, px[0], py[0], px[4], py[4], color);
	draw_line(app, px[1], py[1], px[5], py[5], color);
	draw_line(app, px[2], py[2], px[6], py[6], color);
	draw_line(app, px[3], py[3], px[7], py[7], color);
}

void render_voxels(struct s_app *app)
{
	for (int x = 0; x < MAP_SIZE; x++)
	{
		for (int y = 0; y < MAP_SIZE; y++)
		{
			for (int z = 0; z < MAP_SIZE; z++)
			{
				if (example_3d_map[x][y][z].visible)
				{
					draw_cube(app, x * CUBE_SIZE, y * CUBE_SIZE, z * CUBE_SIZE, example_3d_map[x][y][z].color);
				}
			}
		}
	}
}

int loop(void *arg)
{
	struct s_app	*app;

	app = arg;

	memset(app->buffer, 0, app->width * app->height * sizeof(unsigned int)); // CLEAR SCREEN

	render_voxels(app);

	if (app->key.esc)
		close_window(app);

	if (app->key.w)
	{
		camera_pos_z += cosf(camera_radiant_x) * 1.0f;
		camera_pos_x -= -(sinf(camera_radiant_x) * 1.0f);
	}
	if (app->key.s)
	{
		camera_pos_z -= cosf(camera_radiant_x) * 1.0f;
		camera_pos_x += -(sinf(camera_radiant_x) * 1.0f);
	}
	if (app->key.d)
	{
		camera_pos_z += -(sinf(camera_radiant_x) * 1.0f);
		camera_pos_x += cosf(camera_radiant_x) * 1.0f;
	}
	if (app->key.a)
	{
		camera_pos_z -= -(sinf(camera_radiant_x) * 1.0f);
		camera_pos_x -= cosf(camera_radiant_x) * 1.0f;
	}
	if (app->key.space)
		camera_pos_y += 1;
	if (app->key.shift)
		camera_pos_y -= 1;
	if (app->key.arrow_right)
		camera_radiant_x += 0.05;
	if (app->key.arrow_left)
		camera_radiant_x -= 0.05;
	if (app->key.arrow_up)
		camera_radiant_y += 0.05;
	if (app->key.arrow_down)
		camera_radiant_y -= 0.05;

	return (0);
}

int
	main(void)
{
	struct s_app	app;

	app_setup(&app);
	app.fps = 0; // No Limit
	app.window.resizable = 1;

	example_3d_map[2][2][2].color = 0xFF0000; // Red voxel
	example_3d_map[3][2][2].color = 0x00FF00; // Green voxel
	example_3d_map[4][2][2].color = 0x0000FF; // Blue voxel
	example_3d_map[2][2][2].visible = 1;
	example_3d_map[3][2][2].visible = 1;
	example_3d_map[4][2][2].visible = 1;
	example_3d_map[2][5][5].color = 0xFFFFFF; // White voxel
	example_3d_map[2][5][5].visible = 1;
	create_window(&app, 600, 600);
	event_hook_loop(&app, loop, (void *)&app);
	app_loop(&app);
	return (0);
}