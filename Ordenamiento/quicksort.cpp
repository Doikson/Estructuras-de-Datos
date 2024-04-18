#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Función para dividir el array y hacer el intercambio en el algoritmo Quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Función recursiva para Quicksort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000); // Rango de números aleatorios

    // Vectores de diferentes tamaños
    vector<int> vec1000, vec10000, vec100000;

    // Llenar los vectores con números aleatorios
    for (int i = 0; i < 1000; i++) {
        vec1000.push_back(dis(gen));
    }
    for (int i = 0; i < 10000; i++) {
        vec10000.push_back(dis(gen));
    }
    for (int i = 0; i < 100000; i++) {
        vec100000.push_back(dis(gen));
    }

    // Medir tiempo de ejecución para vec1000
    auto start = high_resolution_clock::now();
    quicksort(vec1000, 0, vec1000.size() - 1);
    auto end = high_resolution_clock::now();
    auto time1000 = duration_cast<microseconds>(end - start).count();

    // Medir tiempo de ejecución para vec10000
    start = high_resolution_clock::now();
    quicksort(vec10000, 0, vec10000.size() - 1);
    end = high_resolution_clock::now();
    auto time10000 = duration_cast<microseconds>(end - start).count();

    // Medir tiempo de ejecución para vec100000
    start = high_resolution_clock::now();
    quicksort(vec100000, 0, vec100000.size() - 1);
    end = high_resolution_clock::now();
    auto time100000 = duration_cast<microseconds>(end - start).count();

    // Mostrar los tiempos de ejecución en microsegundos
    cout << "Tiempo de ejecucion para 1000 elementos: " << time1000 << " microsegundos." << endl;
    cout << "Tiempo de ejecucion para 10000 elementos: " << time10000 << " microsegundos." << endl;
    cout << "Tiempo de ejecucion para 100000 elementos: " << time100000 << " microsegundos." << endl;

    return 0;
}
