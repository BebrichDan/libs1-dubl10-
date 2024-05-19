cmake_minimum_required(VERSION 3.28)
project(dubl10 C)

set(CMAKE_C_STANDARD 23)

add_library(dubl10 STATIC st/library.c)
