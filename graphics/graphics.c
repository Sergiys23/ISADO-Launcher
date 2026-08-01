#include "graphics.h"

#include <math.h>

SDL_Renderer *gfx_renderer = NULL;


int gfx_init(SDL_Renderer *renderer)
{
    gfx_renderer = renderer;

    return renderer != NULL;
}


void gfx_shutdown(void)
{
    gfx_renderer = NULL;
}


Color color_rgb(
    Uint8 r,
    Uint8 g,
    Uint8 b)
{
    Color c;

    c.r = r;
    c.g = g;
    c.b = b;
    c.a = 255;

    return c;
}


Color color_rgba(
    Uint8 r,
    Uint8 g,
    Uint8 b,
    Uint8 a)
{
    Color c;

    c.r = r;
    c.g = g;
    c.b = b;
    c.a = a;

    return c;
}


void gfx_set_color(Color color)
{
    SDL_SetRenderDrawColor(
        gfx_renderer,
        color.r,
        color.g,
        color.b,
        color.a);
}


void gfx_clear(Color color)
{
    gfx_set_color(color);

    SDL_RenderClear(gfx_renderer);
}


void gfx_present(void)
{
    SDL_RenderPresent(gfx_renderer);
}


void gfx_fill_rect(
    int x,
    int y,
    int width,
    int height)
{
    SDL_Rect rect =
    {
        x,
        y,
        width,
        height
    };

    SDL_RenderFillRect(
        gfx_renderer,
        &rect);
}


void gfx_draw_rect(
    int x,
    int y,
    int width,
    int height)
{
    SDL_Rect rect =
    {
        x,
        y,
        width,
        height
    };

    SDL_RenderDrawRect(
        gfx_renderer,
        &rect);
}


void gfx_draw_line(
    int x1,
    int y1,
    int x2,
    int y2)
{
    SDL_RenderDrawLine(
        gfx_renderer,
        x1,
        y1,
        x2,
        y2);
}


void gfx_fill_circle(
    int cx,
    int cy,
    int radius)
{
    for(int y=-radius;y<=radius;y++)
    {
        for(int x=-radius;x<=radius;x++)
        {
            if(x*x+y*y<=radius*radius)
            {
                SDL_RenderDrawPoint(
                    gfx_renderer,
                    cx+x,
                    cy+y);
            }
        }
    }
}