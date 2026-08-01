#include "mouse.h"

#include <stdio.h>

void mouse_handle_event(SDL_Event *event)
{
    if (event->type != SDL_MOUSEBUTTONDOWN)
        return;

    printf(
        "Mouse click: %d %d\n",
        event->button.x,
        event->button.y);
}