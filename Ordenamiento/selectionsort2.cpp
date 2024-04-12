#include <iostream>
#include <vector>

using namespace std;

void seleccionSort(vector<int> &lista) {
    int min = 0;
    cout << "Índice mínimo : " << min << endl;
    cout << "Lista original:" << endl;
    for (int num : lista) {
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < lista.size(); i++) {
        min = i;
        for (int j = i + 1; j < lista.size(); j++) {
            if (lista[j] < lista[min]) {
                min = j;
            }
        }
        cout << "Índice mínimo : " << min << endl;

        // Intercambio de elementos
        int temp = lista[min];
        lista[min] = lista[i];
        lista[i] = temp;

        cout << "Parcial : ";
        for (int num : lista) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Final : ";
    for (int num : lista) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> lista = {56, 1, 99, 67, 89, 23, 44, 12, 78, 34};
    seleccionSort(lista);

    return 0;
}
