#include <stdlib.h>
#include "hash.h"
#include "llist.h"
#include "str_funcs.h"

#define DEFAULT_INPUT "input.txt"

enum {
    default_hash_table_size = 4297 // should be a prime number
};

int main(int argc, char **argv)
{
    char *buffer = file_to_buffer(DEFAULT_INPUT);
    size_t count = 0;
    char **array = split_lines(buffer, &count);
    struct hash_table tbl = (struct hash_table){0};
    hash_table_init(&tbl, &hash_func_rol, default_hash_table_size);
    for (size_t i = 0; i < count; i++)
        hash_table_append(&tbl, array[i]);
    hash_table_print_stats_csv(stdout, &tbl);
    hash_table_free(&tbl);
    for (size_t i = 0; i < count; i++)
        free(array[i]);
    free(array);
    free(buffer);
    return 0;
}
