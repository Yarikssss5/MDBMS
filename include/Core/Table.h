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


inline bool safe_change_size_Table(Table *table, size_t new_size) {
    if (table != NULL) {
        if (table->length > new_size) return false;
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


// You can lost data if use this :
inline bool unsafe_change_size_Table(Table *table, size_t new_size) {
    if (table != NULL) {
        Record *tmp = (Record*)malloc(sizeof(Record) * new_size);
        if (tmp == NULL) return false;
        if (table->data == NULL) { 
            table->data = tmp;
            table->length = new_size;
            table->top = 0;
            return true;
        }
        else {
            if (table->length > new_size) 
                for (int i = 0; i < (int)new_size; i++)
                    tmp[i] = table->data[i];
            
            else if (table->length < new_size) 
                for (int i = 0; i < (int)table->length; i++)
                    tmp[i] = table->data[i];

            else if (table->length == new_size) 
                for (int i = 0; i < (int)new_size; i++)
                    tmp[i] = table->data[i];

            free(table->data);
            table->data = tmp;
            return true;
        }
    }
    else return false;
}


inline bool rename_Table(Table *table, MyString *new_name) {
    if (table != NULL && new_name != NULL) {
        if (table->name.length == 0) {
            table->name = *new_name;
            return true;
        } 
        else {
            remove_MyString(&table->name);
            table->name = *new_name;
            return true;
        }
    }
    else return false;
}


inline int write_Table(FILE *file, Table *table) {
    if (file != NULL && table != NULL) {
        write_MyString(file, &table->name);
        fputc(table->top, file);
        fputc(table->length, file);
        for (int i = 0; i < (int)table->length; i++)
            write_Record(file, &table->data[i]);
        return 0;
    }
    else return 1;
}


inline int read_Table(FILE *file, Table *table) {
    if (file != NULL && table != NULL) {
        if (table->name.data != NULL) 
            remove_MyString(&table->name);
        read_MyString(file, &table->name);
        table->top = fgetc(file);
        table->length = fgetc(file);
        for (int i = 0; i < (int)table->length; i++)
            read_Record(file, &table->data[i]);
        return 0;
    }
    else return 1;
}


#endif
