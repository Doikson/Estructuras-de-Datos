//Concatena
#include <iostream>
#include <vector>
#include <algorithm> // Necesario para std::reverse

using namespace std;

vector<int> concatena(vector<int>& V1, vector<int>& V2) {
    vector<int> V3;
    cout << "Size 1: " << V1.size() << endl;
    cout << "Size 2: " << V2.size() << endl;
    int size1 = V1.size();
    int size2 = V2.size();
    int minSize = min(size1, size2); // Obtener el tamaño mínimo entre V1 y V2

    // Invertir el orden del vector 2
    reverse(V2.begin(), V2.end());
    cout << "Vector 2 de reversa: " << endl;
    cout << "V2 = {";
    for (int i = 0; i < V2.size(); ++i) {
        cout << V2[i];
        if (i != V2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    for (int i = 0; i < minSize; i++) {
        V3.push_back(V1[i]);
        V3.push_back(V2[i]);
    }

    // Si los tamaños son diferentes, agregar los elementos restantes del vector más grande
    for (int i = minSize; i < size1; i++) {
        V3.push_back(V1[i]);
    }
    for (int i = minSize; i < size2; i++) {
        V3.push_back(V2[i]);
    }

    if (size1 == size2) {
        cout << "Mismo Numero de Elementos" << endl;
    } else if (size1 > size2) {
        cout << "V1 tiene más elementos que el vector V2" << endl;
    } else {
        cout << "V2 tiene más elementos que el vector V1." << endl;
    }

    return V3; // Devuelve el vector concatenado
}

int main() {

    // Escenario 1
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};

    cout << "Escenario 1:" << endl;
    vector<int> v3_1 = concatena(v1, v2);

    cout << "V3 (Escenario 1) = {";
    for (int i = 0; i < v3_1.size(); ++i) {
        cout << v3_1[i];
        if (i != v3_1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    cout << endl;

    // Escenario 2
    v1 = {1, 2, 3, 4};
    v2 = {5, 6, 7};

    cout << "Escenario 2:" << endl;
    vector<int> v3_2 = concatena(v1, v2);

    cout << "V3 (Escenario 2) = {";
    for (int i = 0; i < v3_2.size(); ++i) {
        cout << v3_2[i];
        if (i != v3_2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    cout << endl;

    // Escenario 3
    v1 = {1, 2, 3};
    v2 = {4, 5, 6, 7};

    cout << "Escenario 3:" << endl;
    vector<int> v3_3 = concatena(v1, v2);

    cout << "V3 (Escenario 3) = {";
    for (int i = 0; i < v3_3.size(); ++i) {
        cout << v3_3[i];
        if (i != v3_3.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    return 0;
}