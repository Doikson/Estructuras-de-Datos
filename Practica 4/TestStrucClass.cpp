#include <iostream>
using namespace std;

struct miEstructura
{
    int numero = 5;
};

class MiClase //Empieza con mayuscula Siempre
{
    public: //Se esta forzando a que sea publico
    int numero = 10;
};

int main (){

    //Crea una instancia de Estructura
    miEstructura miInstanciaEstructura; //Elementos Publicos por defecto

    //Crea instancia de Clase
    MiClase miInstanciaClase; //Elementos Privados por defecto

    //Operacion de Asingacion
    int i = miInstanciaEstructura.numero;
    cout << i << endl;

    //Esto no se puede porque numero es inaccesible a menos que se fuerze (como es el caso)
    int j = miInstanciaClase.numero;
    cout << j << endl;
}