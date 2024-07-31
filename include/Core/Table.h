#ifndef TABLE_I
#define TABLE_I


#include "Record.h"


typedef struct {
	Record *data;
	size_t length;
	size_t top;
	MyString name;
} Table;


Table *new_Table() {
	Table *tmp = (Table*)malloc(sizeof(Table));
	if (tmp != NULL) {
		
	}
	return tmp;
}


#endif