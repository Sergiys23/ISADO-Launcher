#ifndef ISADO_COMMANDS_H
#define ISADO_COMMANDS_H

typedef void (*command_handler_t)(const char *args);

typedef struct
{
    const char *name;
    command_handler_t handler;
} Command;

void cmd_help(const char *args);
void cmd_version(const char *args);
void cmd_sysinfo(const char *args);
void cmd_echo(const char *args);
void cmd_about(const char *args);
void cmd_clear(const char *args);

const Command* get_command_table(void);
int get_command_count(void);

#endif