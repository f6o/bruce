#ifndef __QUEUE_H_INCLUDED
#define __QUEUE_H_INCLUDED

#include <string.h>
#include <stdio.h>

#define MAX_QUEUE_LEN 100
#define MAX_STRING_LEN 1024

typedef char string[MAX_STRING_LEN];

void print_all();
int enqueue(const string);
string *dequeue();
string *top();
void clear();
#endif
