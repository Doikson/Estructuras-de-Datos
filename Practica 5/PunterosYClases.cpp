#include <iostream>
using namespace std;

class Nodo
{
public:
    int dato;
    Nodo* siguiente;

    Nodo()
    {
        dato=0;
        siguiente = NULL;

    }

    Nodo(int dato)
    {
        this->dato = dato;
        this->siguiente = NULL;

    }

};

class ListaLigada
{
    public:
    Nodo* head;

    //Constructor
    ListaLigada()
    {
        cout << "Constructor de Lista Ligada" << endl;
        head = NULL;
    }

    //Funcion para insertar Nodos
    void insertarNodo(int dato)
    {
        //Crear Nodo
        Nodo* nuevoNodo = new Nodo(dato);

        //El primer Nodo no esta apuntando a ninguna parte 'head=Null';
        if (head == NULL) //Verifica si no se ha creado nada
        {
            head = nuevoNodo;

            return; //Este return se agrega no se porque (LOL)
        }
        //Crea un nuevo apuntador temporal y lo pone al inicio de la lista
        Nodo* temp = head;

        //Viajar sobre la lista
        while (temp->siguiente != NULL)
        {
            //Mientras no sea nulo mueve temp a la sig posicion
            temp = temp->siguiente;
        }

        cout << "Valor a Insertar: " << nuevoNodo->dato <<endl;
        temp->siguiente = nuevoNodo;
        
    }

    void imprimirLista()
    {
        Nodo* temp = head;
        if (head == NULL)
        {
            cout << "LISTA VACIA" << endl;
        }

        while (temp != NULL)
        {
            cout << temp->dato << " , " <<endl;
            temp = temp->siguiente;    
        }
    }

    // Método para contar cuántos nodos hay en la lista
    int contarNodos()
    {
        //Se crea la variable contador
        int contador = 0;
        Nodo* temp = head;
        
        while (temp != NULL)
        {
            contador++;
            temp = temp->siguiente;
        }
        
        return contador;
    }



};

int main (){

ListaLigada lista;

lista.insertarNodo(5);
lista.insertarNodo(4);
lista.insertarNodo(3);
lista.insertarNodo(2);
lista.insertarNodo(1);

lista.imprimirLista();

cout << "Numero de nodos en la lista: " << lista.contarNodos() << endl;


}