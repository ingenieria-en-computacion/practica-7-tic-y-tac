#include "generic_linked_list.h"

#define IMPLEMENT_LINKED_LIST(TYPE) \
List_##TYPE* list_##TYPE##_create(void) { \
    List_##TYPE* list = malloc(sizeof(List_##TYPE)); \
    list->head = list->tail = NULL; \
    list->length = 0; \
    return list; \
} \
\
void list_##TYPE##_destroy(List_##TYPE* list) { \
    Node_##TYPE* current = list->head; \
    while (current) { \
        Node_##TYPE* temp = current; \
        current = current->next; \
        free(temp); \
    } \
    free(list); \
} \
\
bool list_##TYPE##_insert(List_##TYPE* list, TYPE data, size_t pos) { \
    if (pos > list->length) return false; \
    Node_##TYPE* node = malloc(sizeof(Node_##TYPE)); \
    node->data = data; \
    node->next = NULL; \
    if (pos == 0) { \
        node->next = list->head; \
        list->head = node; \
        if (list->length == 0) list->tail = node; \
    } else { \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < pos - 1; i++) \
            current = current->next; \
        node->next = current->next; \
        current->next = node; \
        if (node->next == NULL) list->tail = node; \
    } \
    list->length++; \
    return true; \
} \
\
bool list_##TYPE##_append(List_##TYPE* list, TYPE data) { \
    return list_##TYPE##_insert(list, data, list->length); \
} \
\
bool list_##TYPE##_remove_at(List_##TYPE* list, size_t pos) { \
    if (pos >= list->length) return false; \
    Node_##TYPE* to_delete; \
    if (pos == 0) { \
        to_delete = list->head; \
        list->head = to_delete->next; \
        if (list->length == 1) list->tail = NULL; \
    } else { \
        Node_##TYPE* current = list->head; \
        for (size_t i = 0; i < pos - 1; i++) \
            current = current->next; \
        to_delete = current->next; \
        current->next = to_delete->next; \
        if (to_delete == list->tail) list->tail = current; \
    } \
    free(to_delete); \
    list->length--; \
    return true; \
} \
\
bool list_##TYPE##_get(const List_##TYPE* list, size_t pos, TYPE* out) { \
    if (pos >= list->length) return false; \
    Node_##TYPE* current = list->head; \
    for (size_t i = 0; i < pos; i++) \
        current = current->next; \
    *out = current->data; \
    return true; \
} \
\
size_t list_##TYPE##_length(const List_##TYPE* list) { \
    return list->length; \
} \
\
void list_##TYPE##_print(const List_##TYPE* list, void (*print_fn)(TYPE)) { \
    Node_##TYPE* current = list->head; \
    printf("["); \
    while (current) { \
        print_fn(current->data); \
        if (current->next) printf(", "); \
        current = current->next; \
    } \
    printf("]\n"); \
}

IMPLEMENT_LINKED_LIST(int)
