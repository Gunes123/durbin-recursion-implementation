cmake_minimum_required(VERSION 3.22)
project(l_durbin_recursion C)

set(CMAKE_C_STANDARD 99)

add_executable(l_durbin_recursion main.c stat.h stat.c)
