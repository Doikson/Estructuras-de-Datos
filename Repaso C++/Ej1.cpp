#include <iostream>

using namespace std;

int main() {
    // Declare a variable to store the number entered by the user
    int numero;

    // Prompt the user to enter a number
    cout << "Ingrese un numero (ingrese 0 para salir): ";
    cin >> numero;

    // Use a while loop to repeat the process until 0 is entered
    while (numero != 0) {
        // Print the number multiplied by 10
        cout << "El resultado de multiplicar " << numero << " por 10 es: " << numero * 10 << endl;

        // Prompt the user to enter another number
        cout << "Ingrese otro numero (ingrese 0 para salir): ";
        cin >> numero;
    }

    cout << "Ha ingresado 0. El programa ha terminado." << endl;

    return 0;
}
