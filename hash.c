#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"
#include "hash.h"

void hash_table_init(struct hash_table *tbl, hash_func_t func, size_t size)
{
    tbl->hash_func = func;
    tbl->size = size;
    tbl->data = (struct list *)malloc(sizeof(struct list) * size);
    for (size_t i = 0; i < tbl->size; i++)
    	list_init(&(tbl->data[i]));
}

void hash_table_free(struct hash_table *tbl)
{
    for (size_t i = 0; i < tbl->size; i++)
        list_free(&(tbl->data[i]));
    free(tbl->data);
}

void hash_table_append(struct hash_table *tbl, const char *str)
{
    list_append(&(tbl->data[tbl->hash_func(str) % tbl->size]), str);
}

void hash_table_print(FILE *stream, struct hash_table *tbl)
{
    for (size_t i = 0; i < tbl->size; i++)
    {
	if (!list_is_empty(&(tbl->data[i])))
            continue;
        fprintf(stream, "[%lu]:", i);
        list_print(stream, &(tbl->data[i]));
    }
}

void hash_table_print_stats_csv(FILE *stream, struct hash_table *tbl)
{
    for (size_t i = 0; i < tbl->size; i++)
    {
	if (!list_is_empty(&(tbl->data[i])))
            continue;
        fprintf(stream, "%llu,%llu\n", i, list_len(&(tbl->data[i])));
    }
}

size_t hash_func_zero(const char *str)
{
    return 0;
}

size_t hash_func_first_char(const char *str)
{
    return (size_t)*str;
}

size_t hash_func_len(const char *str)
{
    return strlen(str);
}

size_t hash_func_ascii_sum(const char *str)
{
    size_t sum = 0;
    while (*str)
    {
        sum += (size_t)*str;
        str++;
    }
    return sum;
}

size_t hash_func_rol(const char *str)
{
    size_t val = 0;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        val = ((val << 1) | (val >> 31)) ^ (size_t)str[(i + 1) % len];
    }
    return val;
}

/*
size_t hash_func_crc32(const char *str)
{

}



