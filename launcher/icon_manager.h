#ifndef ICON_MANAGER_H
#define ICON_MANAGER_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#define MAX_ICONS 64

typedef struct
{
    char title[32];
    char image[128];

    SDL_Texture *texture;

    SDL_Rect rect;

    bool visible;
    bool selected;
    bool dragging;

    int offsetX;
    int offsetY;

    void (*open)(void);

} DesktopIcon;

void icon_manager_init(SDL_Renderer *renderer);

void icon_manager_render(SDL_Renderer *renderer);

void icon_manager_mouse(SDL_Event *event);

void icon_manager_shutdown(void);

void icon_manager_add(
    const char *title,
    const char *image,
    int x,
    int y,
    void (*open)(void)
);

#endif