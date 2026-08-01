#include "explorer.h"

#include "../../graphics/graphics.h"

static int explorer_visible = 1;

void explorer_init(void)
{
    explorer_visible = 1;
}

void explorer_update(void)
{
}

void explorer_render(SDL_Renderer *renderer)
{
    if(!explorer_visible)
        return;

    SDL_Rect body =
    {
        120,
        70,
        950,
        600
    };

    SDL_SetRenderDrawColor(renderer,40,40,45,255);
    SDL_RenderFillRect(renderer,&body);

    SDL_SetRenderDrawColor(renderer,0,170,255,255);
    SDL_RenderDrawRect(renderer,&body);

    SDL_Rect toolbar =
    {
        120,
        70,
        950,
        35
    };

    SDL_SetRenderDrawColor(renderer,60,80,130,255);
    SDL_RenderFillRect(renderer,&toolbar);

    SDL_Rect sidebar =
    {
        120,
        105,
        220,
        565
    };

    SDL_SetRenderDrawColor(renderer,55,55,65,255);
    SDL_RenderFillRect(renderer,&sidebar);

    SDL_Rect files =
    {
        340,
        105,
        730,
        565
    };

    SDL_SetRenderDrawColor(renderer,35,35,40,255);
    SDL_RenderFillRect(renderer,&files);
}

void explorer_event(SDL_Event *event)
{
    (void)event;
}

void explorer_shutdown(void)
{
    explorer_visible = 0;
}