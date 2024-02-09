#include <iostream>
using namespace std;

// Estructura
struct TablaISR {
    double limiteInferior;
    double cuotaFija;
    double tasa;
};

// Variables globales
double salario, resultado;
int posicion; // Guarda una posición del Array

//Funciones
void iniciarTabla(TablaISR* ISR);

int main() {

    //Se inicia la tabla y se llena
    TablaISR ISR[11];
    iniciarTabla(ISR);

    cout << "Ingresa tu Salario: $"; 
    cin >> salario;

    // Obtención de la posicion del Limite Inferior Correspondiente
    for (int i = 0; i < 11; i++) {
        if (salario >= ISR[i].limiteInferior) {
            posicion = i;
        }
    } 

    // Ajuste de la posición para que exista dentro de los límites del Array
    if (posicion == 11){
        posicion = 10;
    }
    
    double limiteInferior = ISR[posicion].limiteInferior;
    double tasa = ISR[posicion].tasa;
    double cuotaFija = ISR[posicion].cuotaFija;

    cout << "El límite inferior es: $" << limiteInferior << endl;
    cout << "La tasa es: %" << tasa << endl;
    cout << "La Cuota Fija es: $" << cuotaFija << endl;  

    resultado = (salario - limiteInferior) - (((salario - limiteInferior) * tasa) / 100) + cuotaFija;
    cout << "El IRS estimado es: $" << resultado << endl;

    return 0;
}

void iniciarTabla(TablaISR* ISR) {
    ISR[0] = {0.01, 0.00, 1.92};
    ISR[1] = {578.53, 11.11, 6.40};
    ISR[2] = {4910.19, 288.33, 10.88};
    ISR[3] = {8629.21, 692.96, 16.00};
    ISR[4] = {10031.08, 917.26, 17.92};
    ISR[5] = {12009.95, 1271.87, 21.36};
    ISR[6] = {24222.32, 3880.44, 23.52};
    ISR[7] = {38177.70, 7162.74, 30.00};
    ISR[8] = {72887.51, 17575.69, 32.00};
    ISR[9] = {97183.34, 25350.35, 34.00};
    ISR[10] = {291550.01, 91435.02, 35.00};
}