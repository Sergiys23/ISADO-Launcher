#include "window.h"

#include <string.h>

void window_create(
    Window *window,
    const char *title,
    int x,
    int y,
    int width,
    int height)
{
    strcpy(window->title, title);

    window->x = x;
    window->y = y;

    window->width = width;
    window->height = height;

    window->visible = 1;

    window->dragging = 0;
    window->drag_x = 0;
    window->drag_y = 0;
}

void window_draw(SDL_Renderer *renderer, Window *window)
{
    if (!window->visible)
        return;

    /* Основне вікно */

    SDL_Rect body =
    {
        window->x,
        window->y,
        window->width,
        window->height
    };

    SDL_SetRenderDrawColor(renderer, 40, 45, 60, 255);
    SDL_RenderFillRect(renderer, &body);

    /* Рамка */

    SDL_SetRenderDrawColor(renderer, 0, 170, 255, 255);
    SDL_RenderDrawRect(renderer, &body);

    /* Заголовок */

    SDL_Rect title =
    {
        window->x,
        window->y,
        window->width,
        30
    };

    SDL_SetRenderDrawColor(renderer, 30, 120, 220, 255);
    SDL_RenderFillRect(renderer, &title);

    /* Кнопка закриття */

    SDL_Rect close =
    {
        window->x + window->width - 28,
        window->y + 6,
        18,
        18
    };

    SDL_SetRenderDrawColor(renderer, 220, 60, 60, 255);
    SDL_RenderFillRect(renderer, &close);
}

int window_title_clicked(Window *window, int mouse_x, int mouse_y)
{
    if (!window->visible)
        return 0;

    return (
        mouse_x >= window->x &&
        mouse_x <= window->x + window->width &&
        mouse_y >= window->y &&
        mouse_y <= window->y + 30
    );
}

int window_close_clicked(Window *window, int mouse_x, int mouse_y)
{
    if (!window->visible)
        return 0;

    return (
        mouse_x >= window->x + window->width - 28 &&
        mouse_x <= window->x + window->width - 10 &&
        mouse_y >= window->y + 6 &&
        mouse_y <= window->y + 24
    );
}