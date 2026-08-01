#ifndef WINDOW_DRAG_H
#define WINDOW_DRAG_H

#include "window.h"

void window_drag_begin(Window *window, int mouseX, int mouseY);

void window_drag_update(Window *window, int mouseX, int mouseY);

void window_drag_end(Window *window);

int window_drag_active(Window *window);

#endif