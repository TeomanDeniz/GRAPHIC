#define NS_APPLICATION_ACTIVATION_POLICY_REGULAR 0
#define NS_WINDOW_STYLE_MASK_TITLED     (1 << 0)
#define NS_WINDOW_STYLE_MASK_CLOSABLE   (1 << 1)
#define NS_WINDOW_STYLE_MASK_RESIZABLE  (1 << 3)
#define NS_BACKING_STORE_BUFFERED       2

// clang -framework Cocoa -framework QuartzCore -framework Metal -fobjc-arc -fobjc-runtime=macos -o metal_window macos.c

#import <objc/objc.h>
#import <objc/message.h>
#import <objc/runtime.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/CAMetalLayer.h>
#import <Metal/Metal.h>
#import <Cocoa/Cocoa.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Objective-C Bridge Macros */
#ifndef OBJC
# define OBJC(T, O, M) ((T (*)(id, SEL))objc_msgSend)((O), sel_getUid(M))
#endif
#ifndef OBJC1
# define OBJC1(R, O, M, A, AT) ((R (*)(id, SEL, AT))objc_msgSend)((O), sel_getUid(M), (A))
#endif
#ifndef OBJC2
# define OBJC2(R, O, M, A, AT, B, BT) ((R (*)(id, SEL, AT, BT))objc_msgSend)((O), sel_getUid(M), (A), (B))
#endif

/* GLOBAL STATE */
struct {
	id app;
	id window;
	id device;
	id layer;
	id content_view;
	id pool;
	unsigned int *buffer;
	int width, height;
} APP;

/* FUNCTION: create_window */
void create_window(int w, int h) {
	APP.width = w;
	APP.height = h;
	APP.buffer = calloc(w * h, sizeof(unsigned int));

	APP.pool = OBJC(id, OBJC(id, objc_getClass("NSAutoreleasePool"), "alloc"), "init");

	APP.app = OBJC(id, objc_getClass("NSApplication"), "sharedApplication");
	OBJC1(void, APP.app, "setActivationPolicy:", NS_APPLICATION_ACTIVATION_POLICY_REGULAR, NSInteger);

	// Create window
	NSRect rect = { { 0, 0 }, { w, h } };
	id winAlloc = OBJC(id, objc_getClass("NSWindow"), "alloc");
	APP.window = OBJC2(id, winAlloc, "initWithContentRect:styleMask:backing:defer:",
		rect, NSRect, 
		NS_WINDOW_STYLE_MASK_TITLED | NS_WINDOW_STYLE_MASK_CLOSABLE | NS_WINDOW_STYLE_MASK_RESIZABLE, NSUInteger,
		NS_BACKING_STORE_BUFFERED, NSUInteger,
		NO, BOOL
	);

	id strTitle = OBJC1(id, objc_getClass("NSString"), "stringWithUTF8String:", "Metal Window", const char *);
	OBJC1(void, APP.window, "setTitle:", strTitle, id);
	OBJC1(void, APP.window, "makeKeyAndOrderFront:", nil, id);

	// Metal device
	APP.device = MTLCreateSystemDefaultDevice();

	// CAMetalLayer setup
	id layerClass = objc_getClass("CAMetalLayer");
	APP.layer = OBJC(id, OBJC(id, layerClass, "alloc"), "init");

	OBJC1(void, APP.layer, "setDevice:", APP.device, id);
	OBJC1(void, APP.layer, "setPixelFormat:", 80, NSUInteger); // MTLPixelFormatBGRA8Unorm
	CGSize size = { (CGFloat)w, (CGFloat)h };
	OBJC1(void, APP.layer, "setDrawableSize:", size, CGSize);

	APP.content_view = OBJC(id, APP.window, "contentView");
	OBJC1(void, APP.content_view, "setWantsLayer:", 1, BOOL);
	OBJC1(void, APP.content_view, "setLayer:", APP.layer, id);
}

/* FUNCTION: put_pixel */
void put_pixel(int x, int y, unsigned int color) {
	if (x < 0 || y < 0 || x >= APP.width || y >= APP.height) return;
	APP.buffer[y * APP.width + x] = color;
}

/* FUNCTION: render_frame */
void render_frame() {
	// Fill screen with gradient
	for (int y = 0; y < APP.height; ++y)
	for (int x = 0; x < APP.width; ++x)
		put_pixel(x, y, 0xFF000000 | (x * 255 / APP.width) << 16 | (y * 255 / APP.height));

	// Get next drawable
	SEL sel_nextDrawable = sel_getUid("nextDrawable");
	id drawable = ((id (*)(id, SEL))objc_msgSend)(APP.layer, sel_nextDrawable);
	if (!drawable) return;

	// Get texture from drawable
	SEL sel_texture = sel_getUid("texture");
	id texture = ((id (*)(id, SEL))objc_msgSend)(drawable, sel_texture);

	// Copy buffer to texture
	MTLRegion region = { {0, 0, 0}, {APP.width, APP.height, 1} };
	((void (*)(id, SEL, MTLRegion, NSUInteger, const void *, NSUInteger))objc_msgSend)(
		texture,
		sel_getUid("replaceRegion:mipmapLevel:withBytes:bytesPerRow:"),
		region,
		0,
		APP.buffer,
		APP.width * 4
	);

	// Present
	id commandQueue = OBJC(id, APP.device, "newCommandQueue");
	id commandBuffer = OBJC(id, commandQueue, "commandBuffer");
	OBJC1(void, commandBuffer, "presentDrawable:", drawable, id);
	OBJC(void, commandBuffer, "commit");
}

/* FUNCTION: close_window */
void close_window() {
	free(APP.buffer);
	OBJC(void, APP.pool, "drain");
}

/* MAIN LOOP */
int main() {
	create_window(640, 480);

	while (1) {
		render_frame();
		usleep(16000); // ~60 FPS
	}
	close_window();
	return 0;
}
