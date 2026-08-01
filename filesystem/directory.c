#include "directory.h"

#include <stdio.h>
#include <string.h>

#ifdef _WIN32

#include <windows.h>

bool directory_open(
    const char *path,
    ISDirectory *directory
)
{
    if(directory==NULL)
        return false;

    directory->count=0;

    char search[512];

    sprintf(search,"%s\\*",path);

    WIN32_FIND_DATAA fd;

    HANDLE h=FindFirstFileA(search,&fd);

    if(h==INVALID_HANDLE_VALUE)
        return false;

    do
    {
        if(directory->count>=IS_MAX_FILES)
            break;

        strcpy(
            directory->entries[directory->count].name,
            fd.cFileName
        );

        directory->entries[directory->count].isDirectory=
            (fd.dwFileAttributes &
            FILE_ATTRIBUTE_DIRECTORY)!=0;

        directory->count++;

    }while(FindNextFileA(h,&fd));

    FindClose(h);

    return true;
}

bool directory_create(
    const char *path
)
{
    return CreateDirectoryA(path,NULL);
}

bool directory_delete(
    const char *path
)
{
    return RemoveDirectoryA(path);
}

bool directory_rename(
    const char *oldPath,
    const char *newPath
)
{
    return MoveFileA(
        oldPath,
        newPath
    );
}

#else

#include <dirent.h>
#include <sys/stat.h>

bool directory_open(
    const char *path,
    ISDirectory *directory
)
{
    if(directory==NULL)
        return false;

    directory->count=0;

    DIR *dir=opendir(path);

    if(dir==NULL)
        return false;

    struct dirent *entry;

    while(
        (entry=readdir(dir))
    )
    {
        if(directory->count>=IS_MAX_FILES)
            break;

        strcpy(
            directory->entries[directory->count].name,
            entry->d_name
        );

        directory->entries[directory->count].isDirectory=
            entry->d_type==DT_DIR;

        directory->count++;
    }

    closedir(dir);

    return true;
}

bool directory_create(
    const char *path
)
{
    return mkdir(path,0755)==0;
}

bool directory_delete(
    const char *path
)
{
    return rmdir(path)==0;
}

bool directory_rename(
    const char *oldPath,
    const char *newPath
)
{
    return rename(oldPath,newPath)==0;
}

#endif