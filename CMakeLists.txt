cmake_minimum_required(VERSION 3.7)
project(wheels)

set(CMAKE_CXX_STANDARD 11)

add_executable(Rbtree Rbtree/rbtree_test.cpp
        Rbtree/Rbtree.cpp Rbtree/Rbtree.h)