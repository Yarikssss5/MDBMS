#ifndef SHELL_I
#define SHELL_I

#include "../Core/Table.h"
#include "IOBuf.h"

static const char *MDBMS_SQL_WORDS[] = {
    "CREATE",
    "DROP",
    "RENAME",
    "TO",
    "INTO",
    "INSERT",
    "DELETE"
};


static const char *SHELL_WORDS[] = {
    ".exit",
    ".open",
    ".types",
};


static const char *PREFIX = "MDBMS > ";


inline int run_shell() {

    IOBuf *buf = new_IOBuf(1024);

    if (buf == NULL) return 1;
    /*
    while(true) {
        printf("%s", PREFIX);
    }
    */
    return 0;
}


#endif
