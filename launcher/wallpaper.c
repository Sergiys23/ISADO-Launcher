#include "wallpaper.h"

#include <SDL2/SDL_image.h>
#include <stdio.h>

static SDL_Texture *wallpaper = NULL;

int wallpaper_init(SDL_Renderer *renderer)
{
    SDL_Surface *surface =
        IMG_Load("assets/wallpapers/desktop.png");

    if(surface == NULL)
    {
        printf("Wallpaper error: %s\n", IMG_GetError());
        return 0;
    }

    wallpaper = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    if(wallpaper == NULL)
    {
        printf("Texture error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void wallpaper_render(SDL_Renderer *renderer)
{
    if(wallpaper == NULL)
        return;

    SDL_RenderCopy(renderer, wallpaper, NULL, NULL);
}

void wallpaper_destroy(void)
{
    if(wallpaper != NULL)
    {
        SDL_DestroyTexture(wallpaper);
        wallpaper = NULL;
    }
}