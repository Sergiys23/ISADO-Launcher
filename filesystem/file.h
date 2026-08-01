#ifndef FILE_H
#define FILE_H

#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    FILE *handle;

    char path[512];

} ISFile;

bool file_open(
    ISFile *file,
    const char *path,
    const char *mode
);

void file_close(
    ISFile *file
);

size_t file_read(
    ISFile *file,
    void *buffer,
    size_t size
);

size_t file_write(
    ISFile *file,
    const void *buffer,
    size_t size
);

#endif