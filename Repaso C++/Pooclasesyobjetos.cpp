#include <iostream>

using namespace std;

class Persona { //Crea la clase Persona 
    private: // Aqui se establecen los atributos o caracteristicas de la clase (solo se pueden modificar por los metodos)
    int edad;
    string nombre;
    public: //Aqui van los metodos (Las acciones del objeto, el cual en este caso es persona)
    Persona(int,string); // Este es el constructor de la clase, se insertan los tipos de datos (en este caso int y string)
    void leer ();
    void correr ();
};

Persona::Persona(int _edad,string _nombre){ // Constructor, inicia los atributos y se le asigna una variable diferente a los metodos para diferenciarlos
    edad = _edad;
    nombre = _nombre;
}

void Persona::leer(){ //se declara lo que hace la accion (o metodo) leer
    cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
}

void Persona::correr(){ //se declara lo que hace la accion (o metodo) correr
    cout<<"Soy "<<nombre<<" y estoy corriendo una maraton"<<" y tengo "<<edad<< " anios" <<endl;
}

int main() {
Persona p1 = Persona(20,"Alejandro"); //Se declaran los objetos
Persona p2 = Persona(16,"Maria");
Persona p3 = Persona(69,"Juanito");
p1.leer();
p1.correr();
p2.correr();
p2.leer();
p3.leer();

    return 0;
}
