#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#include <locale.h>
#endif

#include "boot_config.h"

#include "../kernel/kernel.h"
#include "../core/core.h"
#include "../shell/shell.h"
#include "../gui/gui.h"

void boot_step(const char *text)
{
    printf("[BOOT] %s\n", text);
}

int main(void)
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");
#endif

    printf("==============================\n");
    printf("      %s\n", SYSTEM_NAME);
    printf("      Version %s\n", ISADO_VERSION);
    printf("==============================\n");

    boot_step("Hardware check");
    boot_step("Loading modules");

    kernel_init();

    core_init();

    boot_step("Starting services");

    shell_init();

    boot_step("Launching GUI");

    if (gui_init())
    {
        printf("\nGUI STARTED\n");
    }
    else
    {
        printf("\nGUI ERROR\n");
    }

    gui_shutdown();

    printf("\nISADO SYSTEM HALTED\n");

    return 0;
}