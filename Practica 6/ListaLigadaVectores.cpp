#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor = 0) : dato(valor), siguiente(nullptr) {}
};

class ListaLigada {
public:
    Nodo* head;

    ListaLigada() : head(nullptr) {}

    ~ListaLigada() {
        while (head != nullptr) {
            borrarNodoInicio();
        }
    }

    void insertarNodoFinal(int dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        if (head == nullptr) {
            head = nuevoNodo;
        } else {
            Nodo* temp = head;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void insertarNodoInicio(int dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        nuevoNodo->siguiente = head;
        head = nuevoNodo;
    }

    int tamanoLista() {
        int contador = 0;
        Nodo* temp = head;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }
        return contador;
    }

    void borrarNodoInicio() {
        if (head != nullptr) {
            Nodo* temp = head;
            head = head->siguiente;
            delete temp;
        }
    }

    void borrarNodoFin() {
        if (head == nullptr) return;
        if (head->siguiente == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Nodo* temp = head;
            while (temp->siguiente->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            delete temp->siguiente;
            temp->siguiente = nullptr;
        }
    }

    void reservaNodos(int n) {
        for (int i = 0; i < n; ++i) {
            insertarNodoFinal(0); // Asumiendo que "reservar" significa agregar nodos con valor 0
        }
    }

    pair<int, int> end() {
        int index = -1;
        int valor = -1;
        Nodo* temp = head;
        while (temp != nullptr && temp->siguiente != nullptr) {
            temp = temp->siguiente;
            index++;
        }
        if (temp != nullptr) {
            valor = temp->dato;
            index++;
        }
        return {index, valor}; // Devuelve el índice y el valor del último nodo
    }

    bool empty() {
        return head == nullptr;
    }

    void imprimirLista() {
        Nodo* temp = head;
        while (temp != nullptr) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "NULL\n";
    }

    void imprimirListaInverso(Nodo* nodo) {
        if (nodo == nullptr) return;
        imprimirListaInverso(nodo->siguiente);
        cout << nodo->dato << " -> ";
    }

    void imprimirListaInverso() {
        imprimirListaInverso(head);
        cout << "NULL\n";
    }

    void sort() {
        bool swapped;
        do {
            swapped = false;
            Nodo* temp = head;
            while (temp != nullptr && temp->siguiente != nullptr) {
                if (temp->dato > temp->siguiente->dato) {
                    swap(temp->dato, temp->siguiente->dato);
                    swapped = true;
                }
                temp = temp->siguiente;
            }
        } while (swapped);
    }
void obtener(int i) {
    Nodo* temp = head;
    int contador = 0;
    while (temp != nullptr) {
        if (contador == i) {
            cout << "El valor en el índice " << i << " es " << temp->dato << endl;
            return;
        }
        temp = temp->siguiente;
        contador++;
    }
    cout << "La posición " << i << " no existe en la lista actual." << endl;
}

void insertar(int i, int v) {
    if (i == 0) {
        insertarNodoInicio(v);
        return;
    }
    Nodo* nuevoNodo = new Nodo(v);
    Nodo* temp = head;
    for (int j = 0; j < i - 1 && temp != nullptr; ++j) {
        temp = temp->siguiente;
    }
    if (temp == nullptr) {
        cout << "No se puede insertar el nodo en la posición " << i << "." << endl;
        delete nuevoNodo;
    } else {
        nuevoNodo->siguiente = temp->siguiente;
        temp->siguiente = nuevoNodo;
    }
}

void buscar(int v) {
    Nodo* temp = head;
    int index = 0;
    bool found = false;
    while (temp != nullptr) {
        if (temp->dato == v) {
            cout << index << " ";
            found = true;
        }
        temp = temp->siguiente;
        index++;
    }
    if (!found) {
        cout << "No se encontró el valor " << v << " en la lista.";
    }
    cout << endl;
}

void Eliminar(int i) {
    if (head == nullptr) return;
    if (i == 0) {
        borrarNodoInicio();
        return;
    }
    Nodo* temp = head;
    for (int j = 0; j < i - 1 && temp->siguiente != nullptr; ++j) {
        temp = temp->siguiente;
    }
    if (temp->siguiente == nullptr) {
        cout << "La posición " << i << " no existe en la lista actual." << endl;
    } else {
        Nodo* aEliminar = temp->siguiente;
        temp->siguiente = temp->siguiente->siguiente;
        delete aEliminar;
    }
}


};
int main() {
    ListaLigada lista;

    // Insertando nodos al inicio y al final
    lista.insertarNodoFinal(5); // Ahora: 5
    lista.insertarNodoInicio(6); // Ahora: 6 -> 5
    lista.insertarNodoFinal(4); // Ahora: 6 -> 5 -> 4
    lista.insertarNodoInicio(7); // Ahora: 7 -> 6 -> 5 -> 4

    // Impresión de la lista
    cout << "Lista inicial: ";
    lista.imprimirLista();

    // Usando obtener(i)
    lista.obtener(2); // Debería mostrar el valor en el índice 2, que es 5
    lista.obtener(4); // Esta posición no existe, debería indicar que no existe

    // Usando insertar(i, v)
    lista.insertar(2, 10); // Inserta 10 en la posición 2, lista: 7 -> 6 -> 10 -> 5 -> 4
    cout << "Lista después de insertar 10 en índice 2: ";
    lista.imprimirLista();

    lista.insertar(0, 8); // Inserta al inicio, lista: 8 -> 7 -> 6 -> 10 -> 5 -> 4
    cout << "Lista después de insertar 8 en inicio: ";
    lista.imprimirLista();

    // Usando buscar(v)
    lista.buscar(10); // Debería encontrar el índice de 10
    lista.buscar(3); // Debería indicar que no se encuentra

    // Usando Eliminar(i)
    lista.Eliminar(0); // Elimina el primer elemento, lista: 7 -> 6 -> 10 -> 5 -> 4
    cout << "Lista después de eliminar el nodo en el índice 0: ";
    lista.imprimirLista();

    lista.Eliminar(3); // Elimina el elemento en el índice 3, lista: 7 -> 6 -> 10 -> 4
    cout << "Lista después de eliminar el nodo en el índice 3: ";
    lista.imprimirLista();

    // Intento de eliminar un índice fuera de los límites
    lista.Eliminar(10);

    return 0;
}