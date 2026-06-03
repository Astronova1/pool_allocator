

#ifndef POOL_ALLOCATOR_POOLALLOCATOR_H
#define POOL_ALLOCATOR_POOLALLOCATOR_H
#include <cstddef>


class poolAllocator {
    private:
    int m_head;
    int m_slot_size;
    std::byte* m_arena{nullptr};
    int* m_add;
    public:
    explicit poolAllocator( int slot_size);
    int de_allocate(const int &free);
    int allocate();
    int printlist() const;
    ~poolAllocator();
};


#endif //POOL_ALLOCATOR_POOLALLOCATOR_H
