#include "icons.h"

void icons_render(SDL_Renderer *renderer)
{
    SDL_Rect icon;

    /* Explorer */

    icon.x = 40;
    icon.y = 80;
    icon.w = 70;
    icon.h = 70;

    SDL_SetRenderDrawColor(renderer, 40, 170, 255, 255);
    SDL_RenderFillRect(renderer, &icon);

    /* Terminal */

    icon.y = 190;

    SDL_SetRenderDrawColor(renderer, 80, 220, 120, 255);
    SDL_RenderFillRect(renderer, &icon);

    /* Settings */

    icon.y = 300;

    SDL_SetRenderDrawColor(renderer, 255, 180, 0, 255);
    SDL_RenderFillRect(renderer, &icon);

    /* Browser */

    icon.y = 410;

    SDL_SetRenderDrawColor(renderer, 180, 90, 255, 255);
    SDL_RenderFillRect(renderer, &icon);
}