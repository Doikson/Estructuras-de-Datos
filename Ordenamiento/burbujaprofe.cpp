#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<double> v1;
vector<double> v2 {32, 355, 66, 7, 8, 89, 2, 1, 5, 88, 99, 6}; // Lista de números predefinida

void imprimeVector(vector<double> v);
void burbuja(vector<double> &v, bool imp = false); // Se agrega un parámetro para imprimir o no la lista
void seleccion(vector<double> &v);

int main() {
    auto start = high_resolution_clock::now();

    double num = 0;
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> distribution(1.5, 1.90);

    for (int i = 0; i < 10000; i++) {
        num = distribution(gen);
        v1.push_back(num);
    }

    cout << "Lista generada aleatoriamente:" << endl;
    imprimeVector(v1);

    burbuja(v1, true); // Ordena la lista utilizando el algoritmo de burbuja y la imprime
    cout << "Lista ordenada con burbuja:" << endl;
    imprimeVector(v1);

    seleccion(v2); // Ordena la lista predefinida utilizando el algoritmo de selección
    cout << "Lista ordenada con selección:" << endl;
    imprimeVector(v2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() / 1000 << " milisegundos" << endl;

    return 0;
}

void imprimeVector(vector<double> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
    cout << endl;
}

void burbuja(vector<double> &v, bool imp) {
    double temp = 0; // Variable temporal para el intercambio
    bool swapp = true; // Indica si se realizó algún intercambio

    while (swapp) {
        swapp = false;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) {
                temp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = temp;
                swapp = true;
            }
        }
    }

    if (imp) { // Si se especificó imprimir la lista
        cout << "Lista ordenada con burbuja:" << endl;
        imprimeVector(v);
    }
}

void seleccion(vector<double> &v) {
    int minIndex = 0;
    for (int i = 0; i < v.size(); i++) {
        minIndex = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambio de elementos
        double temp = v[minIndex];
        v[minIndex] = v[i];
        v[i] = temp;
    }
}
