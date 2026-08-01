#include "window_manager.h"

static Window *windows[MAX_WINDOWS];

static int count = 0;

void window_manager_init(void)
{
    count = 0;
}

void window_manager_add(Window *window)
{
    if(count >= MAX_WINDOWS)
        return;

    windows[count++] = window;
}

void window_manager_draw(SDL_Renderer *renderer)
{
    for(int i = 0; i < count; i++)
    {
        window_draw(renderer, windows[i]);
    }
}

void window_manager_mouse(SDL_Event *event)
{
    int x;
    int y;

    if(event->type == SDL_MOUSEBUTTONDOWN)
    {
        x = event->button.x;
        y = event->button.y;

        for(int i = count - 1; i >= 0; i--)
        {
            if(window_close_clicked(windows[i], x, y))
            {
                windows[i]->visible = 0;
                return;
            }

            if(window_title_clicked(windows[i], x, y))
            {
                windows[i]->dragging = 1;

                windows[i]->drag_x = x - windows[i]->x;
                windows[i]->drag_y = y - windows[i]->y;

                return;
            }
        }
    }

    if(event->type == SDL_MOUSEBUTTONUP)
    {
        for(int i = 0; i < count; i++)
        {
            windows[i]->dragging = 0;
        }
    }

    if(event->type == SDL_MOUSEMOTION)
    {
        x = event->motion.x;
        y = event->motion.y;

        for(int i = 0; i < count; i++)
        {
            if(windows[i]->dragging)
            {
                windows[i]->x = x - windows[i]->drag_x;
                windows[i]->y = y - windows[i]->drag_y;
            }
        }
    }
}