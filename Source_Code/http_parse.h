//
// Created by jojo on 2020/3/9.
//

#ifndef HTTP_PARSE_H
#define HTTP_PARSE_H

#define CR '\r'
#define LF '\n'

// http请求行解析
int jo_http_parse_request_line(jo_http_request_t *request);
// http请求体解析
int jo_http_parse_request_body(jo_http_request_t *request);

#endif
