#include "include/Main.h"
#include <stdio.h>
#include "include/TH.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Input file not found\nUsage: th <filename.th>\n");

        return 1;
    }

    run_File(argv[1]);

    return 0;
}