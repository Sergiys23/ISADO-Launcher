#include "internet.h"
#include "http.h"

#include <stdio.h>

static bool g_online = false;

bool internet_init(void)
{
    printf("[Internet] Starting service...\n");

    if (!http_init())
    {
        printf("[Internet] HTTP initialization failed\n");
        return false;
    }

    g_online = true;

    printf("[Internet] Service ready\n");
    printf("[Internet] Version: %s\n", internet_version());

    return true;
}

void internet_shutdown(void)
{
    printf("[Internet] Stopping service...\n");

    http_shutdown();

    g_online = false;

    printf("[Internet] Offline\n");
}

bool internet_is_online(void)
{
    return g_online;
}

const char *internet_version(void)
{
    return "ISADO Internet Service v1.0";
}