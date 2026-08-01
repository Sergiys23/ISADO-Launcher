#include "draw.h"

void draw_rect(
    SDL_Renderer *renderer,
    int x,
    int y,
    int w,
    int h,
    Color color)
{
    SDL_Rect rect =
    {
        x,
        y,
        w,
        h
    };

    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g,
        color.b,
        color.a);

    SDL_RenderFillRect(renderer,&rect);
}

void draw_outline(
    SDL_Renderer *renderer,
    int x,
    int y,
    int w,
    int h,
    Color color)
{
    SDL_Rect rect =
    {
        x,
        y,
        w,
        h
    };

    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g,
        color.b,
        color.a);

    SDL_RenderDrawRect(renderer,&rect);
}