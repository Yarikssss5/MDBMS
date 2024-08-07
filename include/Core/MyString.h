#ifndef MYSTRING_I
#define MYSTRING_I


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    size_t length;
    size_t top;
} MyString;


typedef struct {
    MyString *data;
    size_t length;
    size_t top;
} ArrayofMyString;


inline void print_MyString(MyString *str) {
    if (str != NULL) {
        if (str->data != NULL) {
            printf("%s \n", str->data);
        }
    }
}


inline size_t get_size_MyString(MyString *str) {
    if (str != NULL) 
        return (size_t)( sizeof(MyString) + ( sizeof(char) * str->length ) );
    else return 0;
}


inline MyString *empty_MyString() {
    MyString *tmp = (MyString*)malloc(sizeof(MyString));
    if (tmp != NULL) { 
        tmp->length = 0;
        tmp->top = 0;
        tmp->data = NULL;
    }
    return tmp;
}


inline MyString *MyString_from(char *str) {
    if (str != NULL) {
        MyString *tmp = empty_MyString();
        tmp->data = str;
        tmp->length = strlen(str);
        tmp->top = tmp->length;
        return tmp;
    }
    else return NULL;
}


inline void remove_MyString(MyString *str) {
    if (str != NULL) {
        if (str->data != NULL) free(str->data);
        free(str);
    }
}


inline bool safe_change_size_MyString(MyString *str, size_t new_size) {
    if (str != NULL) {
        if(str->length > new_size) return false;
        char *tmp = (char*)malloc(sizeof(char) * new_size);
        if (tmp == NULL) return false;
        if (str->length != 0) 
            for (int i = 0; i < (int)str->length; i++)
                tmp[i] = str->data[i];
        str->length = new_size;
        return true;
    }
    else return false;
}


inline int write_MyString(FILE *file, MyString *str) {
    if (file != NULL && str != NULL) {
        fputc((int)str->top, file);
        fputc((int)str->length, file);
        for (int i = 0; i < (int)str->length; i++)
            fputc((int)str->data[i], file);
        return 0;
    }
    else return 1;
}


inline int read_MyString(FILE *file, MyString *str) {
    if (file != NULL && str != NULL) {
        str->top = fgetc(file);
        str->length = fgetc(file);
        if (str->data != NULL) free(str->data);
        str->data = (char*)malloc(sizeof(char) * str->length);
        if (str->data != NULL) {
            for (int i = 0; i < (int)str->length; i++)
                str->data[i] = (char)fgetc(file);
            return 0;
        }
        else return 1;
    }
    else return 1;
}


inline MyString *get_slice_MyString(MyString *str, size_t start, size_t end) {
    if (str == NULL) return NULL;
    else if (str->data == NULL) return NULL;
    else if (start < str->length &&
            start >= 0 &&
            end >= 0 &&
            end <= str->length) return NULL;
    MyString *out = (MyString*)malloc(sizeof(MyString));
    if (out == NULL) return NULL;
    out->length = ( end - start ) + 1;
    out->data = (char*)malloc(sizeof(char) * out->length );
    if (out->data == NULL) {
        free(out);
        return NULL;
    }
    int counter = 0;
    out->data = (char*)memcpy(out->data, str->data, out->length);
    return out;
}


inline ArrayofMyString *join_MyString(MyString *str, const char sep) {
    if (str == NULL) return NULL;
    if (str->data == NULL) return NULL;
    ArrayofMyString *out = (ArrayofMyString*)malloc(sizeof(ArrayofMyString));
    if (out == NULL) return NULL;
    out->length = strlen(str->data);
    out->data = (MyString*)malloc(sizeof(MyString) * out->length);
    if (out->data == NULL) {
        free(out);
        return NULL;
    }
    char *buf = (char*)"";
    int str_counter = 0;
    while (buf != NULL) {
        buf = strtok(str->data, &sep);
        out->data[str_counter].top = strlen(buf);
        out->data[str_counter].length = strlen(buf);
        out->data[str_counter].data = (char*)memcpy(buf, out->data[str_counter].data, (sizeof(char) * strlen(buf)));
        str_counter += 1;
    }
    return out;
}


#endif
