#include <iostream>
#include <vector>
#include <random>
#include <iomanip> // Se agregó esta librería para el formateo de salida
using namespace std;

int main() {
    // Declarar un vector de tipo "double" llamado v1
    vector<double> v1;

    // Configurar el generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.55, 1.90);

    // Generar 1000 números aleatorios y almacenarlos en el vector v1
    for (int i = 0; i < 1000; ++i) {
        v1.push_back(dis(gen));
    }

    // Imprimir los valores recabados
    cout << "Estaturas de los hombres mexicanos en el grupo:" << endl;
    for (auto estatura : v1) {
        cout << fixed << setprecision(2) << estatura << " m" << endl; // Se aplicó formateo a la salida
    }

    // Calcular el promedio de estatura
    double suma = 0.0;
    for (auto estatura : v1) {
        suma += estatura;
    }
    double promedio = suma / v1.size();

    cout << "\nEl promedio de estatura del grupo es: " << fixed << setprecision(2) << promedio << " m" << endl; // Se aplicó formateo a la salida

    return 0;
}
