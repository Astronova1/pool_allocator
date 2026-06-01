//
// Created by Dark on 30/05/2026.
//

#ifndef POOL_ALLOCATOR_POOLALLOCATOR_H
#define POOL_ALLOCATOR_POOLALLOCATOR_H
#include <cstddef>


class poolAllocator {
    private:
    int m_head;
    int m_slot_size;
    std::byte* m_arena{nullptr};
    public:
    poolAllocator(int head, int slot_size, std::byte* arena);
    ~poolAllocator();
};


#endif //POOL_ALLOCATOR_POOLALLOCATOR_H
