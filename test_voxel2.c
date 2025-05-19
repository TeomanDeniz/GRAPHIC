/*
Can you write me an efficient voxel drawing engine in here? I am going to use it as filling textures on the surfaces and such.



But for now, let's start simple for now and just draw lines around them. The voxels should not be drawn in loop if it's behind the camera (Not totally on the screen). The closest voxel to camera shuld be always at the front (Which means drawn last) and lastly: If a voxel totally behind an another and makes this voxel totally not seenable because it's behind an another voxel, it must be aloso not be drawn too. For optimisation reasons. (Do Not build a triangle system. They are always going to be voxels.)



The camera MUST be in FPS mode. Whcih first person. Not TPS movement. Even thought there's no controls for rotation_z in loop about camera, still include that in rendering calculations.

And lastly: Don't forget to add rotation calculations. Pretend like it's going to be a minecraft game. I just need a simply rendering system.



You can just send the functions that I needed to put instead of re-writing the entire file.
*/


// Windows: gcc test_voxel2.c LIBCGFX.a -lwinmm -lgdi32

// MACOS: gcc LIBCGFX.a test_voxel2.c -framework Cocoa 	-framework AudioToolbox

// MACOS_OPENGL: gcc LIBCGFX.a test_voxel2.c -framework Cocoa -framework AudioToolbox -framework OpenGL

// Unix: gcc LIBCGFX.a test_voxel2.c -lX11 -lasound

#include "LIBCGFX.h"
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

unsigned int test_texture1[24][24];
unsigned int test_texture2[24][24];

void generate_test_texture(
	unsigned int (*texture)[24][24],
	unsigned int color1,
	unsigned int color2,
	unsigned int color3
)
{
	for (int y = 0; y < 24; ++y) {
		for (int x = 0; x < 24; ++x) {
			if ((x / 4 + y / 4) % 2 == 0)
				(*texture)[y][x] = color1; // Red (opaque)
			else if ((x / 2 + y / 2) % 2 == 0)
				(*texture)[y][x] = color2; // Green (semi-transparent)
			else
				(*texture)[y][x] = color3; // Fully transparent
		}
	}

	(*texture)[0][0] = 0XFFFF0000U;
	(*texture)[23][23] = 0XFF00FF00U;
	(*texture)[0][23] = 0XFF00FFFFU;
	(*texture)[23][0] = 0XFFFFFF00U;
}

struct s_cube_3 {
	float x;
	float y;
	float z;
	float size_x;
	float size_y;
	float size_z;
	float rotation_x;
	float rotation_y;
	float rotation_z;
	char  backface_culling;
		// 0 = only outside
		// 1 = only inside
	struct
	{
		unsigned int (*outside[6])[24][24];
		unsigned int (*inside[6])[24][24];
	} texture;

};

struct s_camera {
	float x;
	float y;
	float z;
	float rotation_x;
	float rotation_y;
	float rotation_z;
	float fov;
};

struct s_camera camera;



int project(float x, float y, float z, int *out_x, int *out_y, struct s_app *app) {
	// Translate to camera space
	float dx = x - camera.x;
	float dy = y - camera.y;
	float dz = z - camera.z;

	// Apply camera rotation (Y -> then X -> then Z)
	float cx = cosf(camera.rotation_x), sx = sinf(camera.rotation_x);
	float cy = cosf(camera.rotation_y), sy = sinf(camera.rotation_y);
	float cz = cosf(camera.rotation_z), sz = sinf(camera.rotation_z);

	// Rotate around Y (yaw)
	float xz = cx * dx - sx * dz;
	float zz = sx * dx + cx * dz;

	// Rotate around X (pitch)
	float yz = cy * dy - sy * zz;
	float zz2 = sy * dy + cy * zz;

	// Rotate around Z (roll)
	float xx = cz * xz - sz * yz;
	float yy = sz * xz + cz * yz;
	float zz_final = zz2;

	if (zz_final <= 0.1f)
		return 0; // Behind camera or too close

	// Project to 2D
	*out_x = (int)((xx / zz_final) * camera.fov + app->width / 2);
	*out_y = (int)((yy / zz_final) * camera.fov + app->height / 2);

	// Frustum culling: discard points too far out of bounds
	return *out_x >= -app->width && *out_x <= 2 * app->width &&
	       *out_y >= -app->height && *out_y <= 2 * app->height;
}




