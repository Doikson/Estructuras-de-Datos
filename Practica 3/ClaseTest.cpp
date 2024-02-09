#include <iostream>
#include <vector>
using namespace std;
// globales
vector <struct Alumno> v1;
int num_materias;
struct Materias
{
    string materia;
    double calificacion;
};
struct Alumno 
{
    string nombre;
    string ap;
    string am;
    int cuenta;
    int nmaterias;
    vector <Materias> v2;

    static void altaAlumno(Alumno &alumno) 
    {
        Materias mat;
        cout << "Nombre : ";
        cin >> alumno.nombre;
        cout << endl;
        cout << "AP : ";
        cin >> alumno.ap;
        cout << endl;
        cout << "AM : ";
        cin >> alumno.am;
        cout << endl;
        cout << "Cuente : ";
        cin >> alumno.cuenta;
        cout << endl;
        cout << "Cuantas materias : ";
        cin >> alumno.nmaterias;
        cout << endl;
        for (int i = 0; i <= alumno.nmaterias-1; i++) 
        {
            cout << "Dame la materia que cursas : " << endl;
            cin >> mat.materia;
            cout << "Dame la calificacion obtenida : " << endl;
            cin >> mat.calificacion;
            alumno.v2.push_back(mat);
        }
        v1.push_back(alumno);
        
    }

    static void imprimeDatos(vector<Alumno> va)
    {
        int anterior=0,actual=0;
        for (int i = 0; i <= va.size() - 1; i++)
        {
            cout << "========================================================" << endl;
            cout << "Nombre del alumno : " << va[i].nombre << endl;
            cout << "Apellido Paterno : " << va[i].ap << endl;
            cout << "Apellido Materno : " << va[i].am << endl;
            cout << "No de cuenta : " << va[i].cuenta << endl;
            actual = va[i].nmaterias;
            //cout << "**** Actual : " << actual << endl;
            for (auto j=0; j <= va[i].nmaterias-1; ++j)
            {
                cout << endl;
                cout << "Nombre del alumno : " << va[i].nombre << endl;
                cout << "Materia  : " << va[i].v2[j].materia << endl;
                cout << "Calificacion : " << va[i].v2[j].calificacion << endl;
                cout << endl;
            }
            anterior = anterior+actual;
            //cout << "Anterior : " << anterior << endl;
            cout << "========================================================" << endl;
        }
    }
};



int main()
{
    Alumno temp;
    int num_alumnos;
    cout << "Numero de alumnos : ";
    cin >> num_alumnos;
    cout << endl;
    for (int i = 0; i <= num_alumnos - 1; i++) 
    {
        Alumno::altaAlumno(temp);
    }
    Alumno::imprimeDatos(v1);
    cout << "Tamano del vector :" << v1.size() << endl;
}