#ifndef _COMPLEXITY_COMPUTE_QUEUE_H_
#define _COMPLEXITY_COMPUTE_QUEUE_H_

#include <stdbool.h>
#include <stddef.h>
#include "common.h"

typedef struct compute_queue_entry compute_queue_entry_t;

void compute_queue_init();

void compute_queue_destory();

bool compute_queue_try_lock(size_t queue_id);

void compute_queue_lock(size_t queue_id);

void compute_queue_unlock(size_t queue_id);

void compute_queue_compute(size_t queue_id,
                           size_t bulk_size,
                           size_t data_size,
                           long long *results,
                           size_t *tags);

bool compute_queue_try_push(size_t queue_id,
                            size_t tag_start,
                            size_t bulk_size,
                            size_t data_size,
                            int *buffer);

bool compute_queue_try_pop(size_t queue_id, size_t bulk_size);

#endif
