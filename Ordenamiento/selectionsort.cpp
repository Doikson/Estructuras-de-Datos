#include <iostream>
#include <vector>

using namespace std;

// Función para ordenar la lista utilizando el algoritmo de selección (Selection Sort)
void seleccionSort(vector<int> &lista) {
    cout << "Lista original:" << endl;
    for (int num : lista) { // Itera sobre la lista original e imprime cada elemento
        cout << num << " ";
    }
    cout << endl;

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

        cout << "Índice mínimo: " << minIndex << endl; // Imprime el índice mínimo en cada iteración
        cout << "Parcial: ";
        for (int num : lista) { // Imprime la lista parcial después de cada iteración
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Lista ordenada:" << endl;
    for (int num : lista) { // Imprime la lista ordenada al final
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> lista = {56, 1, 99, 67, 89, 23, 44, 12, 78, 34}; // Lista de números enteros
    seleccionSort(lista); // Llama a la función para ordenar la lista utilizando Selection Sort

    return 0; // Retorna 0 para indicar que el programa se ejecutó correctamente
}