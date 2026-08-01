#include <stdio.h>

#include "../filesystem/directory.h"

int main()
{
    ISDirectory dir;

    if(directory_open("C:\\",&dir))
    {
        for(int i=0;i<dir.count;i++)
        {
            printf(
                "%s %s\n",
                dir.entries[i].isDirectory
                    ? "[DIR]"
                    : "[FILE]",
                dir.entries[i].name
            );
        }
    }

    return 0;
}