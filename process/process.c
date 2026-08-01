#include "process.h"

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

static int nextProcessId = 1;

bool process_init(void)
{
    printf("[PROCESS] Manager initialized\n");
    return true;
}

void process_shutdown(void)
{
    printf("[PROCESS] Manager shutdown\n");
}

bool process_create(
    ISProcess *process,
    const char *program)
{
    if (process == NULL || program == NULL)
        return false;

    memset(process, 0, sizeof(ISProcess));

    process->id = nextProcessId++;

    strncpy(
        process->name,
        program,
        sizeof(process->name) - 1);

    process->name[sizeof(process->name) - 1] = '\0';

#ifdef _WIN32

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));

    si.cb = sizeof(si);

    if (CreateProcessA(
            NULL,
            (LPSTR)process->name,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        process->handle = pi.hProcess;
        process->running = true;

        CloseHandle(pi.hThread);

        printf("[PROCESS] Started: %s\n", process->name);

        return true;
    }

#endif

    printf("[PROCESS] Failed: %s\n", process->name);

    return false;
}

bool process_kill(
    ISProcess *process)
{
#ifdef _WIN32

    if (process == NULL)
        return false;

    if (!process->running)
        return false;

    TerminateProcess(process->handle, 0);

    CloseHandle(process->handle);

    process->running = false;

    printf("[PROCESS] Stopped: %s\n", process->name);

    return true;

#else

    (void)process;
    return false;

#endif
}

bool process_is_running(
    ISProcess *process)
{
    if (process == NULL)
        return false;

    return process->running;
}