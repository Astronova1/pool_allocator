#include <iostream>
using namespace std;

int allocate(int &head ,const int add[]) {
    if (head == -1) {
        return -1;
    }
    const int allo = head;
    head = add[head];
    cout << endl << allo << " allocated" << endl;
    return 0;
}

int de_allocate(int add[], const int &free,int &head) {
    add[free] = head;
    head = free;
    return 0;
}

int freelist(int add[], const int head) {
    if (head == -1) {
        return -1;
    }
    cout << endl;
    cout << "======FREE_LIST======" << endl;
    for (int i=head; i<= 32/4; i++ ) {
        if (i>7) {
            return -1;
        }
        cout << i <<  " Points to " << ": " << add[i] << endl;
    }
    cout << endl << endl;
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

    cout << "Head is " << head << endl;
    delete[] arena;
    return 0;
}