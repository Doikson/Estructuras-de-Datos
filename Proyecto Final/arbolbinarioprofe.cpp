// Tree binary search:
// Falta tema ordenaciones o sorts

//Se crea el puntero raiz nulo
auto raiz = nullptr;


#include <iostream>
using namespace std;

class Nodo
{
public:
    int dato;
    Nodo* izq;
    Nodo* der;


public:
    Nodo(int dato)
    {
        this->dato = dato;
        this->der = nullptr; //El profesor usa NULL en vez de nullptr
        this->izq = nullptr;
    };

    void insertarNodo(int dato)
    {
        // Crear nuevo nodo
        Nodo* nodo= new Nodo(dato);
      
    
    if (raiz==nullptr)
    {
        raiz = nodo;
    }
    else
    {
        Nodo*temp = raiz;
        Nodo* padre;
        while (true)
        {
            padre = temp;
            if (dato<temp->dato)
            {
                temp = temp->izq;
                if (temp == nullptr)
                {
                    padre->izq=nodo;
                }
                
            }
        }

    };
    };
};

class Arbol
{
public:
    Nodo*raiz;
public:
    Arbol()
    {
        raiz = nullptr;
    };
};

int main (){

    Arbol arbol;


}