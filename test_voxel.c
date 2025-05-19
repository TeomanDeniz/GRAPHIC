
// Windows: gcc test_voxel.c LIBCGFX.a -lwinmm -lgdi32

// MACOS: gcc LIBCGFX.a test_voxel.c -framework Cocoa 	-framework AudioToolbox

// MACOS_OPENGL: gcc LIBCGFX.a test_voxel.c -framework Cocoa -framework AudioToolbox -framework OpenGL

// Unix: gcc LIBCGFX.a test_voxel.c -lX11 -lasound

#include "LIBCGFX.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUBE_SIZE    30
#define MAP_SIZE     10
#define PERSPECTIVE  0.698f // 40 degrees

#define MAX_VERTICES 8
#define MAX_INDICES  36

#define TEXTURE 1



unsigned int test_texture[24][24];

void generate_test_texture() {
	for (int y = 0; y < 24; ++y) {
		for (int x = 0; x < 24; ++x) {
			if ((x / 4 + y / 4) % 2 == 0)
				test_texture[y][x] = 0xFF0000FFU; // Red (opaque)
			else if ((x / 2 + y / 2) % 2 == 0)
				test_texture[y][x] = 0x80FF00FFU; // Green (semi-transparent)
			else
				test_texture[y][x] = 0x00000000U; // Fully transparent
		}
	}

	test_texture[0][0] = 0XFFFF0000U;
	test_texture[23][23] = 0XFF00FF00U;
	test_texture[0][23] = 0XFF00FFFFU;
	test_texture[23][0] = 0XFFFFFF00U;
}


typedef struct {
	float x, y, z;
} vec3;

typedef struct {
	vec3 vertices[MAX_VERTICES];
	int  indices[MAX_INDICES];
	unsigned int color;
} s_block_3d;

float camera_pos_x = 7.534571f;
float camera_pos_y = 86.0f;
float camera_pos_z = 5.849144f;
float camera_radiant_x = 0.7f;
float camera_radiant_y = -0.25f;

s_block_3d create_slab(float x, float y, float z, float size, unsigned int color) {
	s_block_3d block;
	block.color = color;

	float s = size;
	block.vertices[0] = (vec3){x,     y,     z};
	block.vertices[1] = (vec3){x + s, y,     z};
	block.vertices[2] = (vec3){x + s, y + s / 2, z};
	block.vertices[3] = (vec3){x,     y + s / 2, z};
	block.vertices[4] = (vec3){x,     y,     z + s};
	block.vertices[5] = (vec3){x + s, y,     z + s};
	block.vertices[6] = (vec3){x + s, y + s / 2, z + s};
	block.vertices[7] = (vec3){x,     y + s / 2, z + s};

	int indices[] = {
		0,1,2, 2,3,0, // front
		4,5,6, 6,7,4, // back
		0,4,7, 7,3,0, // left
		1,5,6, 6,2,1, // right
		3,2,6, 6,7,3, // top
		0,3,4, 5,6,1  // bottom
	};
	memcpy(block.indices, indices, sizeof(indices));

	return block;
}

s_block_3d create_cube(float x, float y, float z, float size, unsigned int color) {
	s_block_3d block;

	float s = size;
	block.color = color;

	block.vertices[0] = (vec3){x,     y,     z};
	block.vertices[1] = (vec3){x + s, y,     z};
	block.vertices[2] = (vec3){x + s, y + s, z};
	block.vertices[3] = (vec3){x,     y + s, z};
	block.vertices[4] = (vec3){x,     y,     z + s};
	block.vertices[5] = (vec3){x + s, y,     z + s};
	block.vertices[6] = (vec3){x + s, y + s, z + s};
	block.vertices[7] = (vec3){x,     y + s, z + s};

	// indices forming 12 triangles (2 per face)
	int cube_indices[] = {
		0,1,2, 2,3,0, // front
		4,5,6, 6,7,4, // back
		0,4,7, 7,3,0, // left
		1,5,6, 6,2,1, // right
		3,2,6, 6,7,3, // top
		0,3,4, 5,6,1  // bottom
	};
	/*
	int cube_indices[] = {
		0,1,2, 2,3,0,
		1,5,6, 6,2,1,
		0,0,0, 0,0,0,
		0,0,0, 0,0,0,
		0,0,0, 0,0,0,
		0,0,0, 0,0,0
	};
	*/

	memcpy(block.indices, cube_indices, sizeof(cube_indices));

	return block;
}





// Helper: calculate edge function
float edge_function(int x0, int y0, int x1, int y1, int x, int y)
{
	return (float)(x - x0) * (y1 - y0) - (y - y0) * (x1 - x0);
}

