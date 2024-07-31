#ifndef FIELD_I
#define FIELD_I

#include "Any.h"

typedef struct {
    Any value;
    MyString name;
} Field;


inline Field *new_Field() {
    Field *tmp = (Field*)malloc(sizeof(Field));
    if ( tmp != NULL ) tmp->name = *empty_MyString();
    return tmp;
}

inline void remove_Field(Field *field) {
    if (field != NULL) {
        free(field);
    }
}


#endif
