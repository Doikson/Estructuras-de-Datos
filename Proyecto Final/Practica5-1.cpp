#include <iostream>
using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    string datos;
    Nodo* siguiente;
    Nodo* anterior;

    // Constructor
    Nodo(string cancion) {
        datos = cancion;
        siguiente = NULL;
        anterior = NULL;
    }
};

// Definición de la clase ListaLigadaDoble
class ListaLigadaDoble {
private:
    Nodo* head;
    Nodo* tail;

public:
    // Constructor
    ListaLigadaDoble() {
        head = NULL;
        tail = NULL;
    }

    // Función para insertar un nodo al final de la lista
    void insertaNodo(string cancion) {
        Nodo* nuevoNodo = new Nodo(cancion);

        if (head == NULL) {
            head = nuevoNodo;
            tail = nuevoNodo;
        } else {
            tail->siguiente = nuevoNodo;
            nuevoNodo->anterior = tail;
            tail = nuevoNodo;
        }
    }

    // Función para obtener el tamaño de la lista
    int tamanoLista() {
        Nodo* temp = head;
        int contador = 0;
        while (temp != NULL) {
            contador++;
            temp = temp->siguiente;
        }
        return contador;
    }

    // Función para imprimir la lista
    void imprimeLista() {
        Nodo* temp = head;
        if (head == NULL) {
            cout << "Lista Vacía" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->datos << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

int main() {
    ListaLigadaDoble lista;

    lista.insertaNodo("Cancion1");
    lista.insertaNodo("Cancion2");
    lista.insertaNodo("Cancion3");
    lista.insertaNodo("Cancion4");
    lista.insertaNodo("Cancion5");

    cout << "Elementos de la lista:" << endl;
    lista.imprimeLista();

    int tamano = lista.tamanoLista();
    cout << "Tamaño de la lista: " << tamano << endl;

    return 0;
}
