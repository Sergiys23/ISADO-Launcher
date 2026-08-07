#include "gui.h"
#include "mouse.h"
#include "keyboard.h"

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "../launcher/desktop.h"
#include "../launcher/desktop_manager.h"
#include "../launcher/wallpaper.h"
#include "../launcher/icon_manager.h"

#include "../wm/window.h"
#include "../wm/window_manager.h"

#define WINDOW_WIDTH   1280
#define WINDOW_HEIGHT   720
#define FRAME_DELAY       16

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static bool running = true;

/*=========================================================
    Створення стандартних вікон
=========================================================*/

static void gui_create_default_windows(void)
{
    static Window terminal;

    window_create(
        &terminal,
        "Terminal",
        250,
        120,
        700,
        450
    );

    window_manager_add(&terminal);
}

/*=========================================================
    Обробка подій
=========================================================*/

static void gui_handle_events_internal(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                running = false;
                break;

            default:
                break;
        }

       mouse_handle_event(&event);

       keyboard_handle_event(&event);

       icon_manager_mouse(&event);

       window_manager_mouse(&event);

 // desktop_manager_mouse(&event);
    }
}

/*=========================================================
    Малювання кадру
=========================================================*/

void gui_render(void)
{
    SDL_SetRenderDrawColor(
        renderer,
        20,
        25,
        35,
        255
    );

    SDL_RenderClear(renderer);

    /* Космічний фон */
    wallpaper_render(renderer);

    /* Робочий стіл */
    desktop_render(renderer);

    /* Вікна */
    window_manager_draw(renderer);

    SDL_RenderPresent(renderer);
}

/*=========================================================
    Ініціалізація GUI
=========================================================*/

bool gui_init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
        "ISADO OS",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN |
        SDL_WINDOW_RESIZABLE
    );

    if (window == NULL)
    {
        printf("Window Error: %s\n", SDL_GetError());

        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == NULL)
    {
        printf("Renderer Error: %s\n", SDL_GetError());

        SDL_DestroyWindow(window);
        SDL_Quit();

        return false;
    }

    /* Завантаження шпалер */

    if (!wallpaper_init(renderer))
    {
        printf("Wallpaper was not loaded.\n");
    }

    /* Ініціалізація Desktop */

   desktop_init(renderer);

    /* Менеджер вікон */

    window_manager_init();

    /* Створюємо стандартні вікна */

    gui_create_default_windows();

    running = true;

    while (running)
    {
        gui_handle_events_internal();

        gui_render();

        SDL_Delay(FRAME_DELAY);
    }

    gui_shutdown();

    return true;
}

/*=========================================================
    Завершення роботи GUI
=========================================================*/

void gui_shutdown(void)
{
    wallpaper_destroy();

    desktop_shutdown();

    if (renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window != NULL)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }

    SDL_Quit();
}