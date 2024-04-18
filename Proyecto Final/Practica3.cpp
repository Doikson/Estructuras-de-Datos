#include <iostream>
#include <string>
using namespace std;

class Alumno {
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    int numeroCuenta;
    bool estatusAlumno;
    int materiasCursadas;
    int materiasActuales;
    int materiasPorCursar;

public:
    // Constructor que alimenta los datos iniciales del alumno
    Alumno(string nombre, string apellidoPaterno, string apellidoMaterno, int numeroCuenta, bool estatusAlumno, int materiasCursadas, int materiasActuales, int materiasPorCursar) {
        this->nombre = nombre;
        this->apellidoPaterno = apellidoPaterno;
        this->apellidoMaterno = apellidoMaterno;
        this->numeroCuenta = numeroCuenta;
        this->estatusAlumno = estatusAlumno;
        this->materiasCursadas = materiasCursadas;
        this->materiasActuales = (estatusAlumno) ? materiasActuales : 0; // Si el estatus es baja, materias actuales es 0
        this->materiasPorCursar = materiasPorCursar;
    }

    // Destructor de la clase
    ~Alumno() {
        cout << "Se destruyó el objeto Alumno." << endl;
    }

    // Métodos para establecer los atributos de manera individual
    void estableceDatosGenerales(string nombre, string apellidoPaterno, string apellidoMaterno, int numeroCuenta, bool estatusAlumno) {
        this->nombre = nombre;
        this->apellidoPaterno = apellidoPaterno;
        this->apellidoMaterno = apellidoMaterno;
        this->numeroCuenta = numeroCuenta;
        this->estatusAlumno = estatusAlumno;
    }

    void estableceMateriasCursadas(int campoMateriasCursadas) {
        materiasCursadas = campoMateriasCursadas;
    }

    void estableceMateriasActuales(int campoMateriasActuales) {
        materiasActuales = (estatusAlumno) ? campoMateriasActuales : 0; // Si el estatus es baja, materias actuales es 0
    }

    void estableceMateriasPorCursar(int campoMateriasPorCursar) {
        materiasPorCursar = campoMateriasPorCursar;
    }

    // Métodos para obtener el valor de los atributos
    string obtenDatosGenerales() {
        return nombre + " " + apellidoPaterno + " " + apellidoMaterno + ", No. de cuenta: " + to_string(numeroCuenta) + ", Estatus: " + ((estatusAlumno) ? "Activo" : "Baja");
    }

    int obtenMateriasCursadas() {
        return materiasCursadas;
    }

    int obtenMateriasActuales() {
        return materiasActuales;
    }

    int obtenMateriasPorCursar() {
        return materiasPorCursar;
    }

    // Método para imprimir los datos del alumno
    void imprimirDatos() {
        cout << "Datos del alumno:" << endl;
        cout << "Nombre completo: " << obtenDatosGenerales() << endl;
        cout << "Materias cursadas: " << obtenMateriasCursadas() << endl;
        cout << "Materias actuales: " << obtenMateriasActuales() << endl;
        cout << "Materias por cursar: " << obtenMateriasPorCursar() << endl;
    }
};

int main() {
    Alumno alumno1("Juan", "Perez", "Garcia", 12345, true, 10, 5, 7);
    Alumno alumno2("Maria", "Lopez", "Hernandez", 54321, false, 15, 0, 5);

    alumno1.imprimirDatos();
    cout << endl;
    alumno2.imprimirDatos();

    return 0;
}
