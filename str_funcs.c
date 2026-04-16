#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "str_funcs.h"

char *file_to_buffer(const char *filename)
{
    struct stat st = {0};
    stat(filename, &st);
    FILE *file = fopen(filename, "r");
    size_t size = (size_t)st.st_size;
    char *buffer = (char *)malloc(size + 1);
    fread(buffer, sizeof(char), size, file);
    fclose(file);
    buffer[size] = '\0';
    return buffer;
}

char **split_lines(const char *buffer, size_t *line_count)
{
    size_t capacity = 16;
    char **array = (char **)malloc(capacity * sizeof(char *));

    size_t count = 0;
    const char *start = buffer;
    for (const char *p = buffer; *p; p++)
    {
        if (*p != '\n')
            continue;
        if (count == capacity)
        {
            capacity *= 2;
            array = (char **)realloc(array, capacity * sizeof(char *));
        }
        array[count] = strndup(start, (size_t)(p - start));
        start = p + 1;
        count++;
    }
    *line_count = count;
    return array;
}
