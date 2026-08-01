#ifndef EXPLORER_H
#define EXPLORER_H

#include <SDL2/SDL.h>

void explorer_init(void);

void explorer_update(void);

void explorer_render(SDL_Renderer *renderer);

void explorer_event(SDL_Event *event);

void explorer_shutdown(void);

#endif