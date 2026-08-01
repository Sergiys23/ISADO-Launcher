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
#include "../process/process.h"

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

    printf("=====================================\n");
    printf("           %s\n", SYSTEM_NAME);
    printf("         Version %s\n", ISADO_VERSION);
    printf("=====================================\n\n");

    boot_step("Hardware check");
    boot_step("Loading kernel");

    kernel_init();

    boot_step("Loading core");

    core_init();

    boot_step("Starting Process Manager");

    process_init();

    {
        printf("[BOOT] Notepad started successfully.\n");
    }
    else
    {
        printf("[BOOT] Failed to start Notepad.\n");
    }

    boot_step("Starting shell");

    shell_init();
    #include "../system/ai/assistant.h"

    boot_step("Launching GUI");

    if(gui_init())
    {
        printf("[BOOT] GUI started successfully.\n");
    }
    else
    {
        printf("[BOOT] GUI failed to start.\n");
    }

    process_shutdown();

    gui_shutdown();

    printf("\nISADO shutdown complete.\n");

    return 0;
}