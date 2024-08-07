#ifndef SHELL_I
#define SHELL_I


#include "IOBuf.h"

const char *MDBMS_SQL_WORDS[] = {
    "CREATE",
    "DROP",
    "RENAME",
    "TO",
    "INTO",
    "INSERT",
    "DELETE"
};


const char *SHELL_WORDS[] = {
    ".exit",
    ".open",
};


const char *PREFIX = "MDBMS > ";




#endif
