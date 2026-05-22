#include <iostream>
using namespace std;

int main() {
    std::byte* arena = new std::byte[32];
    int* add = reinterpret_cast<int*>(arena);
    cout << "arena :" << arena << endl;
    cout << "add : " << add  << endl;
    cout << "add+1 "<<add + 1 << endl;
    int* head = add ;
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

        cout << "value of add " << i << ": " << add[i] << endl;
    }
    delete[] arena;
    return 0;
}