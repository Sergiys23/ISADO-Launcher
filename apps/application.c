#include "application.h"

void application_start(Application *app)
{
    if(app==NULL)
        return;

    if(app->initialized)
        return;

    app->running=1;

    app->initialized=1;

    if(app->init!=NULL)
        app->init(app);
}

void application_update(Application *app)
{
    if(app==NULL)
        return;

    if(!app->running)
        return;

    if(app->update!=NULL)
        app->update(app);
}

void application_render(
    Application *app,
    SDL_Renderer *renderer)
{
    if(app==NULL)
        return;

    if(!app->running)
        return;

    if(app->render!=NULL)
        app->render(
            app,
            renderer);
}

void application_event(
    Application *app,
    SDL_Event *event)
{
    if(app==NULL)
        return;

    if(!app->running)
        return;

    if(app->event!=NULL)
        app->event(
            app,
            event);
}

void application_stop(Application *app)
{
    if(app==NULL)
        return;

    if(!app->running)
        return;

    if(app->shutdown!=NULL)
        app->shutdown(app);

    app->running=0;
}