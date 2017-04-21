#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "list.h"

list_entry* parse_to_list(char* s, int len)
{
    int i = 0, j = 0, k = 0, v = 1;
    list_entry *entry, *temp, *next;

    if (len == 0) {
        return NULL;
    }
    
    entry = alloc_list_item();
    if (entry == NULL) {
        return NULL;
    }

    temp = entry;

    do 
    {
        while (isspace(s[i])) {
            ++i;
        }

        if (i >= len) {
            break;
        }

        j = i;
        if (s[i] != '(') {
            while (j < len && s[j] != ' ') {
                ++j;
            }

            temp->data = alloc_string(j-i);
            if (temp->data) {
                memcpy(temp->data, s+i, j-i);
            } else {
                v = 0;
                break;
            }
        } else {
            ++i;
            ++j;
            k = 1;
            while (j < len && k > 0) {
                if (s[j] == '(') {
                    ++k;
                }
                if (s[j] == ')') {
                    --k;
                }
                ++j;
            }
            if (j < len && s[j] != ' ') {
                v = 0;
                break;
            } else {
                temp->is_list = 1;
                temp->data = parse_to_list(s+i, j-i-1);
            }
        }

        if ((i = j) >= len) {
            break;
        }

        // alloc next
        next = alloc_list_item();
        if (next== NULL) {
            free_list(entry);
            entry = NULL;
            break;
        }

        temp->next = next;
        temp = next;
    } while (i < len);

    if (!v) {
        free_list(entry);
        entry = NULL;
    }
    return entry;
}

list_entry* alloc_list_item()
{
    list_entry* e = (list_entry*)malloc(sizeof(list_entry));

    if (e) {
        e->is_list = 0;
        e->next = NULL;
        e->data = NULL;
    }

    return e;
}

void free_list_item(list_entry* entry)
{
    if (entry) {
        if (entry->is_list) {
            free_list(entry->data);
        } else {
            free_string(entry->data);
        }
        entry->data = NULL;
        free(entry);
        entry = NULL;
    }
}

void free_list(list_entry* entry)
{
    list_entry* temp = entry;

    while (temp) {
        entry = temp->next;
        free_list_item(temp);
        temp = entry;
    }
}

char* alloc_string(int len)
{
    char* s = (char*)malloc(len+1);
    
    if (s) {
        memset(s, 0, len+1);
    }

    return s;
}

void free_string(char* s)
{
    free(s);
}

int list_test()
{
    char* s[] = {"a b c", "(a b c)", "(a (b c) (d e f) g)", "((a b) (c d) (e f))"};
    int i = 0;
    list_entry* a = NULL;
    list_entry* temp = NULL;
    
    for (i = 0; i < sizeof(s)/sizeof(char*); ++i) {
        a = parse_to_list(s[i], strlen(s[i]));
        free_list(a);
    }

    return 0;
}
