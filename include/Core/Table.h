#ifndef TABLE_I
#define TABLE_I


#include "Record.h"


typedef struct {
	Record *data;
	size_t length;
	size_t top;
	MyString name;
} Table;


inline Table *new_Table() {
	Table *tmp = (Table*)malloc(sizeof(Table));
	if (tmp != NULL) {
        tmp->data = NULL;
        tmp->length = 0;
        tmp->name = *empty_MyString();
	}
	return tmp;
}


inline bool change_size_Table(Table *table, size_t new_size) {
    if (table != NULL) {
        Record *tmp = (Record*)malloc(sizeof(Record) * new_size);
        if (tmp != NULL) {
            if (table->length != 0) {
                for (int i = 0; i < (int)table->length; i++) 
                    tmp[i] = table->data[i];
                free(table->data);
                table->data = tmp;
                table->length = new_size;
                return true;
            }
            else {
                table->data = tmp;
                table->length = new_size;
                return true;
            }
        }
        else return false;
    }
    else return false;
}


#endif