void draw_textured_face(struct s_app *app, float p0[3], float p1[3], float p2[3], float p3[3], unsigned int texture[24][24]) {
	int sx[4], sy[4];
	if (!project(p0[0], p0[1], p0[2], &sx[0], &sy[0], app)) return;
	if (!project(p1[0], p1[1], p1[2], &sx[1], &sy[1], app)) return;
	if (!project(p2[0], p2[1], p2[2], &sx[2], &sy[2], app)) return;
	if (!project(p3[0], p3[1], p3[2], &sx[3], &sy[3], app)) return;

	struct { int x[3], y[3]; float u[3], v[3]; } tris[2] = {
		{ {sx[0], sx[1], sx[2]}, {sy[0], sy[1], sy[2]}, {0, 1, 1}, {0, 0, 1} },
		{ {sx[0], sx[2], sx[3]}, {sy[0], sy[2], sy[3]}, {0, 1, 0}, {0, 1, 1} }
	};

	for (int t = 0; t < 2; ++t) {
		int *x = tris[t].x, *y = tris[t].y;
		float *u = tris[t].u, *v = tris[t].v;

		int min_x = fmax(fmin(fmin(x[0], x[1]), x[2]), 0);
		int max_x = fmin(fmax(fmax(x[0], x[1]), x[2]), app->width - 1);
		int min_y = fmax(fmin(fmin(y[0], y[1]), y[2]), 0);
		int max_y = fmin(fmax(fmax(y[0], y[1]), y[2]), app->height - 1);

		for (int py = min_y; py <= max_y; ++py) {
			for (int px = min_x; px <= max_x; ++px) {
				float denom = (float)((y[1] - y[2]) * (x[0] - x[2]) + (x[2] - x[1]) * (y[0] - y[2]));
				if (fabsf(denom) < 1e-6f) continue;

				float w0 = ((y[1] - y[2]) * (px - x[2]) + (x[2] - x[1]) * (py - y[2])) / denom;
				float w1 = ((y[2] - y[0]) * (px - x[2]) + (x[0] - x[2]) * (py - y[2])) / denom;
				float w2 = 1.0f - w0 - w1;

				if (w0 < 0 || w1 < 0 || w2 < 0) continue;

				float fu = w0 * u[0] + w1 * u[1] + w2 * u[2];
				float fv = w0 * v[0] + w1 * v[1] + w2 * v[2];

				int tx = (int)(fu * 23.0f + 0.5f);
				int ty = (int)(fv * 23.0f + 0.5f);

				unsigned int pixel = texture[ty][tx];
				if ((pixel >> 24) != 0x00)
					put_pixel(app, px, py, pixel);
			}
		}
	}
}







void draw_line(struct s_app *app, int x1, int y1, int x2, int y2, unsigned int color) {

	{
		float t0 = 0.0f, t1 = 1.0f;
		int dx = x2 - x1;
		int dy = y2 - y1;

		#define CLIP(p, q) do { \
			if ((p) == 0 && (q) < 0) return ; \
			float r = (float)(q) / (float)(p); \
			if ((p) < 0) { if (r > t1) return ; else if (r > t0) t0 = r; } \
			else if ((p) > 0) { if (r < t0) return ; else if (r < t1) t1 = r; } \
		} while (0)

		// Clip against left, right, bottom, top
		CLIP(-dx, x1);             // Left
		CLIP( dx, app->width - 1 - x1); // Right
		CLIP(-dy, y1);             // Bottom
		CLIP( dy, app->height - 1 - y1);// Top

		if (t1 < 1.0f) {
			x2 = x1 + t1 * dx;
			y2 = y1 + t1 * dy;
		}
		if (t0 > 0.0f) {
			x1 = x1 + t0 * dx;
			y1 = y1 + t0 * dy;
		}
	}

	int dx = abs(x2 - x1), dy = abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;

	while (1) {
		put_pixel(app, x1, y1, color);
		if (x1 == x2 && y1 == y2) break;
		int e2 = err;
		if (e2 > -dx) { err -= dy; x1 += sx; }
		if (e2 < dy)  { err += dx; y1 += sy; }
	}
}




