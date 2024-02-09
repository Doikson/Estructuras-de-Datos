#include <iostream>
#include <vector>
using namespace std;

//Variables Globales
int numMaterias;
int numAlumnos;

// Declaración de la estructura Materias
struct Materias {
    string materia;
    double calificacion;
};

// Declaración de la estructura Alumno
struct Alumno {
    string nombre;
    string ap;
    string am;
    int cuenta;
    vector<Materias> v2; // Vector de Materias

    // Método estático para ingresar datos del alumno
    static void altaAlumno(Alumno &alumno);

    // Método estático para imprimir datos del alumno
    static void imprimeDatos(const Alumno &alumno);
};

// Definición de altaAlumno
void Alumno::altaAlumno(Alumno &alumno) {
    cout << "Nombre alumno : ";
    cin >> alumno.nombre;
    cout << endl;
    cout << "Apellido Paterno : ";
    cin >> alumno.ap;
    cout << endl;
    cout << "Apellido Materno : ";
    cin >> alumno.am;
    cout << endl;
    cout << "Cuenta : ";
    cin >> alumno.cuenta;
    cout << endl;
    // Ingresar materias y calificaciones
    cout << "Número de materias: ";
    cin >> numMaterias; // Se utiliza la variable global
    for (int i = 0; i < numMaterias; ++i) {
        Materias materia;
        cout << "Materia " << i + 1 << ": ";
        cin >> materia.materia;
        cout << "Calificación " << i + 1 << ": ";
        cin >> materia.calificacion;
        alumno.v2.push_back(materia);
    }
}

// Definición de imprimeDatos
void Alumno::imprimeDatos(const Alumno &alumno) {
    cout << "Nombre : " << alumno.nombre << endl;
    cout << "Apellido Paterno : " << alumno.ap << endl;
    cout << "Apellito Materno : " << alumno.am << endl;
    cout << "Cuenta : " << alumno.cuenta << endl;
    cout << "Materias y calificaciones: " << endl;
    for (const auto &materia : alumno.v2) {
        cout << "  - " << materia.materia << ": " << materia.calificacion << endl;
    }
}

// Declaración de las funciones
void agregarAlumno(vector<Alumno> &alumnos);
void imprimirAlumnos(const vector<Alumno> &alumnos);

int main() {
    vector<Alumno> v1;

    cout << "Número de alumnos: ";
    cin >> numAlumnos;

    for (int i = 0; i < numAlumnos; ++i) {
        agregarAlumno(v1);
    }

    imprimirAlumnos(v1);

    return 0;
}

// Definición de la función agregarAlumno
void agregarAlumno(vector<Alumno> &alumnos) {
    Alumno alumno;
    Alumno::altaAlumno(alumno);
    alumnos.push_back(alumno);
}

// Definición de la función imprimirAlumnos
void imprimirAlumnos(const vector<Alumno> &alumnos) {
    for (const auto &alumno : alumnos) {
        Alumno::imprimeDatos(alumno);
        cout << endl;
    }
}