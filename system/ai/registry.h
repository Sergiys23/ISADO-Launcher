#ifndef AI_REGISTRY_H
#define AI_REGISTRY_H

#include <stdbool.h>

#define AI_MAX_COMMANDS 256

typedef bool (*AICommandFunction)(const char *args);

typedef struct
{
    char name[64];

    AICommandFunction function;

} AICommand;

bool ai_registry_init(void);

bool ai_register_command(
    const char *name,
    AICommandFunction function
);

AICommand *ai_find_command(
    const char *name
);

bool ai_execute_command(
    const char *name,
    const char *args
);

int ai_command_count(void);

#endif