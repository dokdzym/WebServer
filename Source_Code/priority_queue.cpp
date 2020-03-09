#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"

void exch(jo_pq_t *jo_pq, size_t i, size_t j){
    void *tmp = jo_pq->pq[i];
    jo_pq->pq[i] = jo_pq->pq[j];
    jo_pq->pq[j] = tmp;
}

void swim(jo_pq_t *jo_pq, size_t k){
    while (k > 1 && jo_pq->comp(jo_pq->pq[k], jo_pq->pq[k/2])){
        exch(jo_pq, k, k/2);
        k /= 2;
    }
}

int sink(jo_pq_t *jo_pq, size_t k){
    size_t j;
    size_t nalloc = jo_pq->nalloc;
    while((k << 1) <= nalloc){
        j = k << 1;
        if((j < nalloc) && (jo_pq->comp(jo_pq->pq[j+1], jo_pq->pq[j])))
            j++;

        if(!jo_pq->comp(jo_pq->pq[j], jo_pq->pq[k]))
            break;

        exch(jo_pq, j, k);
        k = j;
    }
    return k;
}

int jo_pq_sink(jo_pq_t *jo_pq, size_t i){
    return sink(jo_pq, i);
}

int jo_pq_init(jo_pq_t *jo_pq, jo_pq_comparator_pt comp, size_t size){
    // 为jo_pq_t节点的pq分配(void *)指针
    jo_pq->pq = (void **)malloc(sizeof(void *) * (size + 1));
    if (!jo_pq->pq)
        return -1;

    jo_pq->nalloc = 0;
    jo_pq->size = size + 1;
    jo_pq->comp = comp;
    return 0;
}

int jo_pq_is_empty(jo_pq_t *jo_pq){
    // 通过nalloc值款快速判断是否为空
    return (jo_pq->nalloc == 0) ? 1 : 0;
}

size_t jo_pq_size(jo_pq_t *jo_pq){
    // 获取优先队列大小
    return jo_pq->nalloc;
}

void *jo_pq_min(jo_pq_t *jo_pq){
    // 优先队列最小值直接返回第一个元素（指针）
    if (jo_pq_is_empty(jo_pq))
        return (void *)(-1);

    return jo_pq->pq[1];
}


int resize(jo_pq_t *jo_pq, size_t new_size){
    if(new_size <= jo_pq->nalloc)
        return -1;

    void **new_ptr = (void **)malloc(sizeof(void *) * new_size);
    if(!new_ptr)
        return -1;
    // 将原本nalloc + 1个元素值拷贝到new_ptr指向的位置
    memcpy(new_ptr, jo_pq->pq, sizeof(void *) * (jo_pq->nalloc + 1));
    // 释放旧元素
    free(jo_pq->pq);
    // 重新改写优先队列元素pq指针为new_ptr
    jo_pq->pq = new_ptr;
    jo_pq->size = new_size;
    return 0;
}

int jo_pq_delmin(jo_pq_t *jo_pq){
    if(jo_pq_is_empty(jo_pq))
        return 0;

    exch(jo_pq, 1, jo_pq->nalloc);
    --jo_pq->nalloc;
    sink(jo_pq, 1);
    if((jo_pq->nalloc > 0) && (jo_pq->nalloc <= (jo_pq->size - 1)/4)){
        if(resize(jo_pq, jo_pq->size / 2) < 0)
            return -1;
    }
    return 0;
}

int jo_pq_insert(jo_pq_t *jo_pq, void *item){
    if(jo_pq->nalloc + 1 == jo_pq->size){
        if(resize(jo_pq, jo_pq->size * 2) < 0){
            return -1;
        }
    }
    jo_pq->pq[++jo_pq->nalloc] = item;
    swim(jo_pq, jo_pq->nalloc);
    return 0;
}
