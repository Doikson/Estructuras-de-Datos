#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Función para ordenar la lista utilizando el algoritmo de selección (Selection Sort)
void seleccionSort(vector<int>& lista) {
    auto start = high_resolution_clock::now(); // Marca el inicio del proceso de ordenamiento

    int minIndex = 0; // Variable para almacenar el índice del elemento más pequeño
    for (int i = 0; i < lista.size(); i++) { // Itera sobre la lista
        minIndex = i; // Establece el índice del elemento actual como el mínimo inicialmente
        for (int j = i + 1; j < lista.size(); j++) { // Itera sobre el resto de la lista
            if (lista[j] < lista[minIndex]) { // Compara el elemento actual con el mínimo
                minIndex = j; // Si encuentra un nuevo mínimo, actualiza el índice
            }
        }
        // Intercambia el elemento actual con el mínimo encontrado
        int temp = lista[minIndex];
        lista[minIndex] = lista[i];
        lista[i] = temp;
    }

    auto stop = high_resolution_clock::now(); // Marca el final del proceso de ordenamiento
    auto duration = duration_cast<milliseconds>(stop - start); // Calcula la duración en milisegundos
    cout << "Tiempo de ejecución para " << lista.size() << " elementos: " << duration.count() << " milisegundos" << endl; // Imprime el tiempo en milisegundos
}

int main() {
    vector<int> lista1000;
    for (int i = 0; i < 1000; i++) {
        lista1000.push_back(i); // Rellenamos la lista con números en orden ascendente
    }

    vector<int> lista10000;
    for (int i = 0; i < 10000; i++) {
        lista10000.push_back(i); // Rellenamos la lista con números en orden ascendente
    }

    vector<int> lista100000;
    for (int i = 0; i < 100000; i++) {
        lista100000.push_back(i); // Rellenamos la lista con números en orden ascendente
    }

    seleccionSort(lista1000); // Llama a la función para ordenar la lista de 1000 elementos
    seleccionSort(lista10000); // Llama a la función para ordenar la lista de 10000 elementos
    seleccionSort(lista100000); // Llama a la función para ordenar la lista de 100000 elementos

    return 0; // Retorna 0 para indicar que el programa se ejecutó correctamente
}
