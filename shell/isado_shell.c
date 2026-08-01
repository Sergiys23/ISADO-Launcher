#include "shell.h"

#include <stdio.h>
#include <string.h>

static void help(void)
{
    printf("\nAvailable commands\n");
    printf("------------------\n");
    printf("help\n");
    printf("version\n");
    printf("system\n");
    printf("clear\n");
    printf("exit\n");
}

void shell_init(void)
{
    printf("ISADO Shell initialized\n");
}

void shell_update(void)
{
    /* Тут пізніше буде інтерактивний shell */
}

void shell_shutdown(void)
{
    printf("Shell shutdown\n");
}