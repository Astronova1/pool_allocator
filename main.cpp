#include <iostream>
using namespace std;

int main() {
    std::byte* arena = new std::byte[32];
    int* add = reinterpret_cast<int*>(arena);
    cout << "arena :" << arena << endl;
    cout << "add : " << add  << endl;
    cout << "add+1 "<<add + 1 << endl;
    cout << add[1] << endl;
    int* head = add ;
    std::cout <<"Head is " << head << endl;
    cout << "sizeof(int) = " << sizeof(int) << ", sizeof(int*) = " << sizeof(int*) << endl;
    for (int i=0; i < 32/4; i++) {          //pointing arena[i] to the next arena i.e i+4 in the list
        //(arena[i]) = reinterpret_cast ;
        cout << "\nAddress of arena: " << add + i;
        cout << endl;
        add[i] = i+1;
        cout << "value of add " << i << ": " << add[i] << endl;
        //auto memhold[i] = reinterpret_cast<int*>(arena);
        //cout << add[i+1] << endl;
    }
    delete[] arena;
    return 0;
}