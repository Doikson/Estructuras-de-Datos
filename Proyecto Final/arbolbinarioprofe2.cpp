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
        this->der = NULL;
        this->izq = NULL;
    }
};

class Arbol 
{
public:
    Nodo* raiz;
public:
    Arbol() 
    {
        raiz = NULL;
    }
    void insertadoNodo(int dato) 
    {
        // Crear nuevo nodo
        Nodo* nodo = new Nodo(dato);
        if (raiz == NULL) 
        {
            raiz = nodo;
        }
        else 
        {
            Nodo* temp = raiz;
            Nodo* padre;
            while (true) 
            {
                padre = temp;
                if (dato < temp->dato) 
                {
                    temp = temp->izq;
                    if (temp == NULL) 
                    {
                        padre->izq = nodo;
                        break;
                    }
                }
                else 
                {
                    if (dato > temp->dato) 
                    {
                        temp = temp->der;
                        if (temp == NULL) 
                        {
                            padre->der = nodo;
                            break;
                        }
                    }
                }
            }
        }
    }

    void enOrden(Nodo* temp) 
    {
        if (temp == NULL) 
        {
            return;
        }
        enOrden(temp->izq);
        cout << temp->dato << " , ";
        enOrden(temp->der);
    }
};

int main()
{
    Arbol arbol;
    int valores[] = { 8,3,10,1,6,14,4,7,13 };
    for (int i = 0; i <= 8; i++) 
    {
        arbol.insertadoNodo(valores[i]);
    }
    arbol.enOrden(arbol.raiz);
}

 void borrarNodo(int dato) 
    {
        Nodo* temp=NULL;
        Nodo* padre=NULL;
        bool bizq = true;

        // Encontrar el nodo a borrar 
        temp = raiz;
        while (temp->dato != dato)
        {
            padre = temp;
            if (dato < temp->dato)
            {
                bizq = true;
                temp = temp->izq;

            }
            else
            {
                bizq = false;
                temp = temp->der;
            }
            if (temp == NULL) 
            {
                return;
            }
        }

        // Si el nodo no tiene hijos
        if (temp->izq == NULL && temp->der == NULL) 
        {
            if (temp == raiz)
                raiz = NULL;
            else if (bizq)
                padre->izq = NULL;
            else
                padre->der = NULL;
        }
        else {
            // Nodo a borrar tiene un hijo
            if (temp->der == NULL)
            {
                if (temp == raiz)
                    raiz = temp->izq;
                else if (bizq)
                    padre->izq = temp->izq;
                else
                    padre->der = temp->izq;
            }
            else if (temp->izq == NULL)
            {
                if (temp == raiz)
                    raiz = temp->der;
                else if (bizq)
                    padre->izq = temp->der;
                else
                    padre->der = temp->der;
            }

            // El nodo seleccionado tiene dos hijos 
            else
            {
                Nodo* sucesor = obtenSucesor(temp);

                if (temp == raiz)
                    raiz = sucesor;
                else if (bizq)
                    padre->izq = sucesor;
                else
                    padre->der = sucesor;

                sucesor->izq = temp->izq;
            }

            delete temp;

        }

        // Nodo a borrar tiene un hijo


    }