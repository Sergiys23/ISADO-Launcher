#include <stdio.h>
#include "kernel.h"

void kernel_init(void)
{
    printf("[KERNEL] Initializing...\n");
}

void kernel_shutdown(void)
{
    printf("[KERNEL] Shutdown.\n");
}
