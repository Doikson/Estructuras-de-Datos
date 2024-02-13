#include <iostream>
using namespace std;
class Alumno 
{
    // Constructor clase alumno 
   /* Alumno()
    {
        this->materiasCursadas = 0;
        this->materiasCursando = 0;
        this->materiasPorCursar = 0;
    }*/
public:
    void setMateriasCursando(int materiasCursando) 
    {
        this->materiasCursando = materiasCursando;
    }
    void setmateriasCursadas(int materiasCursadas) 
    {
        this->materiasCursadas = materiasCursadas;
    }
    void setmateriasPorCursar(int materiasPorCursar) 
    {
        this->materiasPorCursar = materiasPorCursar;
    }
    int getMateriasCursando() 
    {
        return materiasCursando;
    }
    int getMateriasCursadas() const
    {
        return materiasCursadas;
    }
    int getMateriasPorCursar() const
    {
        return materiasPorCursar;
    }
    // atributos
public:
    int materiasCursando;
    int materiasCursadas;
    int materiasPorCursar;
};
int main()
{
    Alumno jose;
    Alumno carlos;
    jose.setMateriasCursando(5);
    jose.setmateriasCursadas(25);
    jose.setmateriasPorCursar(25);
    cout << jose.getMateriasCursadas() << endl;
    cout << jose.getMateriasCursando() << endl;
    cout << jose.getMateriasPorCursar() << endl;

}