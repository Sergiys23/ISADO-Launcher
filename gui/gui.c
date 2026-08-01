#include "gui.h"
#include "mouse.h"
#include "keyboard.h"

#include <stdio.h>
#include <SDL2/SDL.h>

#include "../launcher/desktop.h"
#include "../wm/window.h"
#include "../wm/window_manager.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int gui_init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow(
        "ISADO OS",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        printf("Window Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == NULL)
    {
        printf("Renderer Error: %s\n", SDL_GetError());

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }

    /* Ініціалізація робочого столу */
    desktop_init();

    /* Ініціалізація менеджера вікон */
    window_manager_init();

    /* Тестове вікно */
    Window terminal;

    window_create(
        &terminal,
        "Terminal",
        250,
        120,
        700,
        450
    );

    window_manager_add(&terminal);

    int running = 1;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }

            mouse_handle_event(&event);
            keyboard_handle_event(&event);
        }

        SDL_SetRenderDrawColor(renderer, 20, 25, 35, 255);
        SDL_RenderClear(renderer);

        desktop_render(renderer);

        window_manager_draw(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    desktop_shutdown();

    return 1;
}

void gui_shutdown(void)
{
    if (renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
    }

    if (window != NULL)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}