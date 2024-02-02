#include <iostream>
using namespace std;

struct CalcularISR {
    double limite_inferior;
    double tasa;
    double cuota_fija;
};

int main() {
    double salario, resultado;
    int posicion; // Guarda una posicion del Array

    CalcularISR ISR[11]= {
        {0.01, 0.00, 1.92},
        {578.53, 11.11, 6.40},
        {4910.19, 288.33, 10.88},
        {8629.21, 692.96, 16.00},
        {10031.08, 917.26, 17.92},
        {12009.95, 1271.87, 21.36},
        {24222.32, 3880.44, 23.52},
        {38177.70, 7162.74, 30.00},
        {72887.51, 17575.69, 32.00},
        {97183.34, 25350.35, 34.00},
        {291550.01, 91435.02, 35.00}
    };

    cout << "Ingresa tu Salario: $";
    cin >> salario;

    // Obtencion del Limite Inferior Correspondiente
    for (int i = 0; i < 11; i++) {
        if (salario >= ISR[i].limite_inferior) {
            posicion = i;
        }
    }

    // Se ajusta la posicion para que exista dentro de los limites del Array
    if (posicion == 11) {
        posicion = 10;
    }

    double limite_inferior = ISR[posicion].limite_inferior;
    double tasa = ISR[posicion].tasa;
    double cuota_fija = ISR[posicion].cuota_fija;

    cout << "El limite inferior es: $" << limite_inferior << endl;
    cout << "La tasa es: %" << tasa << endl;
    cout << "La Cuota Fija es: $" << cuota_fija << endl;

    resultado = (salario-limite_inferior)-(((salario-limite_inferior)*tasa)/100) + cuota_fija;
    cout << "El IRS estimado es: $"<< resultado << endl;

    return 0;
}
