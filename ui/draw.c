#include "draw.h"

void ui_draw_rect(
    SDL_Renderer *renderer,
    SDL_Rect *rect,
    SDL_Color color
)
{
    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g,
        color.b,
        color.a
    );

    SDL_RenderFillRect(
        renderer,
        rect
    );
}

void ui_draw_border(
    SDL_Renderer *renderer,
    SDL_Rect *rect,
    SDL_Color color
)
{
    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g,
        color.b,
        color.a
    );

    SDL_RenderDrawRect(
        renderer,
        rect
    );
}

void ui_draw_line(
    SDL_Renderer *renderer,
    int x1,
    int y1,
    int x2,
    int y2,
    SDL_Color color
)
{
    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g,
        color.b,
        color.a
    );

    SDL_RenderDrawLine(
        renderer,
        x1,
        y1,
        x2,
        y2
    );
}

void ui_draw_circle(
    SDL_Renderer *renderer,
    int cx,
    int cy,
    int radius,
    SDL_Color color
)
{
    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g,
        color.b,
        color.a
    );

    for(int y = -radius; y <= radius; y++)
    {
        for(int x = -radius; x <= radius; x++)
        {
            if(x*x + y*y <= radius*radius)
            {
                SDL_RenderDrawPoint(
                    renderer,
                    cx + x,
                    cy + y
                );
            }
        }
    }
}

void ui_draw_shadow(
    SDL_Renderer *renderer,
    SDL_Rect *rect
)
{
    SDL_Rect shadow =
    {
        rect->x + 5,
        rect->y + 5,
        rect->w,
        rect->h
    };

    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        80
    );

    SDL_RenderFillRect(
        renderer,
        &shadow
    );
}