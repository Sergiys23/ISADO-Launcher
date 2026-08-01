#include "keyboard.h"

#include <stdio.h>

void keyboard_handle_event(SDL_Event *event)
{
    if (event->type != SDL_KEYDOWN)
        return;

    printf(
        "Key: %d\n",
        event->key.keysym.sym);
}