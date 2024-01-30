#include <iostream> //for loop: Es un bucle que se utiliza cuando se conoce de antemano el número de veces que se desea repetir un bloque de código.
using namespace std;

int main()
{
    int i; //declara una variable con un valor integral (o de numeros) llamada i
    for(i = 0; i < 20; i ++) // establece un bucle que se ejecuta 20 veces donde la variable i empieza en 0 y se le suma 1 hasta el 20
    {
        if(i % 2 == 0) // if que determina si la variable i es un numero par (se divide entre 2 y si es igual a 0 significa que es par)
        {
            cout << i << endl;
        }
    }
    return 0;
}