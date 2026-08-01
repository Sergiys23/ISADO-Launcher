#ifndef TERMINAL_H
#define TERMINAL_H

#include <SDL2/SDL.h>

void terminal_init(void);

void terminal_update(void);

void terminal_render(SDL_Renderer *renderer);

void terminal_event(SDL_Event *event);

void terminal_shutdown(void);

#endif