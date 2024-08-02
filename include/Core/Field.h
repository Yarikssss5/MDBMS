#ifndef FIELD_I
#define FIELD_I

#include "Any.h"

typedef struct {
    Any value;
    MyString name;
    Type flag;
} Field;


inline size_t get_size_Field(Field *field) {
    return (size_t)( sizeof(Any) + sizeof(Type) /**/ );
}

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


inline int write_Field(FILE *file, Field *field) {
    if (file != NULL && field != NULL) {
        write_MyString(file, &field->name);
        switch (field->flag) {
            case INT:
                fputc(1, file);
                fputc(field->value.int_val, file);
                break;
            case CHAR:
                fputc(2, file);
                fputc((int)field->value.char_val, file);
                break;
            case MYSTRING:
                fputc(3, file);
                 write_MyString(file, &field->value.MyString_val);
                break;
            case DOUBLE:
                fputc(4, file);
                fwrite(&field->value.double_val, sizeof(double), 1, file);
                break;
            case BOOL:
                fputc(5, file);
                if (field->value.bool_val) fputc(1, file);
                else fputc(0, file);
                break;
            case FLOAT:
                fputc(6, file);
                fwrite(&field->value.float_val, sizeof(float), 1, file);
                break;
            case UNSIGNED_LONG:
                fputc(7, file);
                fwrite(&field->value.unsigned_long_val, sizeof(unsigned long), 1, file);
                break;
        }
        return 0;
    }
    else return 1;
}


inline int read_Field(FILE *file, Field *field) {
    if (file != NULL && field != NULL) {
        read_MyString(file, &field->name);
        field->flag = (Type)(int)fgetc(file);
        switch (field->flag) {
            case INT:
                field->value.int_val = (int)fgetc(file);
                break;
            case CHAR:
                field->value.char_val = (char)fgetc(file);
                break;
            case MYSTRING:
                read_MyString(file, &field->value.MyString_val);
                break;
            case DOUBLE:
                fread(&field->value.double_val, sizeof(double), 1, file);
                break;
            case BOOL:
                field->value.bool_val = (bool)fgetc(file);
                break;
            case FLOAT:
                fread(&field->value.float_val, sizeof(float), 1, file);
                break;
            case UNSIGNED_LONG:
                field->value.unsigned_long_val = (unsigned long)fgetc(file);
                break;
        }
        return 0;
    }
    else return 1;
}


#endif
