#ifndef ICONS_H
#define ICONS_H

#include <SDL2/SDL.h>

int icons_init(SDL_Renderer *renderer);

void icons_render(SDL_Renderer *renderer);

void icons_shutdown(void);

#endif