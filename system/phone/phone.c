#include "phone.h"

#include <stdio.h>

static bool connected = false;

bool phone_init(void)
{
    printf("[PHONE] Service initialized\n");

    connected = false;

    return true;
}

void phone_shutdown(void)
{
    printf("[PHONE] Service shutdown\n");
}

bool phone_connect(void)
{
    printf("[PHONE] Connecting...\n");

    connected = true;

    printf("[PHONE] Connected\n");

    return true;
}

void phone_disconnect(void)
{
    printf("[PHONE] Disconnected\n");

    connected = false;
}

bool phone_is_connected(void)
{
    return connected;
}