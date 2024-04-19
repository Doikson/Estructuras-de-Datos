//ArbolBinario Contar 
#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* izq;
    Nodo* der;

public:
    Nodo(int valor) {
        dato = valor;
        der = NULL;
        izq = NULL;
    }
};

class Arbol {
public:
    Nodo* raiz;

public:
    Arbol() {
        raiz = NULL;
    }

    void insertarNodo(int valor) {
        Nodo* nodo = new Nodo(valor);
        if (raiz == NULL) {
            raiz = nodo;
        } else {
            Nodo* temp = raiz;
            while (true) {
                if (valor < temp->dato) {
                    if (temp->izq == NULL) {
                        temp->izq = nodo;
                        break;
                    }
                    temp = temp->izq;
                } else {
                    if (temp->der == NULL) {
                        temp->der = nodo;
                        break;
                    }
                    temp = temp->der;
                }
            }
        }
    }

    void preOrden(Nodo* temp) {
        if (temp == NULL) {
            return;
        }
        cout << temp->dato << " ";
        preOrden(temp->izq);
        preOrden(temp->der);
    }

    void enOrden(Nodo* temp) {
        if (temp == NULL) {
            return;
        }
        enOrden(temp->izq);
        cout << temp->dato << " ";
        enOrden(temp->der);
    }

    void postOrden(Nodo* temp) {
        if (temp == NULL) {
            return;
        }
        postOrden(temp->izq);
        postOrden(temp->der);
        cout << temp->dato << " ";
    }

    void borrarNodo(int valor) {
        Nodo* temp = raiz;
        Nodo* padre = NULL;
        bool izquierda = true;

        while (temp != NULL && temp->dato != valor) {
            padre = temp;
            if (valor < temp->dato) {
                izquierda = true;
                temp = temp->izq;
            } else {
                izquierda = false;
                temp = temp->der;
            }
        }

        if (temp == NULL) {
            return;
        }

        if (temp->izq == NULL && temp->der == NULL) {
            if (temp == raiz) {
                raiz = NULL;
            } else if (izquierda) {
                padre->izq = NULL;
            } else {
                padre->der = NULL;
            }
            delete temp;
        } else if (temp->izq == NULL) {
            Nodo* aux = temp;
            if (temp == raiz) {
                raiz = temp->der;
            } else if (izquierda) {
                padre->izq = temp->der;
            } else {
                padre->der = temp->der;
            }
            delete aux;
        } else if (temp->der == NULL) {
            Nodo* aux = temp;
            if (temp == raiz) {
                raiz = temp->izq;
            } else if (izquierda) {
                padre->izq = temp->izq;
            } else {
                padre->der = temp->izq;
            }
            delete aux;
        } else {
            Nodo* sucesor = obtenSucesor(temp);
            if (temp == raiz) {
                raiz = sucesor;
            } else if (izquierda) {
                padre->izq = sucesor;
            } else {
                padre->der = sucesor;
            }
            sucesor->izq = temp->izq;
            delete temp;
        }
    }

    Nodo* obtenSucesor(Nodo* nodo) {
        Nodo* sucesorPadre = nodo;
        Nodo* sucesor = nodo;
        Nodo* actual = nodo->der;

        while (actual != NULL) {
            sucesorPadre = sucesor;
            sucesor = actual;
            actual = actual->izq;
        }

        if (sucesor != nodo->der) {
            sucesorPadre->izq = sucesor->der;
            sucesor->der = nodo->der;
        }

        return sucesor;
    }

    int contarNodos(Nodo* temp) {
        if (temp == NULL) {
            return 0;
        }

        return 1 + contarNodos(temp->izq) + contarNodos(temp->der);
    }
};

int main() {
    Arbol arbol;

    int valores[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for (size_t i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        arbol.insertarNodo(valores[i]);
    }

    cout << "Recorrido en preorden: ";
    arbol.preOrden(arbol.raiz);
    cout << endl;

    cout << "Recorrido en orden: ";
    arbol.enOrden(arbol.raiz);
    cout << endl;

    cout << "Recorrido en postorden: ";
    arbol.postOrden(arbol.raiz);
    cout << endl;

    cout << "Número de nodos en el árbol: " << arbol.contarNodos(arbol.raiz) << endl;

    cout << "Eliminando nodo con valor 6..." << endl;
    arbol.borrarNodo(6);

    cout << "Recorrido en orden después de borrar el nodo 6: ";
    arbol.enOrden(arbol.raiz);
    cout << endl;

    cout << "Número de nodos en el árbol después de borrar un nodo: " << arbol.contarNodos(arbol.raiz) << endl;

    return 0;
}
