#include <stdio.h>

#include "../process/process.h"

int main()
{
    process_init();

    ISProcess proc;

    process_create(
        &proc,
        "notepad.exe"
    );

    printf(
        "Running: %d\n",
        process_is_running(&proc)
    );

    getchar();

    process_kill(&proc);

    process_shutdown();

    return 0;
}