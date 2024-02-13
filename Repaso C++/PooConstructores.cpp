#include<iostream>
using namespace std;
class Fecha
{
private: //Atributos
    int day,month,year;
public: //Metodos
Fecha(int,int,int); //Constructor 1
Fecha(long); //Constructor 2
void mostrarfecha();

};

Fecha::Fecha(int _day, int _month, int _year) //Constructor 1

    : day(_day), month(_month), year(_year)

{

}

Fecha::Fecha(long fecha) {//Constructor 2
    year = int(fecha/10000); //Extrae el year
    month = int((fecha-year*10000)/100); //Extrae el month
    day = int(fecha-year*10000-month*100); // Extrae el year
}
void Fecha::mostrarfecha(){
    cout << "La fecha es: " << day << "/" << month << "/" << year << endl;}

int main(){

    Fecha hoy (2,18,2023);
    hoy.mostrarfecha();
    Fecha ayer (20170108);
    ayer.mostrarfecha();
    return 0;

}
