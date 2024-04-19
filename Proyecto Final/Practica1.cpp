//Presentar propuesta iterativa, poner el codigo como texto e imprimirlo todo

#include <iostream>
using namespace std;


// Variable global para acumular los posibles contagios
int contagios = 0;

// Prototipo de la función recursiva
void calcularContagios(int personas);

// Definición de la función recursiva
void calcularContagios(int personas) {
    if (personas == 0) {
        // Caso base: no hay contagios si no hay contacto con personas
        return;
    }

    // Sumar el número actual de personas a los posibles contagios
    contagios += personas;

    // Llamar a la función con un número menor de personas
    calcularContagios(personas - 1);
}

int main() {

    int nPersonas;
    cout << "Ingrese el número de personas con las que el paciente tuvo contacto: ";
    cin >> nPersonas;

    calcularContagios(nPersonas);

    cout << "Posibles contagios: " << contagios << endl;

    return 0;
}
