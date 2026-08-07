#include "desktop_manager.h"

#include <string.h>
#include <stdio.h>

#define ICON_SIZE      70
#define ICON_SPACING   110
#define ICON_X         40
#define ICON_Y         80

static DesktopManagerIcon icons[MAX_DESKTOP_ICONS];

static int iconCount = 0;

void desktop_add_icon(
    const char *title,
    SDL_Color color,
    void (*open)(void)
)
{
    if(iconCount >= MAX_DESKTOP_ICONS)
        return;

    DesktopManagerIcon *icon = &icons[iconCount];

    memset(icon,0,sizeof(DesktopManagerIcon));

    strncpy(
        icon->title,
        title,
        sizeof(icon->title)-1
    );

    icon->rect.x = ICON_X;
    icon->rect.y = ICON_Y + iconCount * ICON_SPACING;

    icon->rect.w = ICON_SIZE;
    icon->rect.h = ICON_SIZE;

    icon->color = color;

    icon->open = open;

    iconCount++;
}

void desktop_manager_init(void)
{
    desktop_add_icon(
        "Explorer",
        (SDL_Color){40,170,255,255},
        NULL
    );

    desktop_add_icon(
        "Terminal",
        (SDL_Color){30,220,120,255},
        NULL
    );

    desktop_add_icon(
        "Settings",
        (SDL_Color){255,190,0,255},
        NULL
    );

    desktop_add_icon(
        "Browser",
        (SDL_Color){255,70,70,255},
        NULL
    );
}

void desktop_manager_render(SDL_Renderer *renderer)
{
    for(int i=0;i<iconCount;i++)
    {
        SDL_SetRenderDrawColor(
            renderer,
            icons[i].color.r,
            icons[i].color.g,
            icons[i].color.b,
            255
        );

        SDL_RenderFillRect(
            renderer,
            &icons[i].rect
        );

        if(icons[i].selected)
        {
            SDL_SetRenderDrawColor(
                renderer,
                255,
                255,
                255,
                255
            );

            SDL_RenderDrawRect(
                renderer,
                &icons[i].rect
            );
        }
    }
}

void desktop_manager_mouse(SDL_Event *event)
{
    if(event->type != SDL_MOUSEBUTTONDOWN)
        return;

    int mx = event->button.x;
    int my = event->button.y;

    for(int i=0;i<iconCount;i++)
    {
        icons[i].selected = 0;

        if(
            mx >= icons[i].rect.x &&
            mx <= icons[i].rect.x + icons[i].rect.w &&
            my >= icons[i].rect.y &&
            my <= icons[i].rect.y + icons[i].rect.h
        )
        {
            icons[i].selected = 1;

            printf(
                "[Desktop] %s selected\n",
                icons[i].title
            );

            if(icons[i].open != NULL)
                icons[i].open();
        }
    }
}

void desktop_manager_shutdown(void)
{
    iconCount = 0;
}