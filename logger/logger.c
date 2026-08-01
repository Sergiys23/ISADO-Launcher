#include <stdio.h>

void log_info(const char *text)
{
    printf("[INFO] %s\n", text);
}

void log_warning(const char *text)
{
    printf("[WARNING] %s\n", text);
}

void log_error(const char *text)
{
    printf("[ERROR] %s\n", text);
}
