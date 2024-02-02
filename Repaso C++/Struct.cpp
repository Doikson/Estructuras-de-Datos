#include <iostream>
using namespace std;

struct persona { //Crea la estructura persona y agrega los objetos pertenecientes a esta
    string nombre;
    int edad;
    bool hace_programacion;
};
int main (void){
persona p1;     // Declara los objetos p1 y p2 con la estructura persona
persona p2;
// Declaro los valores de p1
p1.nombre = "Alicia la Malandrona";
p1.edad = 20;
p1.hace_programacion = false;

//Declaro los valores de p2
p2.nombre = "Bob mi carnal";
p2.edad = 18;
p2.hace_programacion = true;

//Imprime los valores de p1 y p2
//cout << name << " (" << age << ")" << endl;
cout << "Persona 1: " << p1.nombre << "("<< p1.edad <<")" << p1.hace_programacion << endl;
cout << "Persona 2: " << p2.nombre << "("<< p2.edad <<")" << p2.hace_programacion << endl;

return 0;
}