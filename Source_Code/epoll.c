//
// Created by jojo on 2020/3/9.
//

#include "epoll.h"

struct epoll_event* events;

int zym_epoll_create(int flags){//如果epoll_create1成功，则本函数为events分配了最大大小
    int epoll_fd=epoll_create1(flags);//此处也许可以用epoll_create
    if(epoll_fd==-1)//create失败
        return -1;
    events=(struct epoll_event*)malloc(sizeof(struct epoll_event)*MaxEvents);
    return epoll_fd;
}

int zym_epoll_add(int epoll_fd,int fd,zym_http_request_t request,int events){
    struct epoll_event event;
    event.data.ptr=(void*)request;
    event.events=events;
    int ret=epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);
    if(ret == -1)
        return -1;
}
int zym_epoll_mod(int epoll_fd,int fd,zym_http_request_t request,int events){//修改描述符状态
    struct epoll_event event;
    event.data.ptr = (void*)request;
    event.events = events;
    int ret = epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event);
    if(ret == -1)
        return -1;
}
int zym_epoll_del(int epoll_fd,int fd,zym_http_request_t request,int events){
    struct epoll_event event;
    event.data.ptr = (void*)request;
    event.events = events;
    int ret = epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &event);
    if(ret == -1)
        return -1;
}
int zym_epoll_wait(int epoll_fd,struct epoll_event *events,int max_events,int timeout){
    int ret=epoll_wait(epoll_fd, events, max_events, timeout);
    return ret;//返回活跃事件数目
}
int zym_handler(int epoll_fd,int listen_fd,struct epoll_event * events,
                int events_num,char* path,zym_threadpool_t* pool){
    for(int i=0;i<events_num;i++){
        zym_http_request* request=(zym_http_request*)(events[i].data.ptr);//读取事件里的地址
        int fd=request->fd;//读取该地址的fd
        //以下需要检查，fd变量是监听fd还是连接fd
        //如果是监听fd，建立连接
        if(fd==listen_fd){
            accept_connection(listen_fd,epoll_fd,path);
        }
        else{
            //是连接fd
            //可能是错误事件，比如关联文件发生错误/指定文件描述符被挂起/文件不可进行read（）操作
            if((events[i].events&EPOLLERR)||
            (events[i].events&EPOLLHUP)||
            (!(events[i].events & EPOLLIN))){
                close(fd);
                continue;
            }

            //将请求任务加入到线程池中
            int rc=threadpool_add(pool,do_request,events[i].data.ptr);
        }
    }
}