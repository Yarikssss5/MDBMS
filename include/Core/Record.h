#ifndef RECORD_I
#define RECORD_I

#include "Field.h"


typedef struct {
	Field *data;
	size_t length;
	size_t top;
	size_t id;
	Type *template;
} Record;


Record *new_Record() {
	Record *tmp = (Record*)malloc(sizeof(Record));
	if (tmp != NULL) {
		tmp->data = NULL;
	} 
	return tmp;
}


void remove_Record(Record *record) {
	if (record != NULL) {
		if (record->data != NULL) free(record->data);
		if (record->template != NULL) free(record->template);
		free(record);
	}
}


bool change_size_Record(Record *record, size_t length) {
	if (record != NULL ) {
		Field *tmp = (Field*)malloc(sizeof(Field) * length);
		if (tmp == NULL) return false;
		
	}
	else return false;
}


#endif