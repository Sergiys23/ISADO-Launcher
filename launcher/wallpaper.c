#include "wallpaper.h"

void wallpaper_render(SDL_Renderer *renderer)
{
    /* Темно-синій фон */

    SDL_SetRenderDrawColor(renderer, 18, 24, 38, 255);
    SDL_RenderClear(renderer);

    /* Верхня смуга */

    SDL_Rect top =
    {
        0,
        0,
        1280,
        45
    };

    SDL_SetRenderDrawColor(renderer, 25, 35, 55, 255);
    SDL_RenderFillRect(renderer, &top);

    /* Нижня смуга */

    SDL_Rect bottom =
    {
        0,
        680,
        1280,
        40
    };

    SDL_SetRenderDrawColor(renderer, 25, 35, 55, 255);
    SDL_RenderFillRect(renderer, &bottom);
}