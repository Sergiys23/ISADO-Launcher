#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

typedef struct
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;

} Color;


extern SDL_Renderer *gfx_renderer;


int gfx_init(SDL_Renderer *renderer);

void gfx_shutdown(void);


void gfx_clear(Color color);

void gfx_present(void);


void gfx_set_color(Color color);


void gfx_fill_rect(
    int x,
    int y,
    int width,
    int height
);

void gfx_draw_rect(
    int x,
    int y,
    int width,
    int height
);

void gfx_draw_line(
    int x1,
    int y1,
    int x2,
    int y2
);

void gfx_fill_circle(
    int cx,
    int cy,
    int radius
);

Color color_rgb(
    Uint8 r,
    Uint8 g,
    Uint8 b
);

Color color_rgba(
    Uint8 r,
    Uint8 g,
    Uint8 b,
    Uint8 a
);

#endif