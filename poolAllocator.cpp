//
// Created by Dark on 30/05/2026.
//
#include<iostream>
#include <cstddef>
#include "poolAllocator.h"

poolAllocator::poolAllocator( const int m_slot_size)
    : m_head {0}
    , m_slot_size {m_slot_size}
{
    m_arena = new std::byte[m_slot_size*sizeof(int)];   //change to pointer to the byte
    m_add = reinterpret_cast<int*>(m_arena);
    std::cout << "Head is " << m_head << std::endl;
}


poolAllocator::~poolAllocator() {
    delete[] m_arena;
    std::cout << "Memory released\n";
}
