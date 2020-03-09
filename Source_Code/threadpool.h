//
// Created by jojo on 2020/3/9.
//

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

typedef struct jo_task{
    void (*func)(void*);
    void* arg;
    struct jo_task* next;    // 任务链表（下一节点指针）
}jo_task_t;

typedef struct threadpool{
    pthread_mutex_t lock;    // 互斥锁
    pthread_cond_t cond;    // 条件变量
    pthread_t *threads;    // 线程
    jo_task_t *head;    // 任务链表
    int thread_count;    // 线程数 
    int queue_size;    // 任务链表长
    int shutdown;     // 关机模式
    int started;
}jo_threadpool_t;

typedef enum{
    jo_tp_invalid = -1,
    jo_tp_lock_fail = -2,
    jo_tp_already_shutdown = -3,
    jo_tp_cond_broadcast = -4,
    jo_tp_thread_fail = -5,
}jo_threadpool_error_t;

typedef enum{
    immediate_shutdown = 1,
    graceful_shutdown = 2
}jo_threadpool_sd_t;

jo_threadpool_t* threadpool_init(int thread_num);
int threadpool_add(jo_threadpool_t* pool, void (*func)(void *), void* arg);
int threadpool_destroy(jo_threadpool_t* pool, int gracegul);

#endif
