#include "compute_queue.h"
#include <stdio.h>

static int receive[NUM_BULKS * BUFFER_LENGTH];

int main() {
  compute_queue_init();
  size_t num = 1000;
  size_t i;
  for (i = 0; i < num / NUM_BULKS; ++i) {
    compute_queue_push(0,
                       i * NUM_BULKS,
                       NUM_BULKS,
                       D_ARRAY_SIZE * D_ARRAY_SIZE,
                       receive);
  }
  for (i = 0; i < num / NUM_BULKS; ++i) {
    if (compute_queue_try_pop(0, NUM_BULKS) == false) {
      printf("error!\n");
    }
  }
  compute_queue_destory();
}

