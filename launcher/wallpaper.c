#include "wallpaper.h"

#include "../ui/theme.h"
#include "../ui/draw.h"

void wallpaper_render(SDL_Renderer *renderer)
{
    /* Background */

    SDL_SetRenderDrawColor(
        renderer,
        UI_BACKGROUND.r,
        UI_BACKGROUND.g,
        UI_BACKGROUND.b,
        UI_BACKGROUND.a
    );

    SDL_RenderClear(renderer);

    /* Top panel */

    SDL_Rect top =
    {
        0,
        0,
        1280,
        45
    };

    ui_draw_rect(
        renderer,
        &top,
        UI_TOPBAR
    );

    /* Bottom Dock */

    SDL_Rect dock =
    {
        0,
        680,
        1280,
        40
    };

    ui_draw_rect(
        renderer,
        &dock,
        UI_DOCK
    );

    /* Separator line */

    ui_draw_line(
        renderer,
        0,
        45,
        1280,
        45,
        UI_BORDER
    );

    ui_draw_line(
        renderer,
        0,
        679,
        1280,
        679,
        UI_BORDER
    );
}