#include "window.h"
#include "window_resize.h"

#include <SDL2/SDL.h>
#include <string.h>
#include <stdio.h>

#define WINDOW_TITLE_HEIGHT 30
#define WINDOW_BORDER_SIZE 2
#define WINDOW_MIN_WIDTH 200
#define WINDOW_MIN_HEIGHT 120

static SDL_Color backgroundColor =
{
    42,
    45,
    60,
    255
};

static SDL_Color borderColor =
{
    0,
    170,
    255,
    255
};

static SDL_Color titleColor =
{
    35,
    120,
    220,
    255
};

static SDL_Color closeColor =
{
    220,
    60,
    60,
    255
};

static SDL_Color focusedBorder =
{
    0,
    220,
    255,
    255
};

void window_create(
    Window *window,
    const char *title,
    int x,
    int y,
    int width,
    int height)
{
    memset(window,0,sizeof(Window));

    strncpy(
        window->title,
        title,
        sizeof(window->title)-1
    );

    window->x=x;
    window->y=y;

    window->width=width;
    window->height=height;

    if(window->width<WINDOW_MIN_WIDTH)
        window->width=WINDOW_MIN_WIDTH;

    if(window->height<WINDOW_MIN_HEIGHT)
        window->height=WINDOW_MIN_HEIGHT;

    window->visible=1;

    window->focused=1;

    window->dragging=0;
    window->dragOffsetX=0;
    window->dragOffsetY=0;

    window->resizing=0;
    window->resizeEdge=0;

    window->minimized=0;
    window->maximized=0;

    window->draw=NULL;
    window->update=NULL;
}

static void draw_body(
    SDL_Renderer *renderer,
    Window *window)
{
    SDL_Rect body=
    {
        window->x,
        window->y,
        window->width,
        window->height
    };

    SDL_SetRenderDrawColor(
        renderer,
        backgroundColor.r,
        backgroundColor.g,
        backgroundColor.b,
        backgroundColor.a
    );

    SDL_RenderFillRect(
        renderer,
        &body
    );
}

static void draw_border(
    SDL_Renderer *renderer,
    Window *window)
{
    SDL_Rect body=
    {
        window->x,
        window->y,
        window->width,
        window->height
    };

    SDL_Color c=
        window->focused
            ? focusedBorder
            : borderColor;

    SDL_SetRenderDrawColor(
        renderer,
        c.r,
        c.g,
        c.b,
        c.a
    );

    SDL_RenderDrawRect(
        renderer,
        &body
    );
}

static void draw_title(
    SDL_Renderer *renderer,
    Window *window)
{
    SDL_Rect title=
    {
        window->x,
        window->y,
        window->width,
        WINDOW_TITLE_HEIGHT
    };

    SDL_SetRenderDrawColor(
        renderer,
        titleColor.r,
        titleColor.g,
        titleColor.b,
        titleColor.a
    );

    SDL_RenderFillRect(
        renderer,
        &title
    );
}

static void draw_close(
    SDL_Renderer *renderer,
    Window *window)
{
    SDL_Rect close=
    {
        window->x+window->width-26,
        window->y+6,
        18,
        18
    };

    SDL_SetRenderDrawColor(
        renderer,
        closeColor.r,
        closeColor.g,
        closeColor.b,
        closeColor.a
    );

    SDL_RenderFillRect(
        renderer,
        &close
    );
}

void window_draw(
    SDL_Renderer *renderer,
    Window *window)
{
    if (window == NULL)
        return;

    if (!window->visible)
        return;

    draw_body(renderer, window);

    draw_title(renderer, window);

    draw_close(renderer, window);

    draw_border(renderer, window);

    if (window->draw)
    {
        window->draw(window, renderer);
    }
}
int window_title_clicked(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return 0;

    if(!window->visible)
        return 0;

    return (
        mouseX>=window->x &&
        mouseX<=window->x+window->width &&
        mouseY>=window->y &&
        mouseY<=window->y+WINDOW_TITLE_HEIGHT
    );
}
int window_close_clicked(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return 0;

    if(!window->visible)
        return 0;

    return (
        mouseX >= window->x + window->width - 26 &&
        mouseX <= window->x + window->width - 8 &&
        mouseY >= window->y + 6 &&
        mouseY <= window->y + 24
    );
}
void window_show(
    Window *window)
{
    if(window==NULL)
        return;

    window->visible=1;
}

void window_hide(
    Window *window)
{
    if(window==NULL)
        return;

    window->visible=0;
}

