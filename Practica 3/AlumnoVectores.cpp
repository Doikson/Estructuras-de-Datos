#include <iostream>
#include <vector>
using namespace std;

//Variables Globales
int numAlumnos;
int numMaterias;

//Declaracion Funciones
void agregarAlumno(vector<Alumno> &alumnos);
void imprimirAlumnos(const vector<Alumno> &alumnos);

// Definición de la estructura Materias
struct Materias {
    string materia;
    double calificacion;
};

// Definición de la estructura Alumno
struct Alumno {
    string nombre;
    string ap;
    string am;
    int cuenta;
    vector<Materias> v2; // Vector de Materias

    // Método para ingresar datos del alumno
    static void altaAlumno(Alumno &alumno) {
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
        cin >> numMaterias;
        for (int i = 0; i < numMaterias; ++i) {
            Materias materia;
            cout << "Materia " << i + 1 << ": ";
            cin >> materia.materia;
            cout << "Calificación " << i + 1 << ": ";
            cin >> materia.calificacion;
            alumno.v2.push_back(materia);
        }
    }
    // Método para imprimir datos del alumno
    static void imprimeDatos(Alumno alumno) {
        cout << "Nombre : " << alumno.nombre << endl;
        cout << "AP : " << alumno.ap << endl;
        cout << "AM : " << alumno.am << endl;
        cout << "Cuenta : " << alumno.cuenta << endl;
        cout << "Materias y calificaciones: " << endl;
        for (const auto &materia : alumno.v2) {
            cout << "  - " << materia.materia << ": " << materia.calificacion << endl;
        }
    }
};

int main() {
    vector<Alumno> v1;
    int numAlumnos;

    cout << "Número de alumnos: ";
    cin >> numAlumnos;

    for (int i = 0; i < numAlumnos; ++i) {
        agregarAlumno(v1);
    }

    imprimirAlumnos(v1);

    return 0;
}
//Definicion imprimirAlumnos
void imprimirAlumnos(const vector<Alumno> &alumnos) {
    for (const auto &alumno : alumnos) {
        Alumno::imprimeDatos(alumno);
        cout << endl;
    }
}
//Definicion agregarAlumno
void agregarAlumno(vector<Alumno> &alumnos) {
    Alumno alumno;
    Alumno::altaAlumno(alumno);
    alumnos.push_back(alumno);
}