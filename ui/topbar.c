#include "topbar.h"

#include "theme.h"
#include "draw.h"

void ui_topbar_render(SDL_Renderer *renderer)
{
    SDL_Rect top =
    {
        0,
        0,
        1280,
        42
    };

    ui_draw_rect(
        renderer,
        &top,
        UI_TOPBAR
    );

    SDL_Rect line =
    {
        0,
        41,
        1280,
        1
    };

    ui_draw_rect(
        renderer,
        &line,
        UI_BORDER
    );
}