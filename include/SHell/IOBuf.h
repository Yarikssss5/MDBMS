#ifndef IOBUF_I
#define IOBUF_I


#include <stdio.h>
#include <stdlib.h>


typedef struct {
	size_t length;
	size_t top;
	char *data;
} IOBuf;


#endif
