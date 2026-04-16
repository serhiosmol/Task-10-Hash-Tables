#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>

struct list_item
{
    char *data;
    struct list_item *next;
};

struct list
{
    struct list_item *first, *last;
};

void list_init(struct list *list);
void list_free(struct list *list);
void list_append(struct list *list, const char *data);
int list_is_empty(struct list *list);
size_t list_len(const struct list *list);
void list_print(FILE *stream, const struct list *list);

#endif
