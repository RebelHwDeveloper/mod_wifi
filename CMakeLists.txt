cmake_minimum_required(VERSION 3.10)
project(mod_wifi C)

set(CMAKE_C_STANDARD 11)

add_library(mod_wifi library.c library.h data_pool.h)