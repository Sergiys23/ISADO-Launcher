#include "filesystem.h"

#include <stdio.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

bool filesystem_init(void)
{
    printf("[FS] Filesystem initialized\n");
    return true;
}

void filesystem_shutdown(void)
{
    printf("[FS] Filesystem shutdown\n");
}

bool filesystem_exists(const char *path)
{
#ifdef _WIN32
    return (_access(path, 0) == 0);
#else
    return (access(path, F_OK) == 0);
#endif
}

bool filesystem_create_directory(const char *path)
{
#ifdef _WIN32
    return (_mkdir(path) == 0);
#else
    return (mkdir(path, 0755) == 0);
#endif
}

bool filesystem_remove(const char *path)
{
#ifdef _WIN32
    return (remove(path) == 0);
#else
    return (unlink(path) == 0);
#endif
}