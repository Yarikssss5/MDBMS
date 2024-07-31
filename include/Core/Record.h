#ifndef RECORD_I
#define RECORD_I

#include "Field.h"


typedef struct {
	Field *data;
	size_t length;
	size_t top;
	size_t id;
} Record;


inline Record *new_Record() {
	Record *tmp = (Record*)malloc(sizeof(Record));
	if (tmp != NULL) {
		tmp->data = NULL;
	} 
	return tmp;
}


inline void remove_Record(Record *record) {
	if (record != NULL) {
		if (record->data != NULL) free(record->data);
		free(record);
	}
}


inline bool safe_change_size_Record(Record *record, size_t new_size) {
	if (record != NULL ) {
		Field *tmp = (Field*)malloc(sizeof(Field) * new_size);
		if (tmp == NULL) return false;
        if (record->length != 0) {
            for (int i = 0; i < (int)record->length; i++) 
                tmp[i] = record->data[i];
            free(record->data);
            record->data = tmp;
            record->length = new_size;
            return true;
        }
        else {
            record->data = tmp;
            record->length = new_size;
            return true;
        }
	}
	else return false;
}


inline bool unsafe_change_size_Record(Record *record, size_t new_size) {
    if (record != NULL) {
        Field *tmp = (Field*)malloc(sizeof(Field) * new_size);
        if (tmp != NULL) {
            if (record->length == 0) {
                record->data = tmp;
                record->length = new_size;
                record->top = 0;
                return true;
            }
            else {
                if (record->length > new_size)
                    for (int i = 0; i < (int)new_size; i++)
                        tmp[i] = record->data[i];

                else if (record->length < new_size) 
                    for (int i = 0; i < (int)record->length; i++) 
                        tmp[i] = record->data[i];

                else if (record->length == new_size) 
                    for (int i = 0; i < (int)new_size; i++)
                        tmp[i] = record->data[i];

                free(record->data);
                record->length = new_size;
                return true;
            }
        }
        else return false;
    }
    else return false;
}


#endif
