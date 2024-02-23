#include <iostream>
#include <vector>
#include <cstdlib>  // Incluir la biblioteca para usar rand()
using namespace std;


//Declaracion Funciones
string randomStr (int len);

//Class materiales
class Materiales{

private:
    string id;
    string titulo;
    string genero;
    string tipo;
    double duracion;
    int region;
    vector<string> actor;
    vector<string> director;
    int inventario;
    bool referencia;

public:

    void altaMaterial()
    {
        cout << "Ingrese el ID: "; cin >> Materiales.id;

    }


};


int main (){

//main code

}

//Definicion Funcion randomString
string randomStr(int len) 
{
    string str;
    for (int i = 0; i < len; i++) // Corregir la condición del bucle para evitar exceder la longitud
    {
        char ch = 'A' + rand() % 26;
        str.push_back(ch);
    }
    return str; // Devolver la cadena generada
}