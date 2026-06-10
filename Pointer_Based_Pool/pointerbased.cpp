//
// Created by Dark on 04/06/2026.
//
#include <iostream>
#include "poin_poolAllocator.h"
using namespace std;

int main() {
    poin_poolAllocator p(8);
    std::optional<std::byte*> alloc_result = p.allocate();
    std::byte* ptr = nullptr;
    if (alloc_result.has_value()) {
        ptr = alloc_result.value();
    }
    p.allocate();
    p.printlist();
    p.de_allocate(ptr);
    p.printlist();
    return 0;
}