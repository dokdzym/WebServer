//
// Created by jojo on 2020/3/9.
//

#ifndef JO_TIMER_H
#define JO_TIMER_H

#include "priority_queue.h"
#include "http_request.h"

#define TIMEOUT_DEFAULT 500     /* ms */

// 函数指针，负责超时处理，jo_add_timer时指定处理函数
typedef int (*timer_handler_pt)(jo_http_request_t* request);

typedef struct jo_timer{
    size_t key;    // 标记超时时间
    int deleted;    // 标记是否被删除
    timer_handler_pt handler;    // 超时处理，add时指定
    jo_http_request_t* request;    // 指向对应的request请求
} jo_timer_t;

// jo_pq_t定义在"priority_queue.h"中，优先队列中节点
extern jo_pq_t jo_timer;
extern size_t jo_current_msec;

int jo_timer_init();
int jo_find_timer();
void jo_handle_expire_timers();
void jo_add_timer(jo_http_request_t* request, size_t timeout, timer_handler_pt handler);
void jo_del_timer(jo_http_request_t* request);
int timer_comp(void *ti, void *tj);

#endif
