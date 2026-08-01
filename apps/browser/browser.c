#include "browser.h"

static int browser_visible = 1;

void browser_init(void)
{
    browser_visible = 1;
}

void browser_update(void)
{
}

void browser_render(SDL_Renderer *renderer)
{
    if(!browser_visible)
        return;

    SDL_Rect body =
    {
        140,
        80,
        920,
        560
    };

    SDL_SetRenderDrawColor(renderer,235,235,235,255);
    SDL_RenderFillRect(renderer,&body);

    SDL_SetRenderDrawColor(renderer,70,70,70,255);
    SDL_RenderDrawRect(renderer,&body);

    SDL_Rect address =
    {
        150,
        90,
        900,
        35
    };

    SDL_SetRenderDrawColor(renderer,210,210,210,255);
    SDL_RenderFillRect(renderer,&address);
}

void browser_event(SDL_Event *event)
{
    (void)event;
}

void browser_shutdown(void)
{
    browser_visible = 0;
}