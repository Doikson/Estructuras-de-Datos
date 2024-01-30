#include <iostream>
using namespace std;

int suma(int a, int b, int c) { //Esta es la declaración de la función suma, que toma tres argumentos de tipo int llamados a, b y c.
  return a + b + c; // La funcion devuelve la suma de estos argumentos mediante return
} // Las funciones se localizan fuera del int main

int main (){
    int a = 1;
    int b = 4;
    int c = 3;
    int resultado = suma(a, b, c); //se llama a la funcion suma y se guarda el resultado en la variable 'resultado'
    cout << "El resultado de la suma es: " << resultado << endl;
    return 0;
}