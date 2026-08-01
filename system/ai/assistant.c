#include "assistant.h"

#include "../../process/process.h"

#include <stdio.h>
#include <string.h>

static void execute_windows_program(const char *program)
{
    ISProcess proc;

    process_create(
        &proc,
        program
    );
}

void assistant_execute(const char *command)
{
    if(command==NULL)
        return;

    printf("[AI] %s\n",command);

    /* English */

    if(strcmp(command,"open notepad")==0)
    {
        execute_windows_program(
            "notepad.exe"
        );

        return;
    }

    if(strcmp(command,"open cmd")==0)
    {
        execute_windows_program(
            "cmd.exe"
        );

        return;
    }

    if(strcmp(command,"open explorer")==0)
    {
        execute_windows_program(
            "explorer.exe"
        );

        return;
    }

    /* Українська */

    if(strcmp(command,"відкрий блокнот")==0)
    {
        execute_windows_program(
            "notepad.exe"
        );

        return;
    }

    if(strcmp(command,"відкрий командний рядок")==0)
    {
        execute_windows_program(
            "cmd.exe"
        );

        return;
    }

    if(strcmp(command,"відкрий провідник")==0)
    {
        execute_windows_program(
            "explorer.exe"
        );

        return;
    }

    printf("[AI] Unknown command\n");
}