#include "dock.h"

void dock_render(SDL_Renderer *renderer)
{
    SDL_Rect dock;

    dock.x = 0;
    dock.y = 680;
    dock.w = 1280;
    dock.h = 40;

    SDL_SetRenderDrawColor(renderer, 35, 40, 55, 255);
    SDL_RenderFillRect(renderer, &dock);

    SDL_Rect start;

    start.x = 10;
    start.y = 685;
    start.w = 30;
    start.h = 30;

    SDL_SetRenderDrawColor(renderer, 0, 170, 255, 255);
    SDL_RenderFillRect(renderer, &start);
}