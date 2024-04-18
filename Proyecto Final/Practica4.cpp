#include <iostream>
using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    int datos;
    Nodo* siguiente;

    // Constructor sin parámetros
    Nodo() {
        datos = 0;
        siguiente = NULL;
    }

    // Constructor con parámetros
    Nodo(int dato) {
        datos = dato;
        siguiente = NULL;
    }
};

// Definición de la clase ListaLigada
class ListaLigada {
private:
    Nodo* head;

public:
    // Constructor
    ListaLigada() {
        head = NULL;
        cout << "Creación lista con valor NULO" << endl;
    }

    // Función para insertar un nodo al final de la lista
    void insertaNodo(int dato) {
        Nodo* nuevoNodo = new Nodo(dato);

        if (head == NULL) {
            head = nuevoNodo;
            return;
        }

        Nodo* temp = head;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
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

    // Función para eliminar un nodo por su valor
    void eliminarNodo(int datoEliminar) {
        Nodo* temp0 = head;
        Nodo* temp1 = NULL;

        if (temp0 == NULL) {
            cout << "Lista vacía, no se puede eliminar nada." << endl;
            return;
        }

        int tamano = tamanoLista();
        temp0 = head;
        temp1 = NULL;

        if (datoEliminar == 1) {
            head = head->siguiente;
            delete temp0;
            return;
        }

        for (int i = 1; i < datoEliminar; i++) {
            temp1 = temp0;
            temp0 = temp0->siguiente;
        }

        temp1->siguiente = temp0->siguiente;
        delete temp0;
    }
};

int main() {
    ListaLigada lista;
    lista.insertaNodo(10);
    lista.insertaNodo(20);
    lista.insertaNodo(30);
    lista.insertaNodo(40);
    lista.insertaNodo(50);

    cout << "Elementos de la lista:" << endl;
    lista.imprimeLista();

    int tamano = lista.tamanoLista();
    cout << "Tamaño de la lista: " << tamano << endl;

    lista.eliminarNodo(3);

    cout << "Elementos de la lista después de eliminar el tercer nodo:" << endl;
    lista.imprimeLista();

    return 0;
}
