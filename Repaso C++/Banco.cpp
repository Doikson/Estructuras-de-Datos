#include <iostream>
using namespace std;
//Variables Globales
int opcion;
// Declaracion funciones prototipo
void menu();
void imprimeSaldo(float saldo);
int main() 
{
  menu();
  switch (opcion)
  {
    case 1:
      int saldo1=5000;
    imprimeSaldo(saldo1);
    break;
    default:
    break;
  }
}
void imprimeSaldo(float saldo)
{
  cout<<"El saldo es: "<<saldo<<endl;
}
void menu()
{
  cout << "Bienvenido al cajero automatico" << endl;
  cout << "1. Consultar saldo" << endl;
  cout << "2. Retirar" << endl;
  cout << "3. Depositar" << endl;
  cout << "4. Salir" << endl;
  cout << "Seleccione una opcion: ";
  cin >> opcion;
  cout << "La opcion seleccionada es: " << opcion << endl;"
}