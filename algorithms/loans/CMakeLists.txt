cmake_minimum_required(VERSION 3.19)
project(loans C)

set(CMAKE_C_STANDARD 11)

add_executable(loans main.c input/input.c input/input.h installment/installment.c installment/installment.h)