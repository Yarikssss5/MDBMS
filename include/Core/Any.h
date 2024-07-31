#ifndef ANY_I
#define ANY_I


#include "MyString.h"
#include <stdbool.h>


typedef union {
    MyString MyString_val;
    int int_val;
    char char_val;
    double double_val;
    float float_val;
    bool bool_val;
    unsigned long unsigned_long_val;
} Any;


typedef enum {
    INT,
    CHAR,
    MYSTRING,
    DOUBLE,
    BOOL,
    FLOAT,
    UNSIGNED_LONG,
} Type;


typedef struct {
    Type type;
    Any any;
} MyAny;


#endif
