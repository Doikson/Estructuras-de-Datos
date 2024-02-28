/*
Escriba la definición de una clase productos que contenga la siguiente información:

(a)    Código del producto.
(b)    Descripción del producto
(c)    Inventario Inicial
(d)    Inventario Final

Escriba los miembros de función necesarios para que la clase trabaje adecuadamente.

Su código debe cumplir con los siguientes puntos:

Crear el constructor de la clase ✅
Crear los getters y setters de cada atributo de la clase. ✅
Crear un método que se llame venta() que substraiga el numero de unidades vendidas, considere un número aleatorio que no exceda el inventario, de lo contrario marcar error. Considere si debe usar un parametro por valor o por referencia, y explique el porque. ✅
Crear un métos que se llame almacenar() que adicione producto recibido de un proveedor, en este caso pregunte por la cantidad a iniciar.✅
Crear un metodo que se llame imprimirProducto(), que imprima los productos, su inventario inicial y final y determine el valor del inventario actual, con la substracción de inventario inicial menos el inventario final, que representara el consumo.✅
Considere si en los incisos c y d necesita agregar algún atributo adicional. Y explique el porque lo añadio.✅
*/

#include <iostream>
using namespace std;

class Productos{

private:

    string codigoProducto, descripcionProducto;
    int inventarioInicial, inventarioFinal;

public:

 // Constructor
    Productos(string codigo, string descripcion, int inventarioIni, int inventarioFin) {
        codigoProducto = codigo;
        descripcionProducto = descripcion;
        inventarioInicial = inventarioIni;
        inventarioFinal = inventarioFin;
    }

    // Getters y Setters
    string getCodigoProducto() {
        return codigoProducto;
    }

    void setCodigoProducto(string codigo) {
        this->codigoProducto = codigo;
    }

    string getDescripcionProducto() {
        return descripcionProducto;
    }

    void setDescripcionProducto(string descripcion) {
        this->descripcionProducto = descripcion;
    }

    int getInventarioInicial() {
        return inventarioInicial;
    }

    void setInventarioInicial(int inventarioIni) {
        this->inventarioInicial = inventarioIni;
    }

    int getInventarioFinal() {
        return inventarioFinal;
    }

    void setInventarioFinal(int inventarioFin) {
        this->inventarioFinal = inventarioFin;
    }

    void venta(int unidadesVendidas) //Recibe un parametro por valor
    {
        if (unidadesVendidas > inventarioFinal) {
                cout << "Error: No hay suficiente inventario para realizar la venta." << endl;
            } else {
                inventarioFinal -= unidadesVendidas;
                cout << "Venta realizada. Nuevo inventario final: " << inventarioFinal << endl;
            }
    }
        

    void almacenar(int cantidadRecibida) {
        inventarioInicial += cantidadRecibida;
        cout << "Producto almacenado. Nuevo inventario inicial: " << inventarioInicial << endl;
    }

    void imprimirProducto(){
        cout << "Inventario Inicial: " << inventarioInicial << endl;
        cout << "Inventario Final: " << inventarioFinal << endl;
        cout << "Inventario Actual: " << (inventarioInicial-inventarioFinal) << endl;
    }
    };

int main () {

    return 0;
    
}   