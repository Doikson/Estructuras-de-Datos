#include <iostream>
using namespace std;

class Alumno
{
    /*
    //Constructor
    Alumno() //Se va a llamar igual que la clase
    {
        this->materiasCursadas = 0;
        this->materiasCursando = 0;
        this->materiasPorCursar = 0;
    } //Cuando se crea una instancia le va a asignar 0 a los atributos de la class
    */

    //Metodos
    public:

    //Setters:
    void setMateriasCursando (int materiasCursando)
    {
        this->materiasCursando = materiasCursando;
    }

    void setMateriasCursadas (int materiasCursadas)
    {
        this->materiasCursando = materiasCursando;
    }

    void setMateriasPorCursar(int MateriasPorCursar) //Esa variable es diferente a:
    {
                //Esta
        this->materiasPorCursar = materiasPorCursar;
    }

    //Getters
    int getMateriasCursando()
    {
        return materiasCursando;
    }
    int getMateriasCursadas()
    {
        return materiasCursadas;
    }
    int getMateriasPorCursar()
    {
        return materiasPorCursar;
    }

    //Atributos (Se ponen al final)
    private:
    int materiasCursando, materiasCursadas, materiasPorCursar;
    
};

int main (){

    Alumno jose;
    Alumno carlos;

    jose.setMateriasCursando(5);
    jose.setMateriasCursadas(25);
    jose.setMateriasPorCursar(25);

    cout << "Materias Cursando de Jose: " << jose.getMateriasCursando() << endl;
    cout << "Materias Cursadas de Jose: " << jose.getMateriasCursadas() << endl;
    cout << "Materias Por Cursar de Jose: " << jose.getMateriasPorCursar() << endl;

    //Con el getter obtengo info de la class
    //Con el setter establezco un valor a un dato de la class



}