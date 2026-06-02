#include<iostream>
#include <cstddef>
#include "poolAllocator.h"

poolAllocator::poolAllocator( const int slot_size)
    : m_head {-1}
    , m_slot_size {slot_size}
{
    m_arena = new std::byte[m_slot_size*sizeof(int)];   //change to pointer to the byte
    m_add = reinterpret_cast<int*>(m_arena);
    std::cout << "Head is " << m_head << std::endl;
    for (int i=0; i< m_slot_size; i++) {        //create the pointer based linked list
        if (i >= m_slot_size-1) {
            m_add[i] = -1;
        }
        else {
           m_add[i] = i+1;
        }
    }
    m_head = 0;
}

int poolAllocator::allocate() {             //allocate the free memory space
    if (m_head == -1) {         //return -1 if memory arena is empty
        std::cout << "Head is -1" << std::endl;
        return -1;
    }
    const int allo = m_head;
    m_head = m_add[m_head];           //allocate the value of the current head as the new head
    std::cout << std::endl << allo << " allocated" << std::endl;
    std::cout << "New head is : " << m_head << std::endl;
    return allo;
}

int poolAllocator::de_allocate(const int &free) {         //frees the slot currently allocated
    if (free > m_slot_size) {
        std::cout << "Slot to be freed should be less than " << m_slot_size;
        return -1;
    }
    m_add[free] = m_head;               //set block freed value to point it to the old head
    m_head = free;                   //set the current head to the freed slot
    std::cout << std::endl << free << " de-allocated" << std::endl;
    return 0;
}

int poolAllocator::printlist() const {         //travers the free list if it is not allocated
    int curr = m_head;
    if (curr == -1) {               //return -1 if no memory slot free
        std::cout << "All slot are Allocated";
        return -1;
    }
    std::cout << std::endl;
    std::cout << "======FREE_LIST======" << std::endl;
    while ( curr != -1 ) {              // check if there are free slots and run the loops until the conditions becomes false
        std::cout << std::endl << curr << " Points to " << m_add[curr] << std::endl ;    //the current head value pointing to the next slot
        curr = m_add[curr];   //change the current to the next slot value
    }
    std::cout << std::endl << std::endl;
    return 0;
}

poolAllocator::~poolAllocator() {
    delete[] m_arena;
    std::cout << "Memory released\n";
}
