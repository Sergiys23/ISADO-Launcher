#ifndef UI_DRAW_H
#define UI_DRAW_H

#include <SDL2/SDL.h>

void ui_draw_rect(
    SDL_Renderer *renderer,
    SDL_Rect *rect,
    SDL_Color color
);

void ui_draw_border(
    SDL_Renderer *renderer,
    SDL_Rect *rect,
    SDL_Color color
);

void ui_draw_line(
    SDL_Renderer *renderer,
    int x1,
    int y1,
    int x2,
    int y2,
    SDL_Color color
);

void ui_draw_circle(
    SDL_Renderer *renderer,
    int cx,
    int cy,
    int radius,
    SDL_Color color
);

void ui_draw_shadow(
    SDL_Renderer *renderer,
    SDL_Rect *rect
);

#endif