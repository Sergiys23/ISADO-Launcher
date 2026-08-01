#ifndef UI_THEME_H
#define UI_THEME_H

#include <SDL2/SDL.h>

/* Desktop */

extern SDL_Color UI_BACKGROUND;

extern SDL_Color UI_TOPBAR;

extern SDL_Color UI_DOCK;

/* Windows */

extern SDL_Color UI_WINDOW;

extern SDL_Color UI_TITLEBAR;

extern SDL_Color UI_BORDER;

/* Text */

extern SDL_Color UI_TEXT;

/* Buttons */

extern SDL_Color UI_CLOSE;

extern SDL_Color UI_MINIMIZE;

extern SDL_Color UI_MAXIMIZE;

/* Functions */

void ui_theme_init(void);

#endif