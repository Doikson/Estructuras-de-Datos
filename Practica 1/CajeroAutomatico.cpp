//Practica 1 Cajero Automatico - Jose Angel Cortes Baillet
#include <iostream>
using namespace std;

// Declaración de las variables globales
int opcion;
string pass = "1234";
double saldo_inicial = 2500.25, depositar, retirar;

// Declaración de las funciones
void Menu();
void ImprimirSaldo();
void OperacionRetirar();
void OperacionDepositar();

int main() {

    cout << "Ingresa tu Password" << endl;
    cin >> pass;

    do {
    
        if (pass == "1234") {
            Menu();
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    ImprimirSaldo();
                    break;
                case 2:
                    OperacionRetirar();
                    ImprimirSaldo();
                    break;                
                case 3:
                    OperacionDepositar();
                    ImprimirSaldo();
                    break;
                case 4:
                    cout << "Seleccionaste Salir" << endl;
                    break;
                default:
                    cout << "---Opción no válida---" << endl;
                    break;
            }
        } else {
            cout << "Password Incorrecta" << endl;
        }
    } while (opcion !=4);
    return 0;
}

// Declaración de la función Menu
void Menu() {
    cout << "Bienvenido al cajero automático" << endl;
    cout << "1. Consultar saldo" << endl;
    cout << "2. Retirar" << endl;
    cout << "3. Depositar" << endl;
    cout << "4. Salir" << endl;
}   

// Declaración de la función ImprimirSaldo
void ImprimirSaldo() {
    cout << "Tu saldo actual es de: $" << saldo_inicial << endl;
}

// Declaración de la funcion OperacionRetirar
void OperacionRetirar() {
    cout << "Cuánto deseas Retirar?: ";
    cin >> retirar;
    if (retirar > saldo_inicial) {
    cout << "--- La Cantidad a Retirar es Mayor que la cantidad en la Cuenta ---" << endl;
    } else {
    saldo_inicial -= retirar;
    }
}

// Declaración de la función OperacionDepositar
void OperacionDepositar() {
    cout << "Cuánto deseas Depositar?: ";
    cin >> depositar;
    saldo_inicial += depositar;
}