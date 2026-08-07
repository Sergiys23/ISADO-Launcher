#ifndef DESKTOP_MANAGER_H
#define DESKTOP_MANAGER_H

#include <SDL2/SDL.h>

#define MAX_DESKTOP_ICONS 64

typedef struct
{
    char title[32];

    SDL_Rect rect;

    SDL_Color color;

    int selected;

    void (*open)(void);

} DesktopManagerIcon;

void desktop_manager_init(void);

void desktop_manager_render(SDL_Renderer *renderer);

void desktop_manager_mouse(SDL_Event *event);

void desktop_manager_shutdown(void);

void desktop_add_icon(
    const char *title,
    SDL_Color color,
    void (*open)(void)
);

#endif