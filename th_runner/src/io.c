#include "include/IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_File(const char* filename)
{
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("Could not read file \"%s\"\n", filename);
        exit(1);
    }

    char* buffer = malloc(sizeof(char));

    while ((read = getline(&line, &len, fp)) != -1)
    {
        buffer = realloc(buffer, (strlen(buffer) + strlen(line) + 1) * sizeof(char));
        strcat(buffer, line);
    }

    fclose(fp);

    if (line)
        free(line);
    
    return buffer;
}