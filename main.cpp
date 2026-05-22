#include <iostream>
using namespace std;

int allocate(int slot,int &head ,const int add[]) {
    if (head == -1) {
        return -1;
    }
    head = add[head];
    return 0;
}


int main() {
    std::byte* arena = new std::byte[32];
    int* add = reinterpret_cast<int*>(arena);
    int head = 0 ;
    std::cout <<"Head is " << head << endl;
    for (int i=0; i < 32/4; i++) {
        //pointing arena[i] to the next slot in the list
        cout << "\nAddress of arena: " << add + i;

        if (i >= 7) {
            cout << endl;
            add[i] = -1;
        }
        else {
            cout << endl;
            add[i] = i+1;
        }

        cout << "Points to " << i << ": " << add[i] << endl;
    }
    allocate(0,head, add);
    cout << "Head is " << head << endl;
    delete[] arena;
    return 0;
}