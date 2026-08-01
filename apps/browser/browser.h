#ifndef BROWSER_H
#define BROWSER_H

#include <SDL2/SDL.h>

void browser_init(void);

void browser_update(void);

void browser_render(SDL_Renderer *renderer);

void browser_event(SDL_Event *event);

void browser_shutdown(void);

#endif