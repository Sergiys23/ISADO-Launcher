#include "app_manager.h"

#include <string.h>

static ISADO_App *apps[MAX_APPS];

static int app_count = 0;

void app_manager_init(void)
{
    app_count = 0;
}

int app_manager_register(ISADO_App *app)
{
    if(app_count >= MAX_APPS)
        return 0;

    apps[app_count++] = app;

    return 1;
}

void app_manager_start(const char *name)
{
    for(int i=0;i<app_count;i++)
    {
        if(strcmp(apps[i]->name,name)==0)
        {
            apps[i]->running=1;

            if(apps[i]->init)
                apps[i]->init();
        }
    }
}

void app_manager_stop(const char *name)
{
    for(int i=0;i<app_count;i++)
    {
        if(strcmp(apps[i]->name,name)==0)
        {
            if(apps[i]->shutdown)
                apps[i]->shutdown();

            apps[i]->running=0;
        }
    }
}

void app_manager_update(void)
{
    for(int i=0;i<app_count;i++)
    {
        if(apps[i]->running)
        {
            if(apps[i]->update)
                apps[i]->update();
        }
    }
}

void app_manager_render(SDL_Renderer *renderer)
{
    for(int i=0;i<app_count;i++)
    {
        if(apps[i]->running)
        {
            if(apps[i]->render)
                apps[i]->render(renderer);
        }
    }
}

void app_manager_event(SDL_Event *event)
{
    for(int i=0;i<app_count;i++)
    {
        if(apps[i]->running)
        {
            if(apps[i]->event)
                apps[i]->event(event);
        }
    }
}