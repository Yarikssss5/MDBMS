#ifndef IOBUF_I
#define IOBUF_I


typedef struct {
	size_t length;
	size_t top;
	char *data;
} IOBuf;


#endif