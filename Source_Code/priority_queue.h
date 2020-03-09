#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdlib.h>

#define JO_PQ_DEFAULT_SIZE 10

typedef int (*jo_pq_comparator_pt)(void *pi, void *pj);

typedef struct priority_queue{
    void **pq;
    size_t nalloc;
    size_t size;
    jo_pq_comparator_pt comp;
}jo_pq_t;

int jo_pq_init(jo_pq_t *jo_pq, jo_pq_comparator_pt comp, size_t size);
int jo_pq_is_empty(jo_pq_t *jo_pq);
size_t jo_pq_size(jo_pq_t *jo_pq);
void *jo_pq_min(jo_pq_t *jo_pq);
int jo_pq_delmin(jo_pq_t *jo_pq);
int jo_pq_insert(jo_pq_t *jo_pq, void *item);
int jo_pq_sink(jo_pq_t *jo_pq, size_t i);

#endif 

