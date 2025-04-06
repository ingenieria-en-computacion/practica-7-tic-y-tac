#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define DECLARE_CIRCULAR_LIST(TYPE)\
    typedef struct CircularNode_##TYPE {\
        TYPE data;\
        struct CircularNode_##TYPE* next;\
    } CircularNode_##TYPE;\
    \
    typedef struct { \
        CircularNode_##TYPE* tail; \
        size_t length; \
    } CircularList_##TYPE; \
    \
    CircularList_##TYPE* circular_list_##TYPE##_create(); \
    void circular_list_##TYPE##_destroy(CircularList_##TYPE* list); \
    bool circular_list_##TYPE##_append(CircularList_##TYPE* list, TYPE data); \
    bool circular_list_##TYPE##_remove(CircularList_##TYPE* list, TYPE data); \
    void circular_list_##TYPE##_print(CircularList_##TYPE* list, void (*print_fn)(TYPE));
