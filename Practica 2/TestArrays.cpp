#include <iostream>
#include <vector>
using namespace std;

int main (){

    const int TAMANO = 5;
int arreglo[TAMANO]{ 1,2,3,4,5 };
arreglo[0] = 56;
for (int i = 0; i <= TAMANO; i++) 
{
	cout << arreglo[i] << endl;
}
for (auto contador : arreglo) 
{
	cout << contador << endl;
}


//class vector
vector <int> v1;
// Insertar elemenrto al final del vector
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);
v1.push_back(4);
v1.push_back(5);
for (int i = 0; i < v1.size(); i++) 
{
	cout << v1[i] << endl;
}

for (auto contador : v1) 
{
	cout << contador << endl;
}

}