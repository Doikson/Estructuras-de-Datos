#include <iostream>
#include <cstdlib>

using namespace std;

struct NodoDoble {
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

class ListaDoble {
private:
    NodoDoble* cabeza;
    NodoDoble* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    void agregar(int dato) {
        NodoDoble* nuevo = new NodoDoble{dato, nullptr, nullptr};
        if (!cabeza) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    void mostrar() {
        NodoDoble* temp = cabeza;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    void reversa() {
        NodoDoble* temp = nullptr;
        NodoDoble* actual = cabeza;
        while (actual) {
            temp = actual->anterior;
            actual->anterior = actual->siguiente;
            actual->siguiente = temp;
            actual = actual->anterior;
        }
        if (temp) {
            cabeza = temp->anterior;
        }
    }

    void shiftderecho() {
        if (!cola || cola == cabeza) return;

        cola->siguiente = cabeza;
        cabeza->anterior = cola;
        cabeza = cola;
        cola = cola->anterior;
        cola->siguiente = nullptr;
        cabeza->anterior = nullptr;
    }

    void shiftizquierdo() {
        if (!cabeza || cabeza == cola) return;

        NodoDoble* nuevoUltimo = cola->siguiente;
        nuevoUltimo->anterior = nullptr;
        cola->siguiente = cabeza;
        cabeza->anterior = cola;
        cabeza = cabeza->siguiente;
        cabeza->anterior = nullptr;
        cola = nuevoUltimo;
    }
};

int main() {
    ListaDoble lista;
    srand(time(nullptr));

    for (int i = 0; i < 10; i++) {
        lista.agregar(rand() % 100); // Números aleatorios entre 0 y 99
    }

    cout << "Lista original:" << endl;
    lista.mostrar();

    cout << "Lista en reversa:" << endl;
    lista.reversa();
    lista.mostrar();

    cout << "Lista después de shift derecho:" << endl;
    lista.shiftderecho();
    lista.mostrar();

    cout << "Lista después de shift izquierdo:" << endl;
    lista.shiftizquierdo();
    lista.mostrar();

    return 0;
}
