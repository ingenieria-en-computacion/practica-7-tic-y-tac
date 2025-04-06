#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define DECLARE_LINKED_LIST(TYPE) \
typedef struct Node_##TYPE { \
    TYPE data; \
    struct Node_##TYPE* next; \
} Node_##TYPE; \
\
typedef struct { \
    Node_##TYPE* head; \
    Node_##TYPE* tail; \
    size_t length; \
} List_##TYPE; \
\
List_##TYPE* list_##TYPE##_create(void); \
void list_##TYPE##_destroy(List_##TYPE* list); \
bool list_##TYPE##_insert(List_##TYPE* list, TYPE data, size_t pos); \
bool list_##TYPE##_append(List_##TYPE* list, TYPE data); \
bool list_##TYPE##_remove_at(List_##TYPE* list, size_t pos); \
bool list_##TYPE##_get(const List_##TYPE* list, size_t pos, TYPE* out); \
size_t list_##TYPE##_length(const List_##TYPE* list); \
void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE));

DECLARE_LINKED_LIST(int)
