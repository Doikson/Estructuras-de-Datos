//Un getter es un método que devuelve el valor de un atributo encapsulado y un setter es un método que establece el valor de un atributo encapsulado.

#include<iostream>
using namespace std;

class Punto{
    private: //Atributos
        int x,y;
    public: //Metodos
        Punto();
        void setPunto(int _x, int _y);  //Establece los valores para x , y
        int getPuntoX(); //Getter x
        int getPuntoY(); //Getter y
};

Punto::Punto(){
}

void Punto::setPunto(int _x, int _y) //es un setter que establece los valores de los atributos x e y de un objeto de la clase Punto. Los parámetros _x e _y son valores de entrada que se utilizan para establecer los valores de x e y del objeto Punto.
{
    x = _x;
    y = _y;
}

int Punto::getPuntoX(){ //es un getter que devuelve el valor del atributo "x" del objeto de la clase Punto.
    return x;
}

int Punto::getPuntoY(){ // es otro getter que devuelve el valor del atributo "y" del objeto de la clase Punto.
    return y;
}

int main(){

    Punto punto1;
    punto1.setPunto(15,10);
    cout<<punto1.getPuntoX()<<endl;
    cout<<punto1.getPuntoY()<<endl;

    //  punto1.x = 15;     //Esto atributo no se puede llamar porque esta encapsulado, solo se puede llamar desde los metodos

    return 0;
}
