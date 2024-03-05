#include <iostream>
using namespace std;

int main() {
    int n = 2;
    cout << "El valor de n es: " << n << endl;
    cout << "n esta apuntando a la direccion de memoria: " << &n << endl;
    // Create pointers for n
    void* p1;  //Create a void-pointer
    int* p2;  //Create an int-pointer
  
    p1 = &n;  //let the void pointer reference "n"
    p2 = (int*) p1;  // let int-pointer reference the void-pointer but typecasted to int
    (*p2)++;  // increment the value where p2 is pointing to by 1
  
    //cout << *p2 << endl; // points to the address of n. output will be identical to the line below
    cout << "el valor de n ahora es: " << n << endl;
    cout << "el puntero 1 apunta a la direccion de memoria: "  << p1 << endl;
    cout << "el valor del puntero 2 es: " << *p2 << endl;
    return 0;
}