#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stddef.h>
#include "llist.h"

typedef int (*hash_func_t)(const char *);

struct hash_table
{
    struct list *data;
    hash_func_t hash_func;
    size_t size;
};

void hash_table_init(struct hash_table *tbl, hash_func_t func, size_t size);
void hash_table_free(struct hash_table *tbl);
void hash_table_append(struct hash_table *tbl, const char *str);
void hash_table_print(FILE *stream, struct hash_table *tbl);
void hash_table_print_stats_csv(FILE *stream, struct hash_table *tbl);
size_t hash_func_zero(const char *str);
size_t hash_func_first_char(const char *str);
size_t hash_func_len(const char *str);
size_t hash_func_ascii_sum(const char *str);
size_t hash_func_rol(const char *str);

#endif
