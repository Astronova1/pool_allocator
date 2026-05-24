#include <iostream>
using namespace std;

int allocate(int &head ,const int add[]) {    //allocates the slots if slots are free
    if (head == -1) {
        return -1;
    }
    const int allo = head;
    head = add[head];           //allocate the value of the current head as the new head
    cout << endl << allo << " allocated" << endl;
    return 0;
}

int de_allocate(int add[], const int &free,int &head) {         //frees the slot currently allocated
    add[free] = head;               //set block freed value to point it to the old head
    head = free;                   //set the current head to the freed slot
    cout << endl << free << " de-allocated" << endl;
    return 0;
}

int freelist(int add[], int curr) {         //travers the free list if it is not allocated
    if (curr == -1) {
        cout << "All slot are Allocated";
        return -1;
    }
    cout << endl;
    cout << "======FREE_LIST======" << endl;
    while ( curr != -1 ) {              // check if there are free slots and run the loops until the conditions becomes false
        cout << endl << curr << " Points to " << add[curr] << endl ;    //the current head value pointing to the next slot
        curr = add[curr];   //change the current to the next slot value
    }
    cout << endl << endl;
    return 0;
}



int main() {
    std::byte* arena = new std::byte[32];
    int* add = reinterpret_cast<int*>(arena);       //change to pointer to the byte
    int head = 0 ;
    std::cout <<"Head is " << head << endl;
    for (int i=0; i < 32/4; i++) {                  //create a free link list
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
    }
    allocate(head,add);
    freelist(add,head);
    allocate(head,add);
    freelist(add,head);
    allocate(head,add);
    de_allocate(add,0,head);
    allocate(head,add);
    allocate(head,add);
    allocate(head,add);
    allocate(head,add);
    allocate(head,add);
    allocate(head,add);
    allocate(head,add);
    de_allocate(add,0,head);
    de_allocate(add,5,head);
    freelist(add,head);
    cout << "\nHead is " << head << endl;
    delete[] arena;
    return 0;
}