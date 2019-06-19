#include "queue.h"

int enqueue(urlstring u) {
  if ( tail >= MAX_QUEUE_LEN ) {
    return -1;
  } else {
    memcpy(queue[tail], u, (size_t) MAX_URL_STRING_LEN);
  }
}
