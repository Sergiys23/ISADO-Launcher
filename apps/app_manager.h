#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include <SDL2/SDL.h>

#define MAX_APPS 32

typedef struct
{
    const char *name;

    int running;

    void (*init)(void);

    void (*update)(void);

    void (*render)(SDL_Renderer *);

    void (*event)(SDL_Event *);

    void (*shutdown)(void);

} ISADO_App;

void app_manager_init(void);

int app_manager_register(ISADO_App *app);

void app_manager_start(const char *name);

void app_manager_stop(const char *name);

void app_manager_update(void);

void app_manager_render(SDL_Renderer *renderer);

void app_manager_event(SDL_Event *event);

#endif