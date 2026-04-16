#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

void list_init(struct list *list)
{
    list->first = NULL;
    list->last = NULL;
}

void list_free(struct list *list)
{
    while (list->first)
    {
        struct list_item *tmp = list->first->next;
        free(list->first->data);
        free(list->first);
        list->first = tmp;
    }
    list->last = NULL;
}

void list_append(struct list *list, const char *data)
{
    if (list->first)
    {
        list->last->next =
		(struct list_item *)malloc(sizeof(struct list_item));
        list->last = list->last->next;
    }
    else
    {
        list->first = (struct list_item *)malloc(sizeof(struct list_item));
        list->last = list->first;
    }
    list->last->data = strdup(data);
    list->last->next = NULL;
}

int list_is_empty(struct list *list)
{
    return !!list->first;
}

size_t list_len(const struct list *list)
{
    size_t len = 0;
    for (struct list_item *p = list->first; p; p = p->next)
        len++;
    return len;
}

void list_print(FILE *stream, const struct list *list)
{
    for (struct list_item *p = list->first; p; p = p->next)
        fprintf(stream, "\t\t%s\n", p->data);
}
