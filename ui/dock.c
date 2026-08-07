#include "dock.h"

#include "theme.h"
#include "draw.h"

void ui_dock_render(SDL_Renderer *renderer)
{
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

    SDL_Rect line =
    {
        0,
        679,
        1280,
        1
    };

    ui_draw_rect(
        renderer,
        &line,
        UI_BORDER
    );
}