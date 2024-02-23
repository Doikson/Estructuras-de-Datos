/*
Dados los conjuntos de numeros siguientes, guarde en un vector los numeros en comun:

Conjunto A 1, 2, 3, 5, 8, 13, 21, 34, 55, 89

Conjunto B 2, 3, 5, 7, 11, 13, 17, 19, 23, 29

Conteste lo siguiente en un código C++:

Declare dos arreglos con los nombres primero y segundo, y guarde los valores mostrados anteriormente. ✅
Declare un vector llamado comun y guarde los valores comunes en el vector usando la función push_back() 
Imprima los valores comunes usando un iterador.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int primero[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int segundo[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    // Calcula el tamaño del array "primero"
    int arraySize = sizeof(primero) / sizeof(primero[0]);

    vector<int> comun;

    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++)
        {
            if (primero[i] == segundo[j])
            {
                comun.push_back(primero[i]);
            }
        }
    }

    cout << "Elementos comunes: " << endl;
    for (auto k : comun) {
        cout << k << endl;
    }

    return 0;
}
