//
// Created by jojo on 2020/3/9.
//

#ifndef _GNU_SOURCE//可否去掉？
#define _GNU_SOURCE
#endif

#include "http_request.h"

static int jo_http_process_ignore(jo_http_request_t* request, jo_http_out_t* out, char* data, int len);
static int jo_http_process_connection(jo_http_request_t* request, jo_http_out_t* out, char* data, int len);
static int jo_http_process_if_modified_since(jo_http_request_t* request, jo_http_out_t* out, char* data, int len);

jo_http_header_handle_t jo_http_headers_in[] = {
        {"Host", jo_http_process_ignore},
        {"Connection", jo_http_process_connection},
        {"If-Modified-Since", jo_http_process_if_modified_since},
        {"", jo_http_process_ignore}
};

static int jo_http_process_ignore(jo_http_request_t* request, jo_http_out_t* out, char* data, int len){
    (void) request;
    (void) out;
    (void) data;
    (void) len;
    return 0;
}


// 处理连接方式
static int jo_http_process_connection(jo_http_request_t* request, jo_http_out_t* out, char* data, int len){
    (void) request;
    // 记录请求是否为keep-alive
    if (strncasecmp("keep-alive", data, len) == 0) {
        out->keep_alive = 1;
    }
    return 0;
}

// 判断文件是否修改
static int jo_http_process_if_modified_since(jo_http_request_t* request, jo_http_out_t* out, char *data, int len){
    (void) request;
    (void) len;
    struct tm tm;
    // 转换data格式为GMT格式
    if(strptime(data, "%a, %d %b %Y %H:%M:%S GMT", &tm) == (char*)NULL){
        return 0;
    }
    // 将时间转换为自1970年1月1日以来持续时间的秒数
    time_t client_time = mktime(&tm);
    // 计算两个时刻之间的时间差
    double time_diff = difftime(out->mtime, client_time);
    // 微秒时间内未修改status显示未修改，modify字段置为1
    if(fabs(time_diff) < 1e-6){
        out->modified = 0;
        out->status = JO_HTTP_NOT_MODIFIED;
    }
    return 0;
}

// 初始化请求数据结构
int jo_init_request_t(jo_http_request_t* request, int fd, int epoll_fd, char* path){
    // 初始化jo_http_request_t结构
    request->fd = fd;
    request->epoll_fd = epoll_fd;
    request->pos = 0;
    request->last = 0;
    request->state = 0;
    request->root = path;
    INIT_LIST_HEAD(&(request->list));
    return 0;
}

// 初始化响应数据结构
int jo_init_out_t(jo_http_out_t* out, int fd){
    out->fd = fd;
    // 默认值1，保持连接不断开
    out->keep_alive = 1;
    out->modified = 1;
    // 默认为200（success），出错时被修改
    out->status = 200;
    return 0;
}

void jo_http_handle_header(jo_http_request_t* request, jo_http_out_t* out){
    list_head* pos;
    jo_http_header_t* hd;
    jo_http_header_handle_t* header_in;
    int len;
    list_for_each(pos, &(request->list)){
        hd = list_entry(pos, jo_http_header_t, list);
        for(header_in = jo_http_headers_in; strlen(header_in->name) > 0; header_in++){
            if(strncmp(hd->key_start, header_in->name, hd->key_end - hd->key_start) == 0){
                len = hd->value_end - hd->value_start;
                (*(header_in->handler))(request, out, hd->value_start, len);
                break;
            }
        }
        list_del(pos);
        free(hd);
    }
}

// 根据状态码返回shortmsg
const char* get_shortmsg_from_status_code(int status_code){
    if(status_code == JO_HTTP_OK){
        return "OK";
    }
    if(status_code == JO_HTTP_NOT_MODIFIED){
        return "Not Modified";
    }
    if(status_code == JO_HTTP_NOT_FOUND){
        return "Not Found";
    }
    return "Unknown";
}

// 关闭描述符，释放请求数据结构
int jo_http_close_conn(jo_http_request_t* request){
    close(request->fd);
    free(request);
    return 0;
}