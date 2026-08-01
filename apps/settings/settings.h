#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL2/SDL.h>

void settings_init(void);

void settings_update(void);

void settings_render(SDL_Renderer *renderer);

void settings_event(SDL_Event *event);

void settings_shutdown(void);

#endif