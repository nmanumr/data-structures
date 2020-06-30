cmake_minimum_required(VERSION 3.16)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA main.cpp linkedlist/SingleLinkedList.cpp linkedlist/SingleLinkedList.h stack/Stack.cpp stack/Stack.h queue/Queue.cpp queue/Queue.h)
