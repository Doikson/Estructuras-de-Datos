#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void burbuja(vector<double>& v);
void seleccion(vector<double>& v);

int main() {
    // Vector con 1000 elementos
    vector<double> v1000;
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> distribution(1.5, 1.90);

    for (int i = 0; i < 1000; i++) {
        double num = distribution(gen);
        v1000.push_back(num);
    }

    auto start1000 = high_resolution_clock::now();
    burbuja(v1000);
    auto stop1000 = high_resolution_clock::now();
    auto duration1000 = duration_cast<microseconds>(stop1000 - start1000);

    // Vector con 10000 elementos
    vector<double> v10000;
    for (int i = 0; i < 10000; i++) {
        double num = distribution(gen);
        v10000.push_back(num);
    }

    auto start10000 = high_resolution_clock::now();
    burbuja(v10000);
    auto stop10000 = high_resolution_clock::now();
    auto duration10000 = duration_cast<microseconds>(stop10000 - start10000);

    cout << "Tiempo de ejecución para 1000 elementos: " << duration1000.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecución para 10000 elementos: " << duration10000.count() << " microsegundos" << endl;

    return 0;
}

void burbuja(vector<double>& v) {
    double temp = 0;
    bool swapp = true;

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
}

void seleccion(vector<double>& v) {
    int minIndex = 0;
    for (int i = 0; i < v.size(); i++) {
        minIndex = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        double temp = v[minIndex];
        v[minIndex] = v[i];
        v[i] = temp;
    }
}
