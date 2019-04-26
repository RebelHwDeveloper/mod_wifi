cmake_minimum_required(VERSION 3.10)
project(mod_wifi C)

set(CMAKE_C_STANDARD 11)

add_library(mod_wifi mod_wifi.h data_pool.h mod_wifi.c)

target_link_libraries(mod_wifi /usr/lib/libnl-3.so  libnl-genl-3.so)
target_link_libraries(mod_wifi -L/home/andi/Desktop/Sistema_Connect_KIT/wapi/wapi/lib/libwapi.so)
