#ifndef WINDOW_RESIZE_H
#define WINDOW_RESIZE_H

#include "window.h"

#define RESIZE_NONE   0
#define RESIZE_LEFT   1
#define RESIZE_RIGHT  2
#define RESIZE_TOP    4
#define RESIZE_BOTTOM 8

void window_resize_begin(Window *window, int edge);

void window_resize_update(Window *window, int mouseX, int mouseY);

void window_resize_end(Window *window);

int window_resize_active(Window *window);

#endif