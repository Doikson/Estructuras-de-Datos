
#include <iostream>
#include <cstdlib>  // Incluir la biblioteca para usar rand()

using namespace std;

string randomString(int len) 
{
    string str;
    for (int i = 0; i < len; i++) // Corregir la condición del bucle para evitar exceder la longitud
    {
        char ch = 'A' + rand() % 26;
        str.push_back(ch);
    }
    return str; // Devolver la cadena generada
}

int main() {
    string nombre = randomString(20);
    cout << nombre << endl; // Agregar un salto de línea para mejorar la legibilidad

    string nombre2 = randomString(15);
    cout << nombre2 << endl; // Agregar un salto de línea para mejorar la legibilidad
    return 0;
}
