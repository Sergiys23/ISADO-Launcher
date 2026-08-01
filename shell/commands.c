#include <stdio.h>
#include <stdlib.h>

#include "commands.h"
#include "../system/system.h"

void cmd_help(const char *args)
{
    (void)args;

    printf("\n========== AVAILABLE COMMANDS ==========\n");
    printf(" help      - Show help\n");
    printf(" version   - Show version\n");
    printf(" sysinfo   - Show system information\n");
    printf(" echo      - Print text\n");
    printf(" about     - About ISADO\n");
    printf(" clear     - Clear console\n");
    printf(" exit      - Exit shell\n");
    printf("========================================\n");
}

void cmd_version(const char *args)
{
    (void)args;

    printf("%s Version %s\n",
           system_name(),
           system_version());
}

void cmd_sysinfo(const char *args)
{
    (void)args;

    printf("\n========== SYSTEM ==========\n");
    printf("System       : %s\n", system_name());
    printf("Version      : %s\n", system_version());

#ifdef _WIN32
    printf("Platform     : Windows\n");
#else
    printf("Platform     : Linux\n");
#endif

#ifdef __GNUC__
    printf("Compiler     : GCC %d.%d\n",
           __GNUC__,
           __GNUC_MINOR__);
#endif

#if defined(_WIN64) || defined(__x86_64__)
    printf("Architecture : x64\n");
#else
    printf("Architecture : x86\n");
#endif

    printf("============================\n");
}

void cmd_echo(const char *args)
{
    if(args)
        printf("%s\n", args);
}

void cmd_about(const char *args)
{
    (void)args;

    printf("\n");
    printf("ISADO Desktop\n");
    printf("Version %s\n", system_version());
    printf("Created by Sergiy\n");
    printf("AI Ready Platform\n");
}

void cmd_clear(const char *args)
{
    (void)args;

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static Command command_table[] =
{
    {"help",     cmd_help},
    {"version",  cmd_version},
    {"sysinfo",  cmd_sysinfo},
    {"echo",     cmd_echo},
    {"about",    cmd_about},
    {"clear",    cmd_clear},
};

const Command* get_command_table(void)
{
    return command_table;
}

int get_command_count(void)
{
    return sizeof(command_table) / sizeof(command_table[0]);
}