// Fill a textured triangle
void fill_triangle_textured(struct s_app *app,
	int x0, int y0, int x1, int y1, int x2, int y2,
	int texture[24][24], int tex_width, int tex_height)
{
	int min_x = (x0 < x1 ? (x0 < x2 ? x0 : x2) : (x1 < x2 ? x1 : x2));
	int min_y = (y0 < y1 ? (y0 < y2 ? y0 : y2) : (y1 < y2 ? y1 : y2));
	int max_x = (x0 > x1 ? (x0 > x2 ? x0 : x2) : (x1 > x2 ? x1 : x2));
	int max_y = (y0 > y1 ? (y0 > y2 ? y0 : y2) : (y1 > y2 ? y1 : y2));

	float area = edge_function(x0, y0, x1, y1, x2, y2);
	if (area == 0.0f)
		return; // Degenerate triangle

	for (int y = min_y; y <= max_y; ++y) {
		for (int x = min_x; x <= max_x; ++x) {
			float w0 = edge_function(x1, y1, x2, y2, x, y);
			float w1 = edge_function(x2, y2, x0, y0, x, y);
			float w2 = edge_function(x0, y0, x1, y1, x, y);

			if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
				// Normalize barycentric coordinates
				w0 /= area;
				w1 /= area;
				w2 /= area;

				// Use barycentric coordinates for simple UV mapping
				int u = (int)((w1 * 1.0f + w2 * 1.0f) * (tex_width - 1));
				int v = (int)((w2 * 1.0f) * (tex_height - 1));

				u = u < 0 ? 0 : (u >= tex_width ? tex_width - 1 : u);
				v = v < 0 ? 0 : (v >= tex_height ? tex_height - 1 : v);

				unsigned int color = texture[v][u];
				if ((color & 0xFF000000U) != 0) // Only draw if not transparent
					if (x >= 0 && y >= 0 && x < app->width && y < app->height)
						put_pixel(app, x, y, color);
			}
		}
	}
}



void draw_line(struct s_app *app, int x1, int y1, int x2, int y2, unsigned int color) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;

	while (x1 < app->width && y1 < app->height && x1 >= 0 && y1 >= 0)
	{
		put_pixel(app, x1, y1, color);

		if ((x1 == x2 && y1 == y2))
			break ;

		int e2 = err;
		if (e2 > -dx) { err -= dy; x1 += sx; }
		if (e2 < dy)  { err += dx; y1 += sy; }
	}
}

void
	project_point(struct s_app *app, float x, float y, float z, int *screen_x, int *screen_y)
{
	const float epsilon = 0.01f;

	float scale;
	float dx = x - camera_pos_x;
	float dy = y - camera_pos_y;
	float dz = z - camera_pos_z;
	float rotated_x = dx * cosf(camera_radiant_x) - dz * sinf(camera_radiant_x);
	float rotated_z = dx * sinf(camera_radiant_x) + dz * cosf(camera_radiant_x);
	float rotated_y = dy * cosf(camera_radiant_y) - rotated_z * sinf(camera_radiant_y);
	rotated_z = dy * sinf(camera_radiant_y) + rotated_z * cosf(camera_radiant_y);

	if (rotated_z < 0.0f)
		scale = 10.0;
	else
		scale = PERSPECTIVE / (rotated_z + epsilon);

	*screen_x = (int)(app->width / 2 + rotated_x * scale * app->width);
	*screen_y = (int)(app->height / 2 - rotated_y * scale * app->height);
}

void draw_block(struct s_app *app, s_block_3d *block) {
	int px[MAX_VERTICES], py[MAX_VERTICES];

	for (int i = 0; i < MAX_VERTICES; ++i)
		project_point(app, block->vertices[i].x, block->vertices[i].y, block->vertices[i].z, &px[i], &py[i]);

	for (int i = 0; i < MAX_INDICES; i += 3) {
		int i0 = block->indices[i];
		int i1 = block->indices[i + 1];
		int i2 = block->indices[i + 2];

		if (!TEXTURE)
		{
			draw_line(app, px[i0], py[i0], px[i1], py[i1], block->color);
			draw_line(app, px[i1], py[i1], px[i2], py[i2], block->color);
			draw_line(app, px[i2], py[i2], px[i0], py[i0], block->color);
		}
		else
		{
			fill_triangle_textured(app,
				px[i0], py[i0],
				px[i1], py[i1],
				px[i2], py[i2],
				test_texture, // use block's texture
				24, 24 // your texture size
			);
		}
	}
}


void render_voxels(struct s_app *app) {
	for (int x = 0; x < MAP_SIZE; x++) {
		for (int y = 0; y < MAP_SIZE; y++) {
			for (int z = 0; z < MAP_SIZE; z++) {
				// Example slab at center
				if (x == 5 && y == 5 && z == 5) {
					unsigned int color = test_texture[y % 24][x % 24];
					if ((color & 0xFF000000U) == 0) continue; // Skip fully transparent blocks

					s_block_3d block = create_slab(x * CUBE_SIZE, y * CUBE_SIZE, z * CUBE_SIZE, CUBE_SIZE, color);
					draw_block(app, &block);
				}
				if (x == 1 && y == 2 && z == 1) {
					unsigned int color = test_texture[y % 24][x % 24];
					if ((color & 0xFF000000U) == 0) continue; // Skip fully transparent blocks

					s_block_3d block = create_cube(x * CUBE_SIZE, y * CUBE_SIZE, z * CUBE_SIZE, CUBE_SIZE, color);
					draw_block(app, &block);
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
	{
		close_window(app);
		return (0);
	}

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

	for (register int x = 0; x < 24; x++)
	{
	    for (register int y = 0; y < 24; y++)
	    {
	        for (register int i = 0; i < 6; i++)       // Scale X
	        {
	            for (register int j = 0; j < 6; j++)   // Scale Y
	            {
	                put_pixel(app, x * 6 + i, y * 6 + j, test_texture[y][x]);
	            }
	        }
	    }
	}

	return (0);
}

int main(void) {
	struct s_app app;
	app_setup(&app);

	app.fps = 90;
	app.window.resizable = 1;

	generate_test_texture();

	create_window(&app, 600, 600);
	event_hook_loop(&app, loop, &app);
	app_loop(&app);
	return 0;
}
