#include <iostream>
using namespace std;

int main (){

    cout << "Ingrese el primer Num: ";
    int rango1; cin>>rango1;
    cout << "Ingrese el Segundo Num: ";
    int rango2; cin>>rango2;

 if (rango1 > rango2) {
    cout << "Error: El primer numero debe ser menor o igual al segundo numero" << endl;
    return 1;    
}

for (int i = rango1; i <= rango2; ++i) {
        cout << i << " ";
}
return 0;
}