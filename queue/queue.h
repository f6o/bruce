#include <string.h>

#define MAX_QUEUE_LEN 100
#define MAX_URL_STRING_LEN 1024

typedef char urlstring[MAX_URL_STRING_LEN];

urlstring queue[MAX_QUEUE_LEN] = { 0 };
int tail = 0;
int head = 0;

int enqueue(urlstring);
urlstring *dequeue();
urlstring *top();
void clear();
