cmake_minimum_required(VERSION 3.14)
project(Hashing)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hashing main.cpp hashTable.cpp hashTable.h LinkedList.cpp LinkedList.h)