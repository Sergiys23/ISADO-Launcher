#include "settings.h"

static int settings_visible = 1;

void settings_init(void)
{
    settings_visible = 1;
}

void settings_update(void)
{
}

void settings_render(SDL_Renderer *renderer)
{
    if(!settings_visible)
        return;

    SDL_Rect body =
    {
        200,
        100,
        800,
        520
    };

    SDL_SetRenderDrawColor(renderer,45,45,55,255);
    SDL_RenderFillRect(renderer,&body);

    SDL_SetRenderDrawColor(renderer,0,170,255,255);
    SDL_RenderDrawRect(renderer,&body);

    SDL_Rect menu =
    {
        200,
        100,
        220,
        520
    };

    SDL_SetRenderDrawColor(renderer,60,70,90,255);
    SDL_RenderFillRect(renderer,&menu);
}

void settings_event(SDL_Event *event)
{
    (void)event;
}

void settings_shutdown(void)
{
    settings_visible = 0;
}