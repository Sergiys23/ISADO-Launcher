#include "icon_manager.h"

#include <stdio.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define ICON_SIZE 64
#define DOUBLE_CLICK_TIME 350

static DesktopIcon icons[MAX_ICONS];

static int iconCount = 0;

static SDL_Renderer *renderer = NULL;

static TTF_Font *font = NULL;

static Uint32 lastClickTime = 0;

static int lastClicked = -1;
/*=========================================================
    Draw Text
=========================================================*/

static void draw_text(
    const char *text,
    int x,
    int y
)
{
    if(font == NULL)
        return;

    SDL_Color color =
    {
        255,
        255,
        255,
        255
    };

    SDL_Surface *surface =
        TTF_RenderUTF8_Blended(
            font,
            text,
            color
        );

    if(surface == NULL)
        return;

    SDL_Texture *texture =
        SDL_CreateTextureFromSurface(
            renderer,
            surface
        );

    if(texture == NULL)
    {
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect rect =
    {
        x,
        y,
        surface->w,
        surface->h
    };

    SDL_RenderCopy(
        renderer,
        texture,
        NULL,
        &rect
    );

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

/*=========================================================
    Init
=========================================================*/

void icon_manager_init(SDL_Renderer *r)
{
    renderer = r;

    iconCount = 0;

    if(TTF_Init() == -1)
    {
        printf(
            "[IconManager] %s\n",
            TTF_GetError()
        );
    }

    font = TTF_OpenFont(
        "assets/fonts/Roboto-Regular.ttf",
        16
    );

    if(font == NULL)
    {
        printf(
            "[IconManager] %s\n",
            TTF_GetError()
        );
    }
}

/*=========================================================
    Add Icon
=========================================================*/

void icon_manager_add(
    const char *title,
    const char *image,
    int x,
    int y,
    void (*open)(void)
)
{
    if(iconCount >= MAX_ICONS)
        return;

    DesktopIcon *icon =
        &icons[iconCount];

    memset(
        icon,
        0,
        sizeof(DesktopIcon)
    );

    strncpy(
        icon->title,
        title,
        sizeof(icon->title)-1
    );

    strncpy(
        icon->image,
        image,
        sizeof(icon->image)-1
    );

    icon->texture =
        IMG_LoadTexture(
            renderer,
            image
        );

    if(icon->texture == NULL)
    {
        printf(
            "[IconManager] Cannot load %s\n",
            image
        );

        printf(
            "%s\n",
            IMG_GetError()
        );
    }

    icon->rect.x = x;
    icon->rect.y = y;
    icon->rect.w = ICON_SIZE;
    icon->rect.h = ICON_SIZE;

    icon->visible = true;
    icon->selected = false;
    icon->dragging = false;

    icon->offsetX = 0;
    icon->offsetY = 0;

    icon->open = open;

    iconCount++;
}
/*=========================================================
    Render Icons
=========================================================*/

void icon_manager_render(SDL_Renderer *r)
{
    SDL_Rect border;

    for(int i = 0; i < iconCount; i++)
    {
        DesktopIcon *icon = &icons[i];

        if(!icon->visible)
            continue;

        if(icon->texture != NULL)
        {
            SDL_RenderCopy(
                r,
                icon->texture,
                NULL,
                &icon->rect
            );
        }

        if(icon->selected)
        {
            border.x = icon->rect.x - 3;
            border.y = icon->rect.y - 3;
            border.w = icon->rect.w + 6;
            border.h = icon->rect.h + 6;

            SDL_SetRenderDrawColor(
                r,
                60,
                140,
                255,
                255
            );

            SDL_RenderDrawRect(
                r,
                &border
            );
        }

        draw_text(
            icon->title,
            icon->rect.x,
            icon->rect.y + ICON_SIZE + 8
        );
    }
}
/*=========================================================
    Icon Hit Test
=========================================================*/

static int icon_at(
    int x,
    int y
)
{
    for(int i = iconCount - 1; i >= 0; i--)
    {
        if(!icons[i].visible)
            continue;

        if(
            x >= icons[i].rect.x &&
            x <= icons[i].rect.x + icons[i].rect.w &&
            y >= icons[i].rect.y &&
            y <= icons[i].rect.y + icons[i].rect.h
        )
        {
            return i;
        }
    }

    return -1;
}
/*=========================================================
    Mouse Events
=========================================================*/

void icon_manager_mouse(SDL_Event *event)
{
    static int draggingIcon = -1;

    int index;

    switch(event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
        {
            if(event->button.button != SDL_BUTTON_LEFT)
                break;

            index = icon_at(
                event->button.x,
                event->button.y
            );

            for(int i = 0; i < iconCount; i++)
            {
                icons[i].selected = false;
            }

            if(index != -1)
            {
                icons[index].selected = true;

                icons[index].dragging = true;

                icons[index].offsetX =
                    event->button.x -
                    icons[index].rect.x;

                icons[index].offsetY =
                    event->button.y -
                    icons[index].rect.y;

                draggingIcon = index;

                Uint32 now = SDL_GetTicks();

                if(
                    lastClicked == index &&
                    now - lastClickTime <
                    DOUBLE_CLICK_TIME
                )
                {
                    if(
                        icons[index].open != NULL
                    )
                    {
                        icons[index].open();
                    }

                    lastClicked = -1;
                }
                else
                {
                    lastClicked = index;
                    lastClickTime = now;
                }
            }

            break;
        }

        case SDL_MOUSEBUTTONUP:
        {
            if(event->button.button != SDL_BUTTON_LEFT)
                break;

            if(draggingIcon != -1)
            {
                icons[draggingIcon].dragging = false;
            }

            draggingIcon = -1;

            break;
        }

        case SDL_MOUSEMOTION:
        {
            if(draggingIcon == -1)
                break;

            icons[draggingIcon].rect.x =
                event->motion.x -
                icons[draggingIcon].offsetX;

            icons[draggingIcon].rect.y =
                event->motion.y -
                icons[draggingIcon].offsetY;

            break;
        }

        default:
            break;
    }
}
/*=========================================================
    Shutdown
=========================================================*/

void icon_manager_shutdown(void)
{
    for(int i = 0; i < iconCount; i++)
    {
        if(icons[i].texture != NULL)
        {
            SDL_DestroyTexture(
                icons[i].texture
            );

            icons[i].texture = NULL;
        }

        icons[i].visible = false;
        icons[i].selected = false;
        icons[i].dragging = false;
    }

    iconCount = 0;

    if(font != NULL)
    {
        TTF_CloseFont(font);
        font = NULL;
    }

    if(TTF_WasInit())
    {
        TTF_Quit();
    }
}

/*=========================================================
    Helpers
=========================================================*/

int icon_manager_count(void)
{
    return iconCount;
}

DesktopIcon *icon_manager_get(
    int index
)
{
    if(index < 0)
        return NULL;

    if(index >= iconCount)
        return NULL;

    return &icons[index];
}

void icon_manager_clear_selection(void)
{
    for(int i = 0; i < iconCount; i++)
    {
        icons[i].selected = false;
    }
}

DesktopIcon *icon_manager_selected(void)
{
    for(int i = 0; i < iconCount; i++)
    {
        if(icons[i].selected)
            return &icons[i];
    }

    return NULL;
}
/*=========================================================
    Auto Arrange
=========================================================*/

void icon_manager_arrange(void)
{
    int x = 40;
    int y = 40;

    const int stepX = 120;
    const int stepY = 110;

    const int maxHeight = 700;

    for(int i = 0; i < iconCount; i++)
    {
        icons[i].rect.x = x;
        icons[i].rect.y = y;

        y += stepY;

        if(y > maxHeight)
        {
            y = 40;
            x += stepX;
        }
    }
}

/*=========================================================
    Select
=========================================================*/

void icon_manager_select(int index)
{
    if(index < 0 || index >= iconCount)
        return;

    for(int i = 0; i < iconCount; i++)
    {
        icons[i].selected = false;
    }

    icons[index].selected = true;
}

/*=========================================================
    Deselect
=========================================================*/

void icon_manager_deselect_all(void)
{
    for(int i = 0; i < iconCount; i++)
    {
        icons[i].selected = false;
    }
}

/*=========================================================
    Move
=========================================================*/

void icon_manager_move(
    int index,
    int x,
    int y
)
{
    if(index < 0 || index >= iconCount)
        return;

    icons[index].rect.x = x;
    icons[index].rect.y = y;
}

/*=========================================================
    Open
=========================================================*/

void icon_manager_open(
    int index
)
{
    if(index < 0 || index >= iconCount)
        return;

    if(icons[index].open != NULL)
    {
        icons[index].open();
    }
}
/*=========================================================
    Hover
=========================================================*/

DesktopIcon *icon_manager_hover(
    int mouseX,
    int mouseY
)
{
    for(int i = iconCount - 1; i >= 0; i--)
    {
        DesktopIcon *icon = &icons[i];

        if(!icon->visible)
            continue;

        if(mouseX >= icon->rect.x &&
           mouseX <= icon->rect.x + icon->rect.w &&
           mouseY >= icon->rect.y &&
           mouseY <= icon->rect.y + icon->rect.h)
        {
            return icon;
        }
    }

    return NULL;
}

/*=========================================================
    Find By Name
=========================================================*/

DesktopIcon *icon_manager_find(
    const char *title
)
{
    for(int i = 0; i < iconCount; i++)
    {
        if(strcmp(
            icons[i].title,
            title
        ) == 0)
        {
            return &icons[i];
        }
    }

    return NULL;
}

/*=========================================================
    Remove
=========================================================*/

void icon_manager_remove(
    int index
)
{
    if(index < 0 || index >= iconCount)
        return;

    if(icons[index].texture != NULL)
    {
        SDL_DestroyTexture(
            icons[index].texture
        );
    }

    for(int i = index; i < iconCount - 1; i++)
    {
        icons[i] = icons[i + 1];
    }

    iconCount--;
}

/*=========================================================
    Update
=========================================================*/

void icon_manager_update(void)
{
    /* Поки що нічого.
       Тут у майбутньому буде:
       - hover animation
       - drag animation
       - snap to grid
       - tooltip
    */
}

/*=========================================================
    End
=========================================================*/