void draw_cube(struct s_app *app, struct s_cube_3 cube, unsigned int color) {
	float x = cube.x, y = cube.y, z = cube.z;
	float sx = cube.size_x;
	float sy = cube.size_y;
	float sz = cube.size_z;

	float corners[8][3] = {
		{x - sx, y - sy, z - sz},
		{x + sx, y - sy, z - sz},
		{x + sx, y + sy, z - sz},
		{x - sx, y + sy, z - sz},
		{x - sx, y - sy, z + sz},
		{x + sx, y - sy, z + sz},
		{x + sx, y + sy, z + sz},
		{x - sx, y + sy, z + sz}
	};

	int faces[6][4] = {
		{0, 1, 2, 3}, // Front
		{5, 4, 7, 6}, // Back
		{4, 0, 3, 7}, // Left
		{1, 5, 6, 2}, // Right
		{3, 2, 6, 7}, // Top
		{4, 5, 1, 0}  // Bottom
	};

	if (cube.backface_culling == 1)
	{
		for (int i = 0; i < 6; ++i) // EXTRA CHECK TO DRAW ONLY TEXTURES FRONT OF THE USER
		{
			if (cube.texture.inside[i])
			{
				float face_normals[6][3];

				float *p0 = corners[faces[i][0]];
				float *p1 = corners[faces[i][1]];
				float *p2 = corners[faces[i][2]];

				float u[3] = {p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2]};
				float v[3] = {p2[0] - p0[0], p2[1] - p0[1], p2[2] - p0[2]};

				face_normals[i][0] = u[1] * v[2] - u[2] * v[1];
				face_normals[i][1] = u[2] * v[0] - u[0] * v[2];
				face_normals[i][2] = u[0] * v[1] - u[1] * v[0];

				float cam_dir[3] = {
					camera.x - p0[0],
					camera.y - p0[1],
					camera.z - p0[2]
				};

				float dot =
					face_normals[i][0] * cam_dir[0] +
					face_normals[i][1] * cam_dir[1] +
					face_normals[i][2] * cam_dir[2];

				if (dot > 0)
				{
					draw_textured_face(
						app,
						corners[faces[i][0]],
						corners[faces[i][1]],
						corners[faces[i][2]],
						corners[faces[i][3]],
						*(cube.texture.inside[i])
					);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 6; ++i) // EXTRA CHECK TO DRAW ONLY TEXTURES FRONT OF THE USER
		{
			if (cube.texture.outside[i])
			{
				float face_normals[6][3];

				float *p0 = corners[faces[i][0]];
				float *p1 = corners[faces[i][1]];
				float *p2 = corners[faces[i][2]];

				float u[3] = {p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2]};
				float v[3] = {p2[0] - p0[0], p2[1] - p0[1], p2[2] - p0[2]};

				face_normals[i][0] = u[1] * v[2] - u[2] * v[1];
				face_normals[i][1] = u[2] * v[0] - u[0] * v[2];
				face_normals[i][2] = u[0] * v[1] - u[1] * v[0];

				float cam_dir[3] = {
					camera.x - p0[0],
					camera.y - p0[1],
					camera.z - p0[2]
				};

				float dot =
					face_normals[i][0] * cam_dir[0] +
					face_normals[i][1] * cam_dir[1] +
					face_normals[i][2] * cam_dir[2];

				if (dot <= 0)
				{
					draw_textured_face(
						app,
						corners[faces[i][0]],
						corners[faces[i][1]],
						corners[faces[i][2]],
						corners[faces[i][3]],
						*(cube.texture.outside[i])
					);
				}
			}
		}
	}

#if 1 // DRAW LINES AROUND SHAPES
	int screen[8][2];
	int draw = 0;

	// Project points
	for (int i = 0; i < 8; i++) {
		if (project(corners[i][0], corners[i][1], corners[i][2], &screen[i][0], &screen[i][1], app))
			draw = 1;
	}

	if (!draw)
		return ; // Fully off screen or behind camera

	// Only draw edges where both points are visible (fast culling)
	int edges[12][2] = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0}, // front face
		{4, 5}, {5, 6}, {6, 7}, {7, 4}, // back face
		{0, 4}, {1, 5}, {2, 6}, {3, 7}  // side edges
	};

	for (int i = 0; i < 12; i++) {
		int a = edges[i][0], b = edges[i][1];
		draw_line(app, screen[a][0], screen[a][1], screen[b][0], screen[b][1], color);
	}
#endif
}



