#ifndef ANY_I
#define ANY_I


#include "MyString.h"
#include <stdbool.h>


#define NULL_INT (int)0
#define NULL_DOUBLE (double)0
#define NULL_CHAR ' '
#define NULL_MYSTRING empty_MyString()
#define NULL_UNSIGNED_LONG (unsigned long) 0
#define NULL_FLOAT (float)0f
#define NULL_BOOL (bool)0


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
    INT = 1,
    CHAR = 2,
    MYSTRING = 3,
    DOUBLE = 4,
    BOOL = 5,
    FLOAT = 6,
    UNSIGNED_LONG = 7,
} Type;


typedef struct {
    Type type;
    Any any;
} MyAny;


#endif
