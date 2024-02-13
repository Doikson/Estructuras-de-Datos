#include <iostream>
using namespace std;

class CuentaBancaria {
    private: //En este ejemplo, la clase CuentaBancaria tiene dos atributos privados, titular y saldo.
        string titular;
        int saldo;
    public: //Los métodos públicos setTitular, setSaldo, getTitular y getSaldo son los setters y getters respectivamente que permiten establecer y obtener los valores de los atributos encapsulados.
        void setTitular(string _titular) {
            titular = _titular;
        }
        void setSaldo(int _saldo) {
            saldo = _saldo;
        }
        string getTitular() {
            return titular;
        }
        int getSaldo() {
            return saldo;
        }
};

int main() {
    CuentaBancaria cuenta;

    cuenta.setTitular("Juan Perez");
    cuenta.setSaldo(1000);

    cout << "Titular: " << cuenta.getTitular() << endl;
    cout << "Saldo: " << cuenta.getSaldo() << endl;

    return 0;
}
