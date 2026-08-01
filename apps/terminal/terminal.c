#include "terminal.h"

#include "../../graphics/graphics.h"

static int terminal_visible = 1;

void terminal_init(void)
{
    terminal_visible = 1;
}

void terminal_update(void)
{
}

void terminal_render(SDL_Renderer *renderer)
{
    if(!terminal_visible)
        return;

    SDL_Rect window =
    {
        180,
        120,
        900,
        500
    };

    SDL_SetRenderDrawColor(renderer,25,25,30,255);
    SDL_RenderFillRect(renderer,&window);

    SDL_SetRenderDrawColor(renderer,0,170,255,255);
    SDL_RenderDrawRect(renderer,&window);

    SDL_Rect title =
    {
        180,
        120,
        900,
        30
    };

    SDL_SetRenderDrawColor(renderer,40,80,180,255);
    SDL_RenderFillRect(renderer,&title);
}

void terminal_event(SDL_Event *event)
{
    (void)event;
}

void terminal_shutdown(void)
{
    terminal_visible = 0;
}