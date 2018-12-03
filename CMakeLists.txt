cmake_minimum_required(VERSION 3.10)
project(mod_wifi C)

set(CMAKE_C_STANDARD 11)

add_library(mod_wifi mod_wifi.c mod_wifi.h data_pool.h driver.c)

target_link_libraries(mod_wifi libwapi)