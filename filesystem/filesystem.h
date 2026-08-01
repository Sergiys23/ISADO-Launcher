#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdbool.h>

bool filesystem_init(void);
void filesystem_shutdown(void);

bool filesystem_exists(const char *path);

bool filesystem_create_directory(const char *path);

bool filesystem_remove(const char *path);

#endif