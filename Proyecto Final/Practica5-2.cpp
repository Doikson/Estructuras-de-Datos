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

    // Función para imprimir la lista de atrás hacia adelante
    void imprimeListaAtras() {
        Nodo* temp = tail;
        if (tail == NULL) {
            cout << "Lista Vacía" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->datos << " ";
            temp = temp->anterior;
        }
        cout << endl;
    }

    // Función para imprimir la lista de frente hacia atrás
    void imprimeListaFrente() {
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

    // Función para borrar el primer elemento de la lista
    void borraPrimerElemento() {
        if (head == NULL) {
            cout << "Lista Vacía, no se puede borrar nada." << endl;
            return;
        }

        Nodo* temp = head;
        head = head->siguiente;
        if (head != NULL) {
            head->anterior = NULL;
        }
        delete temp;
    }

    // Función para borrar el último elemento de la lista
    void borraUltimoElemento() {
        if (tail == NULL) {
            cout << "Lista Vacía, no se puede borrar nada." << endl;
            return;
        }

        Nodo* temp = tail;
        tail = tail->anterior;
        if (tail != NULL) {
            tail->siguiente = NULL;
        }
        delete temp;
    }

    // Función para insertar un nodo en una posición específica
    void insertaNodoEnPos(int pos, string cancion) {
        Nodo* nuevoNodo = new Nodo(cancion);

        if (pos == 1) {
            nuevoNodo->siguiente = head;
            head->anterior = nuevoNodo;
            head = nuevoNodo;
            return;
        }

        Nodo* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->siguiente;
        }

        if (temp == NULL) {
            cout << "Posición inválida, no se puede insertar." << endl;
            return;
        }

        nuevoNodo->siguiente = temp->siguiente;
        nuevoNodo->anterior = temp;
        if (temp->siguiente != NULL) {
            temp->siguiente->anterior = nuevoNodo;
        }
        temp->siguiente = nuevoNodo;
    }

    // Función para insertar un nodo al inicio de la lista
    void insertaNodoInicio(string cancion) {
        insertaNodoEnPos(1, cancion);
    }
};

int main() {
    ListaLigadaDoble lista;

    lista.insertaNodo("Cancion1");
    lista.insertaNodo("Cancion2");
    lista.insertaNodo("Cancion3");
    lista.insertaNodo("Cancion4");
    lista.insertaNodo("Cancion5");

    cout << "Elementos de la lista de frente hacia atrás:" << endl;
    lista.imprimeListaFrente();

    cout << "Elementos de la lista de atrás hacia adelante:" << endl;
    lista.imprimeListaAtras();

    cout << "Borrando primer elemento..." << endl;
    lista.borraPrimerElemento();
    lista.imprimeListaFrente();

    cout << "Borrando último elemento..." << endl;
    lista.borraUltimoElemento();
    lista.imprimeListaFrente();

    cout << "Insertando nueva canción al inicio..." << endl;
    lista.insertaNodoInicio("NuevaCancion");
    lista.imprimeListaFrente();

    return 0;
}