int loop(void *arg)
{
	struct s_app *app = arg;

	memset(app->buffer, 0, app->width * app->height * sizeof(unsigned int));

	struct s_cube_3 cubes[3] = {
		{
			1, 82, 3,
			3, 5, 1,
			0, 0, 0,
			0
		},
		{
			2, 82, 11,
			1, 1, 1,
			0, 0, 0,
			1
		},
		{
			3, 82, 20,
			3, 5, 1,
			0, 0, 0,
			1
		}
	};

	int cube_count = sizeof(cubes)/sizeof(cubes[0]);

	// Naive painter’s sort

	for (int i = 0; i < 6; i++)
	{
		cubes[0].texture.outside[i] = &test_texture1;
		cubes[0].texture.inside[i] = &test_texture2;
	}

	for (int i = 0; i < 6; i++)
	{
		cubes[1].texture.outside[i] = &test_texture1;
		cubes[1].texture.inside[i] = &test_texture2;
	}

	for (int i = 0; i < 6; i++)
	{
		cubes[2].texture.outside[i] = &test_texture1;
		cubes[2].texture.inside[i] = &test_texture2;
	}



	for (int i = 0; i < cube_count - 1; i++)
	{
		for (int j = i + 1; j < cube_count; j++)
		{
			float di = powf(cubes[i].x - camera.x, 2) + powf(cubes[i].y - camera.y, 2) + powf(cubes[i].z - camera.z, 2);
			float dj = powf(cubes[j].x - camera.x, 2) + powf(cubes[j].y - camera.y, 2) + powf(cubes[j].z - camera.z, 2);

			if (di < dj)
			{
				struct s_cube_3 tmp = cubes[i];
				cubes[i] = cubes[j];
				cubes[j] = tmp;
			}
		}
	}

	draw_cube(app, cubes[0], 0XFF0000);
	draw_cube(app, cubes[1], 0X00FF00);
	draw_cube(app, cubes[2], 0X0000FF);

	if (app->key.esc)
		return close_window(app), 0;

	if (app->key.w)
	{
		camera.z += cosf(camera.rotation_x) / 2;
		camera.x -= -sinf(camera.rotation_x) / 2;
	}
	if (app->key.s)
	{
		camera.z -= cosf(camera.rotation_x) / 2;
		camera.x += -sinf(camera.rotation_x) / 2;
	}
	if (app->key.d)
	{
		camera.z += -sinf(camera.rotation_x) / 2;
		camera.x += cosf(camera.rotation_x) / 2;
	}
	if (app->key.a)
	{
		camera.z -= -sinf(camera.rotation_x) / 2;
		camera.x -= cosf(camera.rotation_x) / 2;
	}
	if (app->key.space)
		camera.y -= 0.4;
	if (app->key.shift)
		camera.y += 0.4;
	if (app->key.arrow_right)
		camera.rotation_x += 0.04;
	if (app->key.arrow_left)
		camera.rotation_x -= 0.04;
	if (app->key.arrow_up)
		camera.rotation_y -= 0.04;
	if (app->key.arrow_down)
		camera.rotation_y += 0.04;

#if 0
	// TEXTURE PREVIEW
	for (register int x = 0; x < 24; x++)
	{
	    for (register int y = 0; y < 24; y++)
	    {
	        for (register int i = 0; i < 6; i++)       // Scale X
	        {
	            for (register int j = 0; j < 6; j++)   // Scale Y
	            {
	                put_pixel(app, x * 6 + i, y * 6 + j, test_texture2[y][x]);
	            }
	        }
	    }
	}
#endif

	return 0;
}


int main(void) {
	struct s_app app;
	app_setup(&app);

	generate_test_texture(&test_texture1, 0xFF0000FFU, 0x80FF00FFU, 0x00000000U);
	generate_test_texture(&test_texture2, 0xFFFF0000U, 0x0000FFFFU, 0xFF00FFFFU);
	camera.x = 17.98922;
	camera.y = 62;
	camera.z = 26.06;
	camera.rotation_x = -2.32;
	camera.rotation_y = 0.81;
	camera.rotation_z = 0;
	camera.fov = 700;
	app.fps = 90;
	app.window.resizable = 1;

	create_window(&app, 600, 600);
	event_hook_loop(&app, loop, &app);
	app_loop(&app);
	return 0;
}
