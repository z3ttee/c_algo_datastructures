cmake_minimum_required(VERSION 3.19)
project(binary_search C)

set(CMAKE_C_STANDARD 11)

add_executable(binary_search main.c searchTree.h searchTree.c)