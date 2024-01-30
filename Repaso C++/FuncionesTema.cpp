#include <iostream>
using namespace std;

// Declaración de la función
int suma(int a, int b);

int main() {
    // Llamada a la función desde la función principal (main)
    int resultado = suma(5, 3);

    // Imprimir el resultado
    cout << "La suma es: " << resultado << endl;

    return 0;
}

// Definición de la función
int suma(int a, int b) {
    // Cuerpo de la función
    int resultado = a + b;
    return resultado;
}
