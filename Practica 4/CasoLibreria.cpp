#include <iostream>
#include <vector>
#include <cstdlib>  // Incluir la biblioteca para usar rand()
using namespace std;

// Declaración de la clase Usuario
class Usuario {
public:
    string matricula;
    string nombre;
    string apellidos;
    struct Direccion {
        string calle;
        int numero;
        string numeroInterno;
        string fraccionamiento;
        string municipio;
        string pais;
    } direccion;
    string telefono;
    int diasPrestamo;
    string tipo;
    string idMaterial;
    string prestamoVencido; // Se cambió a string para aceptar valores "Si" o "No"

    bool tieneAdeudo() {
        // Implementar la función para verificar si el usuario tiene adeudo
        // Esto se puede hacer revisando si el atributo prestamoVencido está marcado como "Si"
        return (prestamoVencido == "Si");
    }
};

// Definición de la clase Materiales
class Materiales {
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
    vector<string> categorias; // Vector para almacenar las categorías de materiales

public:
    void altaMaterial(string categoria) {
        // Implementación de la función para dar de alta un material
        categorias.push_back(categoria);
    }

    // Métodos para gestionar el préstamo de materiales
    void prestarMaterial(Usuario &usuario, string categoria) {
        // Implementación del préstamo de material
        // Verificar el tipo de material y establecer la duración del préstamo
        if (!usuario.tieneAdeudo()) {
            // Realizar el préstamo
            // Aquí puedes agregar la lógica para gestionar el préstamo de acuerdo a la categoría
        } else {
            cout << "No se puede realizar el préstamo porque el usuario tiene un adeudo pendiente." << endl;
        }
    }

    void devolverMaterial(Usuario &usuario, int diasExcedidos) {
        // Implementación de la devolución de material y cálculo del cargo por días excedidos
        if (diasExcedidos > 0) {
            // Calcular el cargo por días excedidos y mostrarlo al usuario
            double cargo = diasExcedidos * 10; // Cargo de 10 pesos por día excedido
            cout << "Se debe pagar un cargo de $" << cargo << " por los días excedidos." << endl;
            // Después de pagar el cargo, actualizar el estado del usuario y quitar el adeudo
            // usuario.prestamoVencido = "No";
        } else {
            cout << "No se generó cargo por días excedidos." << endl;
        }
    }

    void registrarUsoPorCategoria(string categoria) {
        // Implementación para registrar el uso de materiales por categoría
        // Aquí puedes agregar la lógica para registrar el uso por categoría en el vector de categorías
    }
};

// Función main
int main() {
    vector<Usuario> usuarios;
    vector<Materiales> materiales;

    int opcion;
    do {
        cout << "=== MENU ===" << endl;
        cout << "1. Registrar nuevo usuario" << endl;
        cout << "2. Dar de alta un nuevo material" << endl;
        cout << "3. Realizar un préstamo" << endl;
        cout << "4. Devolver un material" << endl;
        cout << "5. Mostrar información sobre un material" << endl;
        cout << "6. Mostrar información sobre un usuario" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Llamar a la función para registrar un nuevo usuario
                break;
            case 2:
                // Llamar a la función para dar de alta un nuevo material
                break;
            case 3:
                // Llamar a la función para realizar un préstamo
                break;
            case 4:
                // Llamar a la función para devolver un material
                break;
            case 5:
                // Llamar a la función para mostrar información sobre un material
                break;
            case 6:
                // Llamar a la función para mostrar información sobre un usuario
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 7);

    return 0;
}
