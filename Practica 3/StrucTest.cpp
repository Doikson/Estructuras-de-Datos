#include <iostream>
using namespace std;

// estructuras o clases
struct Alumno 
{
    string nombre;
    string ap;
    string am;
    int cuenta;

    //Se crea una funcion para ingresar los datos
    static void altaAlumno (Alumno &alumno) //Se le agrega un amperzon para que modifique la direccion de memoria directamente
    {
        cout << "Ingresa los datos del Alumno" << endl;
        cout << "Nombre: "; cin>>alumno.nombre;
        cout << "Apellido Paterno: "; cin>>alumno.ap;
        cout << "Apellido Materno: "; cin>>alumno.am;
        cout << "Num Cuenta: "; cin>>alumno.cuenta;
    }

    //Se crea una funcion para ingresar los datos
    static void imprimeDatos(Alumno alumno) 
    {
        cout << "Nombre : " << alumno.nombre << endl;
        cout << "AP : " << alumno.ap << endl;
        cout << "AM : " << alumno.am << endl;
        cout << "Cuenta : " << alumno.cuenta << endl;
    }
};

int main()
{

Alumno jose;
jose.altaAlumno(jose);
jose.imprimeDatos(jose);

//Se puede reescribir de la sig manera agregando un static a las funciones
Alumno pepe;
Alumno::altaAlumno(pepe);
Alumno:: imprimeDatos(pepe);

}