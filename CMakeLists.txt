cmake_minimum_required(VERSION 3.16)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA main.cpp list/DoubleLinkedList.cpp list/DoubleLinkedList.h list/SingleLinkedList.cpp list/SingleLinkedList.h stack/Stack.cpp stack/Stack.h queue/Queue.cpp queue/Queue.h)
add_executable(ExpressionEvaluator expression_parser.cpp)
add_executable(TypingTutor typingtutor.cpp XPlatform.c XPlatform.h)
