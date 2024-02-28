/*
Dada la siguiente serie 1,7,3,5,4,2,0,6,8,9, imprima su secuencia en un arreglo, agregando un elemento a imprimir, mediante un ciclo, de la siguiente manera:

Declare un vector de enteros
Crear una funcion llamada agrega() para ir agregando en orden secuencial cada elemento del arreglo.
En la función arreglo imprima el vector cada vez que un nuevo elemento es agregado.
El vector debe ser declarado globalmente.
Considere que parametros va usar su función y explique el porque.
La salida de la corrida es como se muestra abajo.
Si va a ordenar el vector, explique que haría de la manera más sencilla posible.
1 ,
1 , 7 ,
1 , 7 , 3 ,
1 , 7 , 3 , 5 ,
1 , 7 , 3 , 5 , 4 ,
1 , 7 , 3 , 5 , 4 , 2 ,
1 , 7 , 3 , 5 , 4 , 2 , 0 ,
1 , 7 , 3 , 5 , 4 , 2 , 0 , 6 ,
1 , 7 , 3 , 5 , 4 , 2 , 0 , 6 , 8 ,
1 , 7 , 3 , 5 , 4 , 2 , 0 , 6 , 8 , 9 ,
*/
#include <vector>
#include <iostream>
using namespace std;

//Variables Globales
vector<int> v1; //Se declara vector de enteros
int arr[] = {1,7,3,5,4,2,0,6,8,9};
int arraySize = sizeof(arr) / sizeof(arr[0]); // Se encuentra el tamaño del array

//Declaracion Funcion
void agrega(int);

int main (){
    for (int i = 0; i < arraySize; i++) {
        agrega(arr[i]);
        cout << endl;
    }
}

//Definicion Agrega
void agrega(int val) {
    v1.push_back(val);
    for (int i = 0; i < v1.size(); i++) {
        if (i != 0)
            cout << " , ";
        cout << v1[i];
    }
}
