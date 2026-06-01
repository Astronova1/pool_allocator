//
// Created by Dark on 30/05/2026.
//
#include<iostream>
#include <cstddef>
#include "poolAllocator.h"

poolAllocator::poolAllocator(int head, int slot_size)
    : m_head {-1}
    , m_slot_size {slot_size}
{
    auto* arena = new std::byte[(slot_size*sizeof(int))];   //change to pointer to the byte
    int* add = reinterpret_cast<int*>(arena);
}



