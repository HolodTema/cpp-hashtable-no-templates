cmake_minimum_required(VERSION 3.30)
project(HashTableWithoutTemplates)

set(CMAKE_CXX_STANDARD 20)

add_executable(HashTableWithoutTemplates main.cpp
        LinkedList.cpp
        LinkedList.h
        HashTable.cpp
        HashTable.h
)
