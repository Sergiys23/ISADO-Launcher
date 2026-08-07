#include "icons.h"

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/*=========================================================
    Textures
=========================================================*/

static SDL_Texture *iconBrowser  = NULL;
static SDL_Texture *iconExplorer = NULL;
static SDL_Texture *iconTerminal = NULL;
static SDL_Texture *iconSettings = NULL;
static SDL_Texture *iconAI       = NULL;
static SDL_Texture *iconGallery  = NULL;
static SDL_Texture *iconMusic    = NULL;
static SDL_Texture *iconVideo    = NULL;
static SDL_Texture *iconTrash    = NULL;
static SDL_Texture *iconDisk     = NULL;

static TTF_Font *font = NULL;

/*=========================================================
    Init
=========================================================*/

int icons_init(SDL_Renderer *renderer)
{
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        printf("SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }

    if (TTF_Init() == -1)
    {
        printf("SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }

    font = TTF_OpenFont(
        "assets/fonts/Roboto-Regular.ttf",
        16
    );

    if (font == NULL)
    {
        printf("Font Error: %s\n", TTF_GetError());
    }

    iconBrowser =
        IMG_LoadTexture(renderer,"assets/icons/browser.png");

    iconExplorer =
        IMG_LoadTexture(renderer,"assets/icons/explorer.png");

    iconTerminal =
        IMG_LoadTexture(renderer,"assets/icons/terminal.png");

    iconSettings =
        IMG_LoadTexture(renderer,"assets/icons/settings.png");

    iconAI =
        IMG_LoadTexture(renderer,"assets/icons/ai.png");

    iconGallery =
        IMG_LoadTexture(renderer,"assets/icons/gallery.png");

    iconMusic =
        IMG_LoadTexture(renderer,"assets/icons/music.png");

    iconVideo =
        IMG_LoadTexture(renderer,"assets/icons/video.png");

    iconTrash =
        IMG_LoadTexture(renderer,"assets/icons/trash.png");

    iconDisk =
        IMG_LoadTexture(renderer,"assets/icons/disk.png");

    return 1;
}

/*=========================================================
    Draw text
=========================================================*/

static void drawText(
    SDL_Renderer *renderer,
    const char *text,
    int x,
    int y
)
{
    if (font == NULL)
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

    if (surface == NULL)
        return;

    SDL_Texture *texture =
        SDL_CreateTextureFromSurface(
            renderer,
            surface
        );

    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_RenderCopy(
        renderer,
        texture,
        NULL,
        &rect
    );

    SDL_FreeSurface(surface);

    SDL_DestroyTexture(texture);
}
/*=========================================================
    Draw Icons
=========================================================*/

void icons_render(SDL_Renderer *renderer)
{
    SDL_Rect icon;

    icon.w = 64;
    icon.h = 64;

    /* Browser */
    icon.x = 50;
    icon.y = 50;
    if (iconBrowser)
        SDL_RenderCopy(renderer, iconBrowser, NULL, &icon);
    drawText(renderer, "Browser", icon.x, icon.y + 70);

    /* Explorer */
    icon.y += 110;
    if (iconExplorer)
        SDL_RenderCopy(renderer, iconExplorer, NULL, &icon);
    drawText(renderer, "Explorer", icon.x, icon.y + 70);

    /* Terminal */
    icon.y += 110;
    if (iconTerminal)
        SDL_RenderCopy(renderer, iconTerminal, NULL, &icon);
    drawText(renderer, "Terminal", icon.x, icon.y + 70);

    /* Settings */
    icon.y += 110;
    if (iconSettings)
        SDL_RenderCopy(renderer, iconSettings, NULL, &icon);
    drawText(renderer, "Settings", icon.x, icon.y + 70);

    /* AI */
    icon.x = 180;
    icon.y = 50;
    if (iconAI)
        SDL_RenderCopy(renderer, iconAI, NULL, &icon);
    drawText(renderer, "AI", icon.x + 18, icon.y + 70);

    /* Gallery */
    icon.y += 110;
    if (iconGallery)
        SDL_RenderCopy(renderer, iconGallery, NULL, &icon);
    drawText(renderer, "Gallery", icon.x, icon.y + 70);

    /* Music */
    icon.y += 110;
    if (iconMusic)
        SDL_RenderCopy(renderer, iconMusic, NULL, &icon);
    drawText(renderer, "Music", icon.x + 8, icon.y + 70);

    /* Video */
    icon.y += 110;
    if (iconVideo)
        SDL_RenderCopy(renderer, iconVideo, NULL, &icon);
    drawText(renderer, "Video", icon.x + 10, icon.y + 70);

    /* Trash */
    icon.x = 310;
    icon.y = 50;
    if (iconTrash)
        SDL_RenderCopy(renderer, iconTrash, NULL, &icon);
    drawText(renderer, "Trash", icon.x + 8, icon.y + 70);

    /* Disk */
    icon.y += 110;
    if (iconDisk)
        SDL_RenderCopy(renderer, iconDisk, NULL, &icon);
    drawText(renderer, "Disk", icon.x + 12, icon.y + 70);
}

/*=========================================================
    Shutdown
=========================================================*/

void icons_shutdown(void)
{
    SDL_DestroyTexture(iconBrowser);
    SDL_DestroyTexture(iconExplorer);
    SDL_DestroyTexture(iconTerminal);
    SDL_DestroyTexture(iconSettings);
    SDL_DestroyTexture(iconAI);
    SDL_DestroyTexture(iconGallery);
    SDL_DestroyTexture(iconMusic);
    SDL_DestroyTexture(iconVideo);
    SDL_DestroyTexture(iconTrash);
    SDL_DestroyTexture(iconDisk);

    iconBrowser  = NULL;
    iconExplorer = NULL;
    iconTerminal = NULL;
    iconSettings = NULL;
    iconAI       = NULL;
    iconGallery  = NULL;
    iconMusic    = NULL;
    iconVideo    = NULL;
    iconTrash    = NULL;
    iconDisk     = NULL;

    if (font != NULL)
    {
        TTF_CloseFont(font);
        font = NULL;
    }

    TTF_Quit();
    IMG_Quit();
}