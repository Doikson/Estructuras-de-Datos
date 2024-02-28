#include <iostream>
#include <vector>
using namespace std;

//Variables Globales
int num_users;
int cuenta;
int totalMateriales=0;

struct Direccion {
    string calle;
    string numero;
    string numeroInterno;
    string colonia;
    string municipio;
    string pais;
};

class Materiales {
private:
    string id;
    string titulo;
    string genero;
    string tipo; //Pelicula, dvd , videojuego
    double duracion; 
    string region;
    vector <string> actor;
    vector <string> director;
    int inventario; //Cantidad en stock
    char referencia; //Solo puede ser prestado por 2hrs si es true

public:
    void ingresarDatosMaterial() {
        cout << "Ingrese el ID del material: " << endl;
        cin >> id;
        cout << "Ingrese el título del material: " << endl;
        cin >> titulo;
        cout << "Ingrese el género del material: " << endl;
        cin >> genero;
        cout << "Ingrese el tipo del material (Pelicula, dvd, videojuego): " << endl;
        cin >> tipo;
        cout << "Ingrese la duración del material: " << endl;
        cin >> duracion;
        cout << "Ingrese la región del material: " << endl;
        cin >> region;
        cout << "Ingrese el inventario del material: " << endl;
        cin >> inventario;
        cout << "¿Es una referencia? (S/N): " << endl;
        cin >> referencia;

          // Ingreso del número de actores
        int numActores;
        cout << "Ingrese el número de actores: ";
        cin >> numActores;
        for (int i = 0; i < numActores; ++i) {
            string nombreActor;
            cout << "Ingrese el nombre del actor " << i+1 << ": ";
            cin >> nombreActor;
            actor.push_back(nombreActor);
        }

        // Ingreso del número de directores
        int numDirectores;
        cout << "Ingrese el número de directores: ";
        cin >> numDirectores;
        for (int i = 0; i < numDirectores; ++i) {
            string nombreDirector;
            cout << "Ingrese el nombre del director " << i+1 << ": ";
            cin >> nombreDirector;
            director.push_back(nombreDirector);
        }
    }

    // Getters para los atributos
    string getId() const {
        return id;
    }

    string getTitulo() const {
        return titulo;
    }

    string getGenero() const {
        return genero;
    }

    string getTipo() const {
        return tipo;
    }

    double getDuracion() const {
        return duracion;
    }

    string getRegion() const {
        return region;
    }

    int getInventario() const {
        return inventario;
    }

    bool esReferencia() const {
        return referencia;
    }

        // Getter para obtener el vector de actores
    vector<string> getActores() const {
        return actor;
    }

    // Getter para obtener el vector de directores
    vector<string> getDirectores() const {
        return director;
    }
};

class Usuario {
private:
    string matricula;
    string nombre;
    string ap;
    Direccion dom;
    string telefono;
    int diasPrestamo;
    /*
    No veo necesario incluir el tipo de material en la clase Usuario
    (Con la idMaterial es suficiente para identificar que se presto)
    */
    string idMaterial;
    string prestamoVencido;

    public:
   // Método para ingresar los datos de un nuevo usuario
    void ingresarDatosUsuario() {
        cout << "Ingrese la matricula: ";
        cin >> matricula;
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> ap;
        cout << "Ingrese la calle: ";
        cin >> dom.calle;
        cout << "Ingrese el numero: ";
        cin >> dom.numero;
        cout << "Ingrese el numero interno: ";
        cin >> dom.numeroInterno;
        cout << "Ingrese la colonia: ";
        cin >> dom.colonia;
        cout << "Ingrese el municipio: ";
        cin >> dom.municipio;
        cout << "Ingrese el pais: ";
        cin >> dom.pais;
        cout << "Ingrese el telefono: ";
        cin >> telefono;
        cout << "Ingrese los dias de prestamo: ";
        cin >> diasPrestamo;
    }

    // Método para mostrar los datos de un usuario
    void mostrarDatosUsuario() {
        cout << "Matricula: " << matricula << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << ap << endl;
        cout << "Direccion: " << dom.calle << " " << dom.numero << ", " << dom.numeroInterno << ", " << dom.colonia << ", " << dom.municipio << ", " << dom.pais << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Dias de prestamo: " << diasPrestamo << endl;
    }
};


int main (){
    
    vector <Materiales> materiales;
    vector <Usuario> usuarios;


    int opcion;
    do {
        cout << "=== MENU ===" << endl;
        cout << "1. Dar de alta un nuevo material" << endl;
        cout << "2. Realizar un préstamo" << endl;
        cout << "3. Devolver un material" << endl;
        cout << "4. Mostrar información sobre un materiales" << endl;
        cout << "5. Mostrar información sobre un usuario" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
                Materiales nuevoMaterial; // Crear un nuevo objeto de tipo Materiales
                nuevoMaterial.ingresarDatosMaterial(); // Llamar al método para ingresar datos del material
                materiales.push_back(nuevoMaterial); // Agregar el material al vector de materiales
                totalMateriales = nuevoMaterial.getInventario() + totalMateriales;
                cout << "Material agregado correctamente." << endl;
                break;
                }
                
            case 2:
                //cout << "Llamar a la función para realizar un préstamo" << endl;
                break;
            case 3:
                //cout << "Llamar a la función para devolver un material" << endl;
                break;
            case 4:
                if (materiales.empty()) {
                    cout << "No hay materiales agregados." << endl;
                } else {
                    cout << "===  TOTAL MATERIALES AGREGADOS: "<< totalMateriales <<" ===" << endl;
                    cout << "=== LISTA MATERIALES ===" << endl;
                    for (size_t i = 0; i < materiales.size(); ++i) {
                        cout << "Material " << i+1 << ":" << endl;
                        cout << "ID: " << materiales[i].getId() << endl;
                        cout << "Título: " << materiales[i].getTitulo() << endl;
                        cout << "Género: " << materiales[i].getGenero() << endl;
                        cout << "Tipo: " << materiales[i].getTipo() << endl;
                        cout << "Duración: " << materiales[i].getDuracion() << endl;
                        cout << "Región: " << materiales[i].getRegion() << endl;
                        cout << "Inventario: " << materiales[i].getInventario() << endl;
                        cout << "Referencia: " << (materiales[i].esReferencia() ? "Sí" : "No") << endl;
                        cout << endl;

                        // Imprimir los nombres de los actores
                        cout << "Actores: ";
                        vector<string> actores = materiales[i].getActores();
                        for (const auto& actor : actores) {
                            cout << actor << ", ";
                        }
                        cout << endl;

                        // Imprimir los nombres de los directores
                        cout << "Directores: ";
                        vector<string> directores = materiales[i].getDirectores();
                        for (const auto& director : directores) {
                            cout << director << ", ";
                        }
                        cout << endl;
                                }
                            }
                break;
            case 5:
                //cout << "Llamar a la función para mostrar información sobre un usuario" << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);

}
