#ifndef SHELL_I
#define SHELL_I


#include "IOBuf.h"

inline const char *MDBMS_SQL_WORDS[] = {
    "CREATE",
    "DROP",
    "RENAME",
    "TO",
    "INTO",
    "INSERT",
    "DELETE"
};


inline const char *SHELL_WORDS[] = {
    ".exit",
    ".open",
};


inline const char *PREFIX = "MDBMS > ";




#endif
