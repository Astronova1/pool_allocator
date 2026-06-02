#include <iostream>
#include "poolAllocator.h"
using namespace std;

int main() {
    poolAllocator p(8);
    p.allocate();
    p.printlist();
    p.de_allocate(0);
    p.printlist();
    return 0;
}