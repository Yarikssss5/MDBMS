#ifndef CORE_I
#define CORE_I


#include "Table.h"

typedef enum {
    Primary = 0,
    Foregin = 1,
} Key_Type;


typedef struct {
    Field *field_ptr;
    Key_Type type;
} Key;


typedef struct {
    Key *data;
    size_t length;
    size_t top;
} Key_storage;


inline Key *new_Key(Field *field, Key_Type Type) {
    if (field == NULL) return NULL;
    Key *key = (Key*)malloc(sizeof(Key));
    if (key == NULL) return NULL;
    key->field_ptr = field;
    key->type = Type;
    return key;
}


inline void remove_Key(Key *key) {
    if (key != NULL) free(key);
}


inline Key_storage *new_Key_storage(size_t key_count) {
    Key_storage *key_st = (Key_storage*)malloc(sizeof(Key_storage));
    if (key_st == NULL) return NULL;
    key_st->data = (Key*)malloc(sizeof(Key) * key_count);
    if (key_st->data == NULL) {
        free(key_st);
        return NULL;
    }
    key_st->length = key_count;
    key_st->top = 0;
    return key_st;
}


inline void remove_Key_storage(Key_storage *key_st) {
    if (key_st != NULL) {
        if (key_st->data != NULL) free(key_st->data);
        free(key_st);
    }
}


#endif
