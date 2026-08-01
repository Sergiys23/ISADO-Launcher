#ifndef PROCESS_H
#define PROCESS_H

#include <stdbool.h>

#define IS_MAX_PROCESSES 256

typedef struct
{
    int id;

    char name[128];

    bool running;

#ifdef _WIN32
    void *handle;
#endif

} ISProcess;

bool process_init(void);

void process_shutdown(void);

bool process_create(
    ISProcess *process,
    const char *program
);

bool process_kill(
    ISProcess *process
);

bool process_is_running(
    ISProcess *process
);

#endif