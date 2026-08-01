#include "ai.h"

#include "../internet/internet.h"
#include "../internet/http.h"
#include "../phone/phone.h"

#include <stdio.h>
#include <string.h>

static int g_initialized = 0;

bool ai_init(void)
{
    printf("[AI] Initializing...\n");

    g_initialized = 1;

    printf("[AI] Ready\n");

    return true;
}

void ai_shutdown(void)
{
    printf("[AI] Shutdown\n");

    g_initialized = 0;
}

bool ai_execute(
    const char *command,
    char *response,
    int responseSize
)
{
    if(!g_initialized)
        return false;

    if(command == NULL)
        return false;

    if(response == NULL)
        return false;

    memset(response,0,responseSize);

    printf("[AI] %s\n",command);

    if(strcmp(command,"browser")==0)
    {
        strcpy(response,"Opening Browser");

        return ai_open_browser("https://google.com");
    }

    if(strcmp(command,"explorer")==0)
    {
        strcpy(response,"Opening Explorer");

        return ai_open_explorer();
    }

    if(strcmp(command,"terminal")==0)
    {
        strcpy(response,"Opening Terminal");

        return ai_open_terminal();
    }

    if(strcmp(command,"phone")==0)
    {
        strcpy(response,"Connecting Phone");

        return ai_connect_phone();
    }

    if(strcmp(command,"download")==0)
    {
        strcpy(response,"Downloading");

        return ai_download_file(
            "https://example.com"
        );
    }

    if(strcmp(command,"shutdown")==0)
    {
        strcpy(response,"Shutdown");

        return ai_shutdown_system();
    }

    strcpy(response,"Unknown command");

    return false;
}

bool ai_open_browser(const char *url)
{
    printf("[AI] Browser -> %s\n",url);

    return true;
}

bool ai_open_explorer(void)
{
    printf("[AI] Explorer\n");

    return true;
}

bool ai_open_terminal(void)
{
    printf("[AI] Terminal\n");

    return true;
}

bool ai_connect_phone(void)
{
    return phone_connect();
}

bool ai_download_file(const char *url)
{
    HTTPResponse response;

    if(http_get(url,&response))
    {
        printf("%s\n",response.body);

        return true;
    }

    return false;
}

bool ai_shutdown_system(void)
{
    printf("[AI] System Shutdown Requested\n");

    return true;
}