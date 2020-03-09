//
// Created by jojo on 2020/3/9.
//

#ifndef EPOLL_H
#define EPOLL_H

#include"http.h"
#include"threadpool.h"
#include<sys/epoll.h>

#define MaxEvents 2048 //

int jo_epoll_create(int flags);
int jo_epoll_add(int epoll_fd,int fd,jo_http_request_t request,int events);
int jo_epoll_mod(int epoll_fd,int fd,jo_http_request_t request,int events);
int jo_epoll_del(int epoll_fd,int fd,jo_http_request_t request,int events);
int jo_epoll_wait(int epoll_fd,struct epoll_event *events,int max_events,int timeout);
int jo_handler(int epoll_fd,int listen_fd,struct epoll_event * events,
                int events_num,char* path,jo_threadpool_t* pool);
#endif
