#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct
{
    char title[64];

    int x;
    int y;

    int width;
    int height;

    int visible;

    int dragging;

    int drag_x;
    int drag_y;

} Window;

void window_create(
    Window *window,
    const char *title,
    int x,
    int y,
    int width,
    int height
);

void window_draw(
    SDL_Renderer *renderer,
    Window *window
);

int window_title_clicked(
    Window *window,
    int mouse_x,
    int mouse_y
);

int window_close_clicked(
    Window *window,
    int mouse_x,
    int mouse_y
);

#endif