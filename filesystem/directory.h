#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stdbool.h>

#define IS_MAX_FILES 1024

typedef struct
{
    char name[260];

    bool isDirectory;

} ISDirectoryEntry;

typedef struct
{
    ISDirectoryEntry entries[IS_MAX_FILES];

    int count;

} ISDirectory;

bool directory_open(
    const char *path,
    ISDirectory *directory
);

bool directory_create(
    const char *path
);

bool directory_delete(
    const char *path
);

bool directory_rename(
    const char *oldPath,
    const char *newPath
);

#endif