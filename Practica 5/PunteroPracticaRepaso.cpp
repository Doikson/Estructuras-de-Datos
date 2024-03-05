#include <iostream>
using namespace std;



int main (){

    int miEntero = 10;
    int* punteroTest = &miEntero;
    
    cout << "Valor miEntero " << miEntero << endl;
    cout << "Valor puntero " << punteroTest << endl;
    cout << "Valor &punteroTest " << &punteroTest << endl;

    *punteroTest = 20;  //Se modifica el valor int de la direccion de memoria
    cout << "Valor miEntero modificado " << miEntero << endl;

    double* punteroTest1;
    double miDouble = 9.5;
    punteroTest1 = &miDouble;

    cout << "Valor miDouble " << miDouble << endl;
    cout << "Valor puntero " << punteroTest1 << endl;
    cout << "Valor &punteroTest " << &punteroTest1 << endl;


    

}