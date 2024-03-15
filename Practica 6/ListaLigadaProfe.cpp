#include <iostream>
using namespace std;
class Nodo
{
public:
	int dato;
	Nodo* siguiente;
	Nodo()
	{
		dato = 0;
		siguiente = NULL;
	}
	Nodo(int dato)
	{
		this->dato = dato;
		this->siguiente = NULL;
	}
};
class ListaL
{
public:
	Nodo* head;
	// Constructor
public:
	ListaL()
	{
		cout << "Constructor de LL" << endl;
		head = NULL;
	}
void insertaNodo(int dato)
{
    
    // Crear un nuevo nodo
    Nodo* nuevoNodo = new Nodo(dato);
    // Checar si la lista esta vacia
    if (head == NULL)
    {
        head = nuevoNodo;
        cout << "Valor de head inserta nodo inicial -->" 
            << nuevoNodo->dato << endl;
        cout << "Valor de la direccion head " << head << endl;
        return;
    }

    // viajar sobre la lista
    Nodo* temp = head;
    cout << "Valor de la direccion temp " << temp << endl;
    int i = 1;
    cout << "Valor de la direccion temp->siguiente " << temp->siguiente << endl;
    while (temp->siguiente != NULL)
    {
        
        temp = temp->siguiente;
        i = i + 1;
    }
    cout << "Valor de head inserta un nodo pos("<< i+1 << ") --> " << nuevoNodo->dato << endl;
    temp->siguiente = nuevoNodo;
    cout << "Valor de la direccion temp->siguiente " << temp->siguiente << endl;
}
	void insertaNodoInicio(int dato) 
	{
		Nodo* nuevoNodo = new Nodo(dato);
		if (head == NULL) 
		{
			head = nuevoNodo;
			return;
		}
		Nodo* temp = head;
		head = nuevoNodo;
		nuevoNodo->siguiente = temp;
	}
	void imprimeLista()
	{
		Nodo* temp = head;

		if (head == NULL)
		{
			cout << "Lista Vacia no se puede imprimir nada" << endl;
			return;
		}

		while (temp != NULL)
		{
			cout << temp->dato << " , ";
			temp = temp->siguiente;
		}
		cout << endl;
	}

 void eliminaNodo(int nodoaBorrar)
 {
     Nodo* temp0 = head;
     Nodo* temp1 = NULL;
     int contador = 0;

     if (temp0 == NULL)
     {
         cout << "Lista vacía no se puede eliminar nada" << endl;
         return;
     }
     else
     {
         while (temp0 != NULL)
         {

             temp0 = temp0->siguiente;
             contador++;
         }
         cout << "contador " << contador << endl;
         if (contador > nodoaBorrar)
         {

             temp0 = head;
             temp1 = NULL;

             if (nodoaBorrar == 1)
             {
                 // Borrar el primer elemento
                 head = head->siguiente;
                 delete temp0;
                 return;
             }
             cout << "Valor nodoaBorrar " << nodoaBorrar << endl;
             while (nodoaBorrar > 1)
             {
                 temp1 = temp0;
                 temp0 = temp0->siguiente;
                 nodoaBorrar--;
                 cout << "Valor nodoaBorrar " << nodoaBorrar << endl;
             }

             cout << nodoaBorrar << endl;
             cout << "temp0 datos " << temp0->dato << endl;
             cout << "temp1 datos " << temp1->dato << endl;
             cout << "temp0 datos siguiente " << temp0->siguiente->dato << endl;
             temp1->siguiente = temp0->siguiente;
             cout << "temp1 datos " << temp1->siguiente->dato << endl;
             cout << "temp0 datos " << temp0->dato << endl;
             delete temp0;

         }
     }
 }
	
		
};
int main()
{
ListaL lista;
lista.insertaNodo(5);
lista.insertaNodo(4);
lista.insertaNodo(3);
lista.insertaNodo(2);
lista.insertaNodo(1);
lista.imprimeLista();
lista.eliminaNodo(3);
lista.imprimeLista();
}