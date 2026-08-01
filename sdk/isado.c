#include "isado.h"

#include "../system/ai/ai.h"
#include "../system/internet/http.h"
#include "../system/phone/phone.h"

#include <stdio.h>

bool IS_Window_Create(
    const char *title,
    int x,
    int y,
    int width,
    int height
)
{
    printf("[SDK] Window Create: %s\n",title);

    return true;
}

void IS_Window_Close(void)
{
    printf("[SDK] Window Close\n");
}

void IS_Draw_Clear(
    SDL_Renderer *renderer
)
{
    SDL_SetRenderDrawColor(
        renderer,
        20,
        20,
        20,
        255
    );

    SDL_RenderClear(renderer);
}

void IS_Draw_Present(
    SDL_Renderer *renderer
)
{
    SDL_RenderPresent(renderer);
}

bool IS_AI_Command(
    const char *command
)
{
    char response[2048];

    return ai_execute(
        command,
        response,
        sizeof(response)
    );
}

bool IS_HTTP_GET(
    const char *url
)
{
    HTTPResponse response;

    return http_get(
        url,
        &response
    );
}

bool IS_Phone_Connect(void)
{
    return phone_connect();
}

bool IS_File_Open(
    const char *path
)
{
    printf(
        "[SDK] Open File: %s\n",
        path
    );

    return true;
}