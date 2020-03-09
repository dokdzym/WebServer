cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp util.c util.h epoll.c epoll.h http.c http.h http_parse.cpp http_parse.h http_request.c http_request.h timer.c timer.h threadpool.c threadpool.h)