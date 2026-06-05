cmake_minimum_required(VERSION 4.2)
project(pool_allocator)

set(CMAKE_CXX_STANDARD 20)

add_executable(pool_allocator
        Index_Based_Pool/main.cpp
        Index_Based_Pool/poolAllocator.cpp
        Index_Based_Pool/poolAllocator.h
)
add_executable(new_target Pointer_Based_Pool/pointerbased.cpp
        Pointer_Based_Pool/poin_poolAllocator.cpp
        Pointer_Based_Pool/poin_poolAllocator.h)
