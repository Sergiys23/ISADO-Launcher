#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct Window
{
    char title[64];

    /* Position */

    int x;
    int y;

    /* Size */

    int width;
    int height;

    /* Visibility */

    int visible;

    /* Focus */

    int focused;

    /* Window state */

    int minimized;

    int maximized;

    /* Drag */

    int dragging;

    int dragOffsetX;

    int dragOffsetY;

    /* Resize */

    int resizing;

    int resizeEdge;

    /* Draw callback */

    void (*draw)(
        struct Window *window,
        SDL_Renderer *renderer
    );

    /* Update callback */

    void (*update)(
        struct Window *window
    );

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
    int mouseX,
    int mouseY
);

int window_close_clicked(
    Window *window,
    int mouseX,
    int mouseY
);

#endif