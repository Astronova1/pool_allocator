//
// Created by Dark on 04/06/2026.
//

#include "poin_poolAllocator.h"
#include <iostream>
#include <cstddef>
#include <optional>

poin_poolAllocator::poin_poolAllocator( const int slot_size)
    : m_head {nullptr}
    , m_slot_size {slot_size}
{
    m_arena = new std::byte[m_slot_size*sizeof(int)];
    for (int i=0; i<slot_size; i++) {
        std::byte* current = m_arena + slot_size * i;     //current pointer of 8 bytes
        std::byte* p_next = m_arena + slot_size * (i+2);  //next pointer of 8 bytes
        std::byte** next;                                // pointer to a pointer
        next = reinterpret_cast<std::byte**>(current);  // imagine current(i.e byte next)  as pointer to pointer
        if (i < m_slot_size-1) {
            *next = nullptr;                           //assign null pointer to the last
        }else {
            *next = p_next;                             // assign next pointer (p_next) to current pointer
        }
        do {

            std::cout << "Slot: "<< i << " " << current << "\n" <<"Slot: " << i+1 << " " << p_next << std::endl;
            i+= 1;
        } while (i >= 8);
    }
    m_head = m_arena ;
    std::cout << "Head is " << m_head << std::endl;
}

 std::optional<std::byte*> poin_poolAllocator::allocate() {             //allocate the free memory space
     if (m_head == nullptr) {         //return -1 if memory arena is empty
         std::cout << "All memory spaces filled" << std::endl;
         return std::nullopt;
     }
    std::byte* allo = m_head;
    m_head = m_arena + m_slot_size;
                //allocate the address inside the current head as the new head
     std::cout << std::endl << allo << " allocated" << std::endl;
     std::cout << "New head is : " << m_head << std::endl;
     return allo;
 }

// int poin_poolAllocator::de_allocate(const int &free) {         //frees the slot currently allocated
//     if (free > m_slot_size) {
//         std::cout << "Slot to be freed should be less than " << m_slot_size;
//         return -1;
//     }
//     m_add[free] = m_head;               //set block freed value to point it to the old head
//     m_head = free;                   //set the current head to the freed slot
//     std::cout << std::endl << free << " de-allocated" << std::endl;
//     return 0;
// }
//
// int poin_poolAllocator::printlist() const {         //travers the free list if it is not allocated
//     int curr = m_head;
//     if (curr == -1) {               //return -1 if no memory slot free
//         std::cout << "All slot are Allocated";
//         return -1;
//     }
//     std::cout << std::endl;
//     std::cout << "======FREE_LIST======" << std::endl;
//     while ( curr != -1 ) {              // check if there are free slots and run the loops until the conditions becomes false
//         std::cout << std::endl << curr << " Points to " << m_add[curr] << std::endl ;    //the current head value pointing to the next slot
//         curr = m_add[curr];   //change the current to the next slot value
//     }
//     std::cout << std::endl << std::endl;
//     return 0;
// }
//
// poin_poolAllocator::~poin_poolAllocator() {
//     delete[] m_arena;
//     std::cout << "Memory released\n";
// }
