//
// Created by Dark on 30/05/2026.
//
#include<iostream>
#include <cstddef>
#include "poolAllocator.h"

poolAllocator::poolAllocator(int head, const int slot_size,std::byte* arena)
    : m_head {0}
    , m_slot_size {slot_size}
{
    arena = new std::byte[slot_size*sizeof(int)];   //change to pointer to the byte
    int* add = reinterpret_cast<int*>(arena);
}


poolAllocator::~poolAllocator() {
    delete[] m_arena;
    std::cout << "Memory released\n";
}
