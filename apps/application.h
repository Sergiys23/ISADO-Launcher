#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>

typedef struct Application Application;

struct Application
{
    char name[64];

    int running;

    int initialized;

    void (*init)(Application *);

    void (*update)(Application *);

    void (*render)(Application *, SDL_Renderer *);

    void (*event)(Application *, SDL_Event *);

    void (*shutdown)(Application *);
};

void application_start(Application *app);

void application_update(Application *app);

void application_render(
    Application *app,
    SDL_Renderer *renderer
);

void application_event(
    Application *app,
    SDL_Event *event
);

void application_stop(Application *app);

#endif