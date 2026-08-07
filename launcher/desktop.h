#ifndef DESKTOP_H
#define DESKTOP_H

#include <SDL2/SDL.h>

void desktop_init(SDL_Renderer *renderer);

void desktop_render(SDL_Renderer *renderer);

void desktop_shutdown(void);

#endif