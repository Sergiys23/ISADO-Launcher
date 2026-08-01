#ifndef ISADO_H
#define ISADO_H

#include <stdbool.h>
#include <SDL2/SDL.h>

/* Window */

bool IS_Window_Create(
    const char *title,
    int x,
    int y,
    int width,
    int height
);

void IS_Window_Close(void);

/* Graphics */

void IS_Draw_Clear(
    SDL_Renderer *renderer
);

void IS_Draw_Present(
    SDL_Renderer *renderer
);

/* AI */

bool IS_AI_Command(
    const char *command
);

/* Internet */

bool IS_HTTP_GET(
    const char *url
);

/* Phone */

bool IS_Phone_Connect(void);

/* File */

bool IS_File_Open(
    const char *path
);

#endif