#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <SDL2/SDL.h>

int wallpaper_init(SDL_Renderer *renderer);

void wallpaper_render(SDL_Renderer *renderer);

void wallpaper_destroy(void);

#endif