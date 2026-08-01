#ifndef COLOR_H
#define COLOR_H

#include <SDL2/SDL.h>

typedef struct
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;

} Color;

extern Color COLOR_BACKGROUND;
extern Color COLOR_PANEL;
extern Color COLOR_BORDER;
extern Color COLOR_BLUE;
extern Color COLOR_GREEN;
extern Color COLOR_ORANGE;
extern Color COLOR_PURPLE;
extern Color COLOR_RED;
extern Color COLOR_WHITE;

#endif