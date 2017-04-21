#ifndef _LIST_H
#define _LIST_H

typedef struct _list_entry {
    struct _list_entry *next;
    char is_list;
    void *data;
} list_entry;

list_entry* parse_to_list(char* s, int len);

list_entry* alloc_list_item();
void free_list_item(list_entry* entry);
void free_list(list_entry* entry);

char* alloc_string(int len);
void free_string(char* s);

int list_test();

#endif
