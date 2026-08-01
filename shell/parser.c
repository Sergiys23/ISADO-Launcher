#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "commands.h"

int execute_command(char *input)
{
    input[strcspn(input, "\n")] = '\0';

    if(strlen(input) == 0)
        return 1;

    char *command = strtok(input, " ");
    char *args = strtok(NULL, "");

    if(command == NULL)
        return 1;

    if(strcmp(command, "exit") == 0)
    {
        printf("Leaving ISADO...\n");
        return 0;
    }

    const Command *table = get_command_table();

    int count = get_command_count();

    for(int i = 0; i < count; i++)
    {
        if(strcmp(command, table[i].name) == 0)
        {
            table[i].handler(args);
            return 1;
        }
    }

    printf("Unknown command: %s\n", command);

    return 1;
}