#ifndef IOBUF_I
#define IOBUF_I


#include <stdio.h>
#include <stdlib.h>


typedef struct {
	size_t length;
	size_t top;
	char *data;
} IOBuf;


inline IOBuf *new_IOBuf(size_t size) {
    IOBuf *buf = (IOBuf*)malloc(sizeof(IOBuf));
    if (buf != NULL) {
        buf->data = (char*)malloc(sizeof(char) * size);
        if (buf->data != NULL) {
            buf->length = size;
            buf->top = 0;
            return buf;
        }
        else {
            free(buf);
            return NULL;
        }
    }
    else return NULL;
}


inline void close_IOBuf(IOBuf *buf) {
    if (buf != NULL) {
        if (buf->data != NULL) {
            free(buf->data);
            free(buf);
        }
    }
}


#endif
