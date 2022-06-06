cmake_minimum_required(VERSION 3.22)
project(laba23)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(laba23
        ArraySequence.h
        DynamicArray.h
        LinkedList.h
        LinkedListSequence.h
        main.cpp
        Matrix.cpp
        Matrix.h
        Sequence.h
        Tests.cpp
        Tests.h)
