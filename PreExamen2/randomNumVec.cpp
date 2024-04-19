//RandomNum Vector
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<double> generarNumerosAleatorios(int cantidad) {
    vector<double> numeros;
    srand(time(nullptr));  // Inicializar la semilla para generar números aleatorios

    for (int i = 0; i < cantidad; i++) {
        double num = rand() / (RAND_MAX + 1.0);  // Generar número aleatorio entre 0 y 1
        numeros.push_back(num);
    }

    return numeros;
}

double max(const vector<double>& numeros) {
    double max = numeros[0];

    for (size_t i = 1; i < numeros.size(); i++) {
        if (numeros[i] > max) {
            max = numeros[i];
        }
    }

    return max;
}

double min(const vector<double>& numeros) {
    double min = numeros[0];

    for (size_t i = 1; i < numeros.size(); i++) {
        if (numeros[i] < min) {
            min = numeros[i];
        }
    }

    return min;
}

size_t indice(const vector<double>& numeros) {
    double max = numeros[0];
    size_t indice = 0;

    for (size_t i = 1; i < numeros.size(); i++) {
        if (numeros[i] > max) {
            max = numeros[i];
            indice = i;
        }
    }

    return indice;
}

void swap(vector<double>& numeros, size_t indice1, size_t indice2) {
    if (indice1 >= numeros.size() || indice2 >= numeros.size()) {
        cout << "Índices fuera de rango." << endl;
        return;
    }

    double temp = numeros[indice1];
    numeros[indice1] = numeros[indice2];
    numeros[indice2] = temp;
}

void shiftdersimple(vector<double>& numeros) {
    double ultimo = numeros.back();
    numeros.pop_back();
    numeros.insert(numeros.begin(), ultimo);
}

void shiftizqsimple(vector<double>& numeros) {
    double primero = numeros[0];
    numeros.erase(numeros.begin());
    numeros.push_back(primero);
}

void shiftder(vector<double>& numeros, size_t indice) {
    if (indice >= numeros.size() - 1) {
        cout << "Índice fuera de rango para mover a la derecha." << endl;
        return;
    }

    double temp = numeros[indice];
    numeros[indice] = numeros[indice + 1];
    numeros[indice + 1] = temp;
}

void shiftizq(vector<double>& numeros, size_t indice) {
    if (indice <= 0) {
        cout << "Índice fuera de rango para mover a la izquierda." << endl;
        return;
    }

    double temp = numeros[indice];
    numeros[indice] = numeros[indice - 1];
    numeros[indice - 1] = temp;
}

int main() {

    int cantidadNumeros;
    cout << "Ingrese la cantidad de números aleatorios que desea generar: ";
    cin >> cantidadNumeros;
    vector<double> numeros = generarNumerosAleatorios(cantidadNumeros);

    cout << "Números generados: ";
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Máximo del vector: " << max(numeros) << endl;
    cout << "Mínimo del vector: " << min(numeros) << endl;
    
    size_t indiceMaximo = indice(numeros);
    cout << "Índice del máximo: " << indiceMaximo << endl;

    cout << "Intercambiar elementos en los índices 1 y 3: ";
    swap(numeros, 1, 3);
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Mover último elemento al principio: ";
    shiftdersimple(numeros);
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Mover primer elemento al final: ";
    shiftizqsimple(numeros);
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Mover a la derecha en el índice 2: ";
    shiftder(numeros, 2);
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Mover a la izquierda en el índice 4: ";
    shiftizq(numeros, 4);
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
