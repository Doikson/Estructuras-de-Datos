#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void shellSort(vector<int>& lista) {
    int n = lista.size();
    int h = n / 2;

    while (h > 0) {
        for (int i = h; i < n; i++) {
            int temp = lista[i];
            int j = i;

            while (j >= h && lista[j - h] > temp) {
                lista[j] = lista[j - h];
                j -= h;
            }
            lista[j] = temp;
        }

        h /= 2;
    }
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

    auto start1000 = high_resolution_clock::now();
    shellSort(lista1000);
    auto stop1000 = high_resolution_clock::now();
    auto duration1000 = duration_cast<microseconds>(stop1000 - start1000);

    auto start10000 = high_resolution_clock::now();
    shellSort(lista10000);
    auto stop10000 = high_resolution_clock::now();
    auto duration10000 = duration_cast<microseconds>(stop10000 - start10000);

    auto start100000 = high_resolution_clock::now();
    shellSort(lista100000);
    auto stop100000 = high_resolution_clock::now();
    auto duration100000 = duration_cast<microseconds>(stop100000 - start100000);

    cout << "Tiempo de ejecución para 1000 elementos: " << duration1000.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecución para 10000 elementos: " << duration10000.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecución para 100000 elementos: " << duration100000.count() << " microsegundos" << endl;

    return 0;
}
