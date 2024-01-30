#include <iostream>
#include <vector>
using namespace std;

int main (){

    vector <int> v1;
    //Insertar Elemento al Final
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    //Iterador
    for (int i=0; i< v1.size(); i++){
        cout<< v1[i] << endl;
    }

    

}