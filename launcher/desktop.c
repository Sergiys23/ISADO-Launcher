#include "desktop.h"

#include "wallpaper.h"
#include "dock.h"

#include "icon_manager.h"

void desktop_init(SDL_Renderer *renderer)
{
    icon_manager_init(renderer);

    icon_manager_add(
        "Browser",
        "assets/icons/browser.png",
        50,
        50,
        NULL
    );

    icon_manager_add(
        "Explorer",
        "assets/icons/explorer.png",
        50,
        160,
        NULL
    );

    icon_manager_add(
        "Terminal",
        "assets/icons/terminal.png",
        50,
        270,
        NULL
    );

    icon_manager_add(
        "Settings",
        "assets/icons/settings.png",
        50,
        380,
        NULL
    );

    icon_manager_add(
        "AI",
        "assets/icons/ai.png",
        180,
        50,
        NULL
    );

    icon_manager_add(
        "Gallery",
        "assets/icons/gallery.png",
        180,
        160,
        NULL
    );

    icon_manager_add(
        "Music",
        "assets/icons/music.png",
        180,
        270,
        NULL
    );

    icon_manager_add(
        "Video",
        "assets/icons/video.png",
        180,
        380,
        NULL
    );

    icon_manager_add(
        "Trash",
        "assets/icons/trash.png",
        310,
        50,
        NULL
    );

    icon_manager_add(
        "Disk",
        "assets/icons/disk.png",
        310,
        160,
        NULL
    );
}

void desktop_render(SDL_Renderer *renderer)
{
    wallpaper_render(renderer);

    icon_manager_render(renderer);

    dock_render(renderer);
}

void desktop_shutdown(void)
{
    icon_manager_shutdown();
}