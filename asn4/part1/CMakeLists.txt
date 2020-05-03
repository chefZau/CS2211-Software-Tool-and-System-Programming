cmake_minimum_required(VERSION 3.12)
project(binarySearchTree C)

set(CMAKE_C_STANDARD 99)

add_executable(binarySearchTree main.c data.c data.h bst.c bst.h)