void window_focus(
    Window *window)
{
    if(window==NULL)
        return;

    window->focused=1;
}

void window_unfocus(
    Window *window)
{
    if(window==NULL)
        return;

    window->focused=0;
}

void window_move(
    Window *window,
    int x,
    int y)
{
    if(window==NULL)
        return;

    window->x=x;
    window->y=y;
}

void window_resize(
    Window *window,
    int width,
    int height)
{
    if(window==NULL)
        return;

    if(width<WINDOW_MIN_WIDTH)
        width=WINDOW_MIN_WIDTH;

    if(height<WINDOW_MIN_HEIGHT)
        height=WINDOW_MIN_HEIGHT;

    window->width=width;
    window->height=height;
}

void window_minimize(
    Window *window)
{
    if(window==NULL)
        return;

    window->minimized=1;
    window->maximized=0;
}

void window_maximize(
    Window *window,
    int screenWidth,
    int screenHeight)
{
    if(window==NULL)
        return;

    window->x=0;
    window->y=0;

    window->width=screenWidth;
    window->height=screenHeight;

    window->maximized=1;
    window->minimized=0;
}

void window_restore(
    Window *window,
    int x,
    int y,
    int width,
    int height)
{
    if(window==NULL)
        return;

    window->x=x;
    window->y=y;

    window->width=width;
    window->height=height;

    window->minimized=0;
    window->maximized=0;
}

int window_contains(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return 0;

    if(!window->visible)
        return 0;

    return (
        mouseX>=window->x &&
        mouseX<=window->x+window->width &&
        mouseY>=window->y &&
        mouseY<=window->y+window->height
    );
}

void window_update(
    Window *window)
{
    if(window==NULL)
        return;

    if(window->update!=NULL)
    {
        window->update(window);
    }
}

void window_set_title(
    Window *window,
    const char *title)
{
    if(window==NULL)
        return;

    if(title==NULL)
        return;

    strncpy(
        window->title,
        title,
        sizeof(window->title)-1
    );

    window->title[
        sizeof(window->title)-1
    ]='\0';
}

const char *window_get_title(
    Window *window)
{
    if(window==NULL)
        return "";

    return window->title;
}

int window_get_width(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->width;
}

int window_get_height(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->height;
}

int window_get_x(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->x;
}

int window_get_y(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->y;
}

int window_is_visible(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->visible;
}

int window_is_focused(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->focused;
}

int window_is_dragging(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->dragging;
}

int window_is_resizing(
    Window *window)
{
    if(window==NULL)
        return 0;

    return window->resizing;
}
/* ========================================================= */
/* CALLBACKS                                                 */
/* ========================================================= */

void window_set_draw_callback(
    Window *window,
    void (*callback)(
        Window *,
        SDL_Renderer *
    ))
{
    if(window==NULL)
        return;

    window->draw=callback;
}

void window_set_update_callback(
    Window *window,
    void (*callback)(
        Window *
    ))
{
    if(window==NULL)
        return;

    window->update=callback;
}

/* ========================================================= */
/* DRAG                                                      */
/* ========================================================= */

void window_drag_begin(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return;

    window->dragging=1;

    window->dragOffsetX=
        mouseX-window->x;

    window->dragOffsetY=
        mouseY-window->y;
}

void window_drag_update(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return;

    if(!window->dragging)
        return;

    window->x=
        mouseX-window->dragOffsetX;

    window->y=
        mouseY-window->dragOffsetY;
}

void window_drag_end(
    Window *window)
{
    if(window==NULL)
        return;

    window->dragging=0;
}

/* ========================================================= */
/* RESIZE                                                    */
/* ========================================================= */

void window_resize_begin(
    Window *window,
    int edge)
{
    if(window==NULL)
        return;

    window->resizing=1;

    window->resizeEdge=edge;
}

void window_resize_update(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return;

    if(!window->resizing)
        return;

    if(window->resizeEdge & RESIZE_RIGHT)
    {
        window->width=
            mouseX-window->x;
    }

    if(window->resizeEdge & RESIZE_BOTTOM)
    {
        window->height=
            mouseY-window->y;
    }

    if(window->resizeEdge & RESIZE_LEFT)
    {
        int newWidth=
            window->width+
            (window->x-mouseX);

        if(newWidth>=WINDOW_MIN_WIDTH)
        {
            window->width=newWidth;
            window->x=mouseX;
        }
    }

    if(window->resizeEdge & RESIZE_TOP)
    {
        int newHeight=
            window->height+
            (window->y-mouseY);

        if(newHeight>=WINDOW_MIN_HEIGHT)
        {
            window->height=newHeight;
            window->y=mouseY;
        }
    }

    if(window->width<WINDOW_MIN_WIDTH)
        window->width=WINDOW_MIN_WIDTH;

    if(window->height<WINDOW_MIN_HEIGHT)
        window->height=WINDOW_MIN_HEIGHT;
}

void window_resize_end(
    Window *window)
{
    if(window==NULL)
        return;

    window->resizing=0;

    window->resizeEdge=
        RESIZE_NONE;
}

/* ========================================================= */
/* HIT TEST                                                  */
/* ========================================================= */

int window_hit_test(
    Window *window,
    int mouseX,
    int mouseY)
{
    if(window==NULL)
        return 0;

    if(!window->visible)
        return 0;

    return
    (
        mouseX>=window->x &&
        mouseX<=window->x+
        window->width &&
        mouseY>=window->y &&
        mouseY<=window->y+
        window->height
    );
}

int window_hit_title(
    Window *window,
    int mouseX,
    int mouseY)
{
    return
    (
        mouseX>=window->x &&
        mouseX<=window->x+
        window->width &&
        mouseY>=window->y &&
        mouseY<=window->y+
        WINDOW_TITLE_HEIGHT
    );
}

int window_hit_close(
    Window *window,
    int mouseX,
    int mouseY)
{
    return
    (
        mouseX>=window->x+
        window->width-26 &&
        mouseX<=window->x+
        window->width-8 &&
        mouseY>=window->y+6 &&
        mouseY<=window->y+24
    );
}
/* ========================================================= */
/* WINDOW STATE                                              */
/* ========================================================= */

void window_set_visible(
    Window *window,
    int visible)
{
    if(window==NULL)
        return;

    window->visible=visible;
}

void window_set_focus(
    Window *window,
    int focused)
{
    if(window==NULL)
        return;

    window->focused=focused;
}

void window_set_position(
    Window *window,
    int x,
    int y)
{
    if(window==NULL)
        return;

    window->x=x;
    window->y=y;
}

void window_set_size(
    Window *window,
    int width,
    int height)
{
    if(window==NULL)
        return;

    if(width<WINDOW_MIN_WIDTH)
        width=WINDOW_MIN_WIDTH;

    if(height<WINDOW_MIN_HEIGHT)
        height=WINDOW_MIN_HEIGHT;

    window->width=width;
    window->height=height;
}

/* ========================================================= */
/* GETTERS                                                   */
/* ========================================================= */

SDL_Rect window_get_rect(
    Window *window)
{
    SDL_Rect rect={0,0,0,0};

    if(window==NULL)
        return rect;

    rect.x=window->x;
    rect.y=window->y;
    rect.w=window->width;
    rect.h=window->height;

    return rect;
}

SDL_Rect window_get_titlebar(
    Window *window)
{
    SDL_Rect rect={0,0,0,0};

    if(window==NULL)
        return rect;

    rect.x=window->x;
    rect.y=window->y;
    rect.w=window->width;
    rect.h=WINDOW_TITLE_HEIGHT;

    return rect;
}

SDL_Rect window_get_close_button(
    Window *window)
{
    SDL_Rect rect={0,0,0,0};

    if(window==NULL)
        return rect;

    rect.x=window->x+window->width-26;
    rect.y=window->y+6;
    rect.w=18;
    rect.h=18;

    return rect;
}

/* ========================================================= */
/* DEBUG                                                     */
/* ========================================================= */

void window_print(
    Window *window)
{
    if(window==NULL)
        return;

    printf("---------------\n");
    printf("WINDOW\n");
    printf("Title : %s\n",window->title);
    printf("Pos   : %d %d\n",window->x,window->y);
    printf("Size  : %d x %d\n",window->width,window->height);
    printf("Visible : %d\n",window->visible);
    printf("Focused : %d\n",window->focused);
    printf("Dragging: %d\n",window->dragging);
    printf("Resize  : %d\n",window->resizing);
    printf("---------------\n");
}

/* ========================================================= */
/* DESTROY                                                   */
/* ========================================================= */

void window_destroy(
    Window *window)
{
    if(window==NULL)
        return;

    memset(window,0,sizeof(Window));
}

/* ========================================================= */
/* END                                                       */
/* ========================================================= */