//
// Created by Dark on 04/06/2026.
//

#ifndef POOL_ALLOCATOR_POIN_POOLALLOCATOR_H
#define POOL_ALLOCATOR_POIN_POOLALLOCATOR_H
#include <cstddef>
#include <optional>

class poin_poolAllocator {
private:
    std::byte* m_head;
    int m_slot_size;
    std::byte* m_arena{nullptr};
public:
    explicit poin_poolAllocator( int slot_size);
    std::optional<std::byte*> de_allocate(std::byte* ptr);
    std::optional<std::byte**> allocate();
    void printlist() const;
    // ~poin_poolAllocator();
};


#endif //POOL_ALLOCATOR_POIN_POOLALLOCATOR_H
