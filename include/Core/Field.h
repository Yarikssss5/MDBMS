#ifndef FIELD_I
#define FIELD_I

#include "Any.h"

typedef struct {
    Any value;
    MyString name;
    Type flag;
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


inline bool rename_Field(Field *field, MyString *new_name) {
    if (field != NULL && new_name != NULL) {
        if (field->name.length == 0) {
            field->name = *new_name;
            return true;
        }
        else {
            remove_MyString(&field->name);
            field->name = *new_name;
            return true;
        }
    }
    else return false;
}


#endif
