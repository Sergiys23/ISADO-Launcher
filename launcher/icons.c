#include "icons.h"

#include "../ui/theme.h"
#include "../ui/draw.h"

void icons_render(SDL_Renderer *renderer)
{
    SDL_Rect icon;

    /* ========================= */
    /* Explorer                  */
    /* ========================= */

    icon.x = 40;
    icon.y = 80;
    icon.w = 72;
    icon.h = 72;

    ui_draw_shadow(renderer, &icon);

    ui_draw_rect(
        renderer,
        &icon,
        UI_BORDER
    );

    ui_draw_border(
        renderer,
        &icon,
        UI_TEXT
    );

    /* ========================= */
    /* Terminal                  */
    /* ========================= */

    icon.y = 180;

    ui_draw_shadow(renderer, &icon);

    ui_draw_rect(
        renderer,
        &icon,
        UI_MAXIMIZE
    );

    ui_draw_border(
        renderer,
        &icon,
        UI_TEXT
    );

    /* ========================= */
    /* Settings                  */
    /* ========================= */

    icon.y = 280;

    ui_draw_shadow(renderer, &icon);

    ui_draw_rect(
        renderer,
        &icon,
        UI_MINIMIZE
    );

    ui_draw_border(
        renderer,
        &icon,
        UI_TEXT
    );

    /* ========================= */
    /* Browser                   */
    /* ========================= */

    icon.y = 380;

    ui_draw_shadow(renderer, &icon);

    ui_draw_rect(
        renderer,
        &icon,
        UI_CLOSE
    );

    ui_draw_border(
        renderer,
        &icon,
        UI_TEXT
    );
}