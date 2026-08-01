#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>

#include "color.h"

void draw_rect(
    SDL_Renderer *renderer,
    int x,
    int y,
    int w,
    int h,
    Color color);

void draw_outline(
    SDL_Renderer *renderer,
    int x,
    int y,
    int w,
    int h,
    Color color);

#endif