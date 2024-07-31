#ifndef MYSTRING_I
#define MYSTRING_I


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *data;
    size_t length;
    size_t top;
} MyString;


MyString *empty_MyString() {
    MyString *tmp = (MyString*)malloc(sizeof(MyString));
    if (tmp != NULL) { 
        tmp->length = 0;
        tmp->top = 0;
        tmp->data = NULL;
    }
    return tmp;
}



#endif
