#ifndef STR_FUNCS_H
#define STR_FUNCS_H

#include <stddef.h>

char *file_to_buffer(const char *filename);
char **split_lines(const char *buffer, size_t *line_count);

#endif
