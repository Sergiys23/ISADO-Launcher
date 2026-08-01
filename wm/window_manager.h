#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SDL2/SDL.h>
#include "window.h"

#define MAX_WINDOWS 32

void window_manager_init(void);

void window_manager_add(Window *window);

void window_manager_draw(SDL_Renderer *renderer);

void window_manager_mouse(SDL_Event *event);

#endif