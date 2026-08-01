#include "registry.h"

#include <stdio.h>
#include <string.h>

static AICommand commands[AI_MAX_COMMANDS];

static int commandCount = 0;

bool ai_registry_init(void)
{
    commandCount = 0;

    printf("[AI] Registry initialized\n");

    return true;
}

bool ai_register_command(
    const char *name,
    AICommandFunction function
)
{
    if(commandCount >= AI_MAX_COMMANDS)
        return false;

    strcpy(
        commands[commandCount].name,
        name
    );

    commands[commandCount].function =
        function;

    commandCount++;

    printf("[AI] Registered: %s\n",name);

    return true;
}

AICommand *ai_find_command(
    const char *name
)
{
    for(int i=0;i<commandCount;i++)
    {
        if(strcmp(commands[i].name,name)==0)
        {
            return &commands[i];
        }
    }

    return NULL;
}

bool ai_execute_command(
    const char *name,
    const char *args
)
{
    AICommand *cmd=
        ai_find_command(name);

    if(cmd==NULL)
    {
        printf("[AI] Unknown command: %s\n",name);

        return false;
    }

    return cmd->function(args);
}

int ai_command_count(void)
{
    return commandCount;
}