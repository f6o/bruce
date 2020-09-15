#include "queue.h"

string queue[MAX_QUEUE_LEN] = { { } };
int tail = 0, head = 0;

void print_all() {
  int i;
  for ( i = 0; i < tail; i++ ) {
    printf("QUEUE %02d: %p %s\n", i, queue[i], queue[i]);
  }
}

int enqueue(const string u) {
  if ( tail >= MAX_QUEUE_LEN ) {
    return -1;
  } else {
    strncpy(queue[tail], u, (size_t) MAX_STRING_LEN);
    queue[tail][MAX_STRING_LEN-1] = '\0';
    tail++;
  }
  return 0;
}

string *top() {
  if ( tail == head )
    return NULL;
  else
    return &queue[head];
}

string *dequeue() {
  if ( tail == head )
    return NULL;
  else
    return &queue[head++];
}