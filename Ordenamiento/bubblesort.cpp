#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<double> v1;
vector<double> v2 {32, 355, 66, 7, 8, 89, 2, 1, 5, 88, 99, 6};

void imprimeVector(vector<double> v);
void burbuja(vector<double> &v, bool imp = false);
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

    burbuja(v1, true);
    cout << "Lista ordenada con burbuja:" << endl;
    imprimeVector(v1);

    seleccion(v2);
    cout << "Lista ordenada con selección:" << endl;
    imprimeVector(v2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() / 1000 << " milisegundos" << endl;

    return 0;
}

void imprimeVector(vector<double> v) {
    for (size_t i = 0; i < v.size(); i++) { // Usamos size_t para evitar comparaciones de tipos diferentes
        cout << v[i] << ",";
    }
    cout << endl;
}

void burbuja(vector<double> &v, bool imp) {
    double temp = 0;
    bool swapp = true;

    while (swapp) {
        swapp = false;
        for (size_t i = 0; i < v.size() - 1; i++) { // Usamos size_t para evitar comparaciones de tipos diferentes
            if (v[i] > v[i + 1]) {
                temp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = temp;
                swapp = true;
            }
        }
    }

    if (imp) {
        cout << "Lista ordenada con burbuja:" << endl;
        imprimeVector(v);
    }
}

void seleccion(vector<double> &v) {
    size_t minIndex = 0; // Usamos size_t para evitar comparaciones de tipos diferentes
    for (size_t i = 0; i < v.size(); i++) { // Usamos size_t para evitar comparaciones de tipos diferentes
        minIndex = i;
        for (size_t j = i + 1; j < v.size(); j++) { // Usamos size_t para evitar comparaciones de tipos diferentes
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        double temp = v[minIndex];
        v[minIndex] = v[i];
        v[i] = temp;
    }
}
