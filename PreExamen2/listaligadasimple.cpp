#include <iostream>
#include <cstdlib>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaSimple {
private:
    Nodo* cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}

    void agregar(int dato) {
        Nodo* nuevo = new Nodo{dato, nullptr};
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    void mostrar() {
        Nodo* temp = cabeza;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    int indice() {
        Nodo* temp = cabeza;
        int indiceMayor = 0;
        int mayor = temp->dato;
        int index = 0;
        while (temp) {
            if (temp->dato > mayor) {
                mayor = temp->dato;
                indiceMayor = index;
            }
            temp = temp->siguiente;
            index++;
        }
        return indiceMayor;
    }

    void swap(int indice1, int indice2) {
        if (indice1 == indice2) return;

        Nodo* temp = cabeza;
        Nodo* nodo1 = nullptr;
        Nodo* nodo2 = nullptr;
        int index = 0;
        while (temp) {
            if (index == indice1) {
                nodo1 = temp;
            }
            if (index == indice2) {
                nodo2 = temp;
            }
            temp = temp->siguiente;
            index++;
        }

        if (nodo1 && nodo2) {
            int tempDato = nodo1->dato;
            nodo1->dato = nodo2->dato;
            nodo2->dato = tempDato;
        }
    }

    void maxmin() {
        Nodo* temp = cabeza;
        int mayor = temp->dato;
        int menor = temp->dato;
        while (temp) {
            if (temp->dato > mayor) {
                mayor = temp->dato;
            }
            if (temp->dato < menor) {
                menor = temp->dato;
            }
            temp = temp->siguiente;
        }
        cout << "Número mayor: " << mayor << endl;
        cout << "Número menor: " << menor << endl;
    }

    void reversa() {
        Nodo* prev = nullptr;
        Nodo* current = cabeza;
        Nodo* next = nullptr;
        while (current) {
            next = current->siguiente;
            current->siguiente = prev;
            prev = current;
            current = next;
        }
        cabeza = prev;
    }
};

int main() {
    ListaSimple lista;
    srand(time(nullptr));

    for (int i = 0; i < 30; i++) {
        lista.agregar(rand() % 100); // Números aleatorios entre 0 y 99
    }

    cout << "Lista original:" << endl;
    lista.mostrar();

    cout << "Índice del número mayor: " << lista.indice() << endl;

    int indice1, indice2;
    cout << "Ingrese el índice del primer elemento a intercambiar: ";
    cin >> indice1;
    cout << "Ingrese el índice del segundo elemento a intercambiar: ";
    cin >> indice2;
    lista.swap(indice1, indice2);

    cout << "Lista después del intercambio:" << endl;
    lista.mostrar();

    cout << "Número mayor y menor:" << endl;
    lista.maxmin();

    cout << "Lista en reversa:" << endl;
    lista.reversa();
    lista.mostrar();

    return 0;
}
