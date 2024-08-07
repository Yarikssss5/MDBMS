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


inline int run_shell() {

    IOBuf *buf = new_IOBuf(1024);

    if (buf == NULL) return 1;

    while(true) {
        fgets(buf->data, sizeof(char) * buf->length, stdin);

    }

    return 0;
}


#endif
