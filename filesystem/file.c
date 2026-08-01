#include "file.h"

#include <string.h>

bool file_open(
    ISFile *file,
    const char *path,
    const char *mode
)
{
    if(file == NULL)
        return false;

    file->handle = fopen(path, mode);

    if(file->handle == NULL)
        return false;

    strcpy(file->path, path);

    return true;
}

void file_close(ISFile *file)
{
    if(file == NULL)
        return;

    if(file->handle)
    {
        fclose(file->handle);
        file->handle = NULL;
    }
}

size_t file_read(
    ISFile *file,
    void *buffer,
    size_t size
)
{
    if(file == NULL || file->handle == NULL)
        return 0;

    return fread(buffer,1,size,file->handle);
}

size_t file_write(
    ISFile *file,
    const void *buffer,
    size_t size
)
{
    if(file == NULL || file->handle == NULL)
        return 0;

    return fwrite(buffer,1,size,file->handle);
}