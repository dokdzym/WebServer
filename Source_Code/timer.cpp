//
// Created by jojo on 2020/3/9.
//

#include <sys/time.h>
#include "timer.h"

jo_pq_t jo_timer;
size_t jo_current_msec;

int timer_comp(void* ti, void* tj){
    jo_timer_t* timeri = (jo_timer_t*)ti;
    jo_timer_t* timerj = (jo_timer_t*)tj;
    return (timeri->key < timerj->key) ? 1 : 0;
}

void jo_time_update(){
    // 获取当前时间
    struct timeval tv;
    int rc = gettimeofday(&tv, NULL);
    jo_current_msec = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int jo_timer_init(){
    // 建立连接后立即初始化
    // 初始优先队列大小JO_PQ_DEFAULT_SIZE = 10
    int rc = jo_pq_init(&jo_timer, timer_comp, JO_PQ_DEFAULT_SIZE);

    // 更新当前时间
    jo_time_update();
    return 0;
}

int jo_find_timer(){
    int time;
    // 返回队列中最早时间和当前时间之差
    while(!jo_pq_is_empty(&jo_timer)){
        // 更新当前时间
        jo_time_update();
        // timer_node指向最小的时间
        jo_timer_t* timer_node = (jo_timer_t*)jo_pq_min(&jo_timer);
        // 如果已删则释放此节点（jo_del_timer只置位不删除）
        if(timer_node->deleted){
            int rc = jo_pq_delmin(&jo_timer);
            free(timer_node);
            continue;
        }
        // 此时timer_node为时间最小节点，time为优先队列里最小时间减去当前时间
        time = (int)(timer_node->key - jo_current_msec);
        time = (time > 0) ? time : 0;
        break;
    }
    return time;
}

void jo_handle_expire_timers(){
    while(!jo_pq_is_empty(&jo_timer)){
        // 更新当前时间
        jo_time_update();
        jo_timer_t* timer_node = (jo_timer_t*)jo_pq_min(&jo_timer);
        // 如果已删则释放此节点
        if(timer_node->deleted){
            int rc = jo_pq_delmin(&jo_timer); 
            free(timer_node);
            continue;
        }
        // 最早入队列节点超时时间大于当前时间（未超时）
        // 结束超时检查，顺带删了下标记为删除的节点
        if(timer_node->key > jo_current_msec){
            return;
        }
        // 出现了没被删但是超时的情况，调用handler处理
        if(timer_node->handler){
            timer_node->handler(timer_node->request);
        }
        int rc = jo_pq_delmin(&jo_timer); 
        free(timer_node);
    }
}

void jo_add_timer(jo_http_request_t* request, size_t timeout, timer_handler_pt handler){
    jo_time_update();
    // 申请新的jo_timer_t节点，并加入到jo_http_request_t的timer下
    jo_timer_t* timer_node = (jo_timer_t*)malloc(sizeof(jo_timer_t));
    request->timer = timer_node;
    // 加入时设置超时阈值，删除信息等
    timer_node->key = jo_current_msec + timeout;
    timer_node->deleted = 0;
    timer_node->handler = handler;
    // 注意需要在jo_timer_t节点中反向设置指向对应resquest的指针
    timer_node->request = request;
    // 将新节点插入优先队列
    int rc = jo_pq_insert(&jo_timer, timer_node);
}

void jo_del_timer(jo_http_request_t* request) {
    jo_time_update();
    jo_timer_t* timer_node = request->timer;
    // 惰性删除
    // 标记为已删，在find_timer和handle_expire_timers检查队列时会删除
    timer_node->deleted = 1;
}
