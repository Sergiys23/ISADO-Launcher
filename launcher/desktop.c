#include "desktop.h"

#include "wallpaper.h"
#include "icons.h"
#include "dock.h"

void desktop_init(void)
{
}

void desktop_render(SDL_Renderer *renderer)
{
    wallpaper_render(renderer);

    icons_render(renderer);

    dock_render(renderer);
}

void desktop_shutdown(void)
{
}