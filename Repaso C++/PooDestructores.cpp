#include <iostream>
using namespace std;

class Perro{
    private:
    string nombre, raza;
    int edad;
    public:
    Perro(string, string, int); // Constructor
    ~Perro(); // Destructor
    void mostrarDatos();
    void jugar();
};

// Constructor
Perro::Perro(string _nombre, string _raza, int _edad)
    : nombre(_nombre), raza(_raza), edad(_edad)
{
}

// Destructor
Perro::~Perro(){
}

void Perro::mostrarDatos(){
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "Edad: " << edad << endl;
}

void Perro::jugar(){
    cout << "El Perro " << nombre << " está jugando" << endl;
}

int main (){
    Perro perro1("Fido", "Doberman", 10);
    perro1.mostrarDatos();
    perro1.jugar();
    perro1.~Perro(); //Destruye el objeto
//Destruir un objeto sirve principalmente para liberar memoria 
    return 0;
}
