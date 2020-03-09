//
// Created by jojo on 2020/3/9.
//

#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

//#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include "util.h"
#include "list.h"

#define JO_AGAIN EAGAIN  //出错，提醒重试

#define JO_HTTP_PARSE_INVALID_METHOD        10
#define JO_HTTP_PARSE_INVALID_REQUEST       11
#define JO_HTTP_PARSE_INVALID_HEADER        12

#define JO_HTTP_UNKNOWN                     0x0001
#define JO_HTTP_GET                         0x0002
#define JO_HTTP_HEAD                        0x0004
#define JO_HTTP_POST                        0x0008

#define JO_HTTP_OK                          200
#define JO_HTTP_NOT_MODIFIED                304
#define JO_HTTP_NOT_FOUND                   404
#define MAX_BUF 8124

typedef struct jo_http_request{
    char* root;
    int fd;
    int epoll_fd;
    char buff[MAX_BUF];
    size_t pos;
    size_t last;
    int state;

    //以下为http请求报文结构，第一部分包含请求方法，URI，HTTP协议版本（前面为请求行request line)
    //                    第二三四部分包含请求头部（request head)，空行，请求数据
    void* request_start;
    void* method_end;
    int method;
    void* uri_start;
    void* uri_end;
    void* path_start;
    void* path_end;
    void* query_start;
    void* query_end;
    int http_major;
    int http_minor;
    void* request_end;

    struct list_head list;//存储请求头，list.h中定义了该结构体

    void* cur_header_key_start;
    void* cur_header_key_end;
    void* cur_header_value_start;
    void* cur_header_value_end;
}jo_http_request_t;

typedef struct jo_http_out{
    int fd;
    int keep_alive;
    time_t mtime;
    int modified;
    int status;
}jo_http_out_t;

typedef struct jo_http_header{
    void* key_start;
    void* key_end;
    void* value_start;
    void* value_end;
    struct list_head list;
}jo_http_header_t;

typedef int (*jo_http_header_handler_pt)(jo_http_request_t* request, jo_http_out_t* out, char* data, int len);

typedef struct jo_http_header_handle{
    char* name;
    jo_http_header_handler_pt handler;    // 函数指针
}jo_http_header_handle_t;

extern jo_http_header_handle_t jo_http_headers_in[];

void jo_http_handle_header(jo_http_request_t* request, jo_http_out_t* out);
int jo_http_close_conn(jo_http_request_t* request);
int jo_init_request_t(jo_http_request_t* request, int fd, int epoll_fd, char* path);
int jo_init_out_t(jo_http_out_t* out, int fd);
const char* get_shortmsg_from_status_code(int status_code);
#endif
