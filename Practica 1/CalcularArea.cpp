//Practica 1 CalcularArea - Jose Angel Cortes Baillet
#include <iostream>
#include <cmath>
using namespace std;

//Variables Globales
int opcion;
double resutlado,input1,input2;

//Declaracion Funciones
void Menu();
void UserInput();
void CalculaArea(double lado);
void CalculaArea(double base, double altura);

int main (){

    while (opcion !=5){

    Menu();
    
    switch (opcion)
        {
            case 1:
            UserInput();
            CalculaArea(input1);
            break;
            case 2:
            UserInput();
            CalculaArea(input1,input2);
            break;
            case 3:
            UserInput();
            CalculaArea(input1,input2);
            break;
            case 4:
            UserInput();
            CalculaArea(input1);
            break;
            case 5:
            cout << "---Seleccionaste Salir---" << endl;
            break;

            default:
            break;
        }
    }
}

//Definicion Menu
void Menu(){
    cout << "---Selecciona la Figura a la cual deseas sacar el Area---" << endl;
    cout << "1. Cuadrado" << endl;
    cout << "2. Rectangulo" << endl;
    cout << "3. Triangulo" << endl;
    cout << "4. Circulo" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: "; cin >> opcion;
}

//Definicion UserInput
void UserInput(){
    if (opcion == 1 ){
        cout << "Ingresa el valor de un lado del Cuadrado: " << endl;
        cin >> input1;
    } else if (opcion == 4) {
        cout << "Ingresa el valor del Radio del Circulo: " << endl;
        cin >> input1;
    } else {
        cout << "Ingresa el valor de la Base" << endl; cin >> input1;
        cout << "Ingresa el valor de la Altura: " << endl; cin >> input2;
    }
}

//Definicion Calcular Area (Cuadrado y Circulo)
void CalculaArea(double lado){
    if (opcion == 1){
        auto resultado = lado*lado;
        cout << "El area del cuadrado es: " << resultado << endl;
    } else {
        auto resultado = (M_PI)*(pow(lado,2)); //Lado se interpeta tambien como el radio
        cout << "El area del circulo es: " << resultado << endl;
    }
    
}

//Definicion Calcular Area (Rectangulo y Triangulo)
void CalculaArea(double base, double altura){
    if (opcion == 2){
        auto resultado = base*altura;
        cout << "El area del rectangulo es: " << resultado << endl;
    } else{
        auto resultado = (base*altura)/2;
        cout << "El area del triangulo es: " << resultado << endl;
    }    
}