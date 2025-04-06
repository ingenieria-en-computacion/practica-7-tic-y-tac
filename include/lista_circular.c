#include "circular_list.h"
#define IMPLEMENT_CIRCULAR_LIST(TYPE) \
    CircularList_##TYPE* circular_list_##TYPE##_create() { \
        CircularList_##TYPE* list = malloc(sizeof(CircularList_##TYPE)); \
        if (!list) return NULL; \
        list->tail = NULL; \
        list->length = 0; \
        return list; \
    } \
    \
    void circular_list_##TYPE##_destroy(CircularList_##TYPE* list) { \
        if (!list || !list->tail) return; \
        CircularNode_##TYPE* current = list->tail->next; \
        CircularNode_##TYPE* next_node; \
        do { \
            next_node = current->next; \
            free(current); \
            current = next_node; \
        } while (current != list->tail->next); \
        free(list); \
    } \
    \
    bool circular_list_##TYPE##_append(CircularList_##TYPE* list, TYPE data) { \
        if (!list) return false; \
        CircularNode_##TYPE* new_node = malloc(sizeof(CircularNode_##TYPE)); \
        if (!new_node) return false; \
        new_node->data = data; \
        if (!list->tail) { \
            new_node->next = new_node; \
            list->tail = new_node; \
        } else { \
            new_node->next = list->tail->next; \
            list->tail->next = new_node; \
            list->tail = new_node; \
        } \
        list->length++; \
        return true; \
    } \
    \
    bool circular_list_##TYPE##_remove(CircularList_##TYPE* list, TYPE data) { \
        if (!list || !list->tail) return false; \
        CircularNode_##TYPE* prev = list->tail; \
        CircularNode_##TYPE* curr = list->tail->next; \
        do { \
            if (curr->data == data) { \
                if (curr == list->tail) { \
                    if (curr == curr->next) { \
                        list->tail = NULL; \
                    } else { \
                        list->tail = prev; \
                    } \
                } \
                prev->next = curr->next; \
                free(curr); \
                list->length--; \
                return true; \
            } \
            prev = curr; \
            curr = curr->next; \
        } while (curr != list->tail->next); \
        return false; \
    } \
    \
    void circular_list_##TYPE##_print(CircularList_##TYPE* list, void (*print_fn)(TYPE)) { \
        if (!list || !list->tail) return; \
        CircularNode_##TYPE* current = list->tail->next; \
        printf("["); \
        do { \
            print_fn(current->data); \
            current = current->next; \
            if (current != list->tail->next) printf(", "); \
        } while (current != list->tail->next); \
        printf("]\n"); \
    }

IMPLEMENT_CIRCULAR_LIST(int)
IMPLEMENT_CIRCULAR_LIST(char)
IMPLEMENT_CIRCULAR_LIST(float)
