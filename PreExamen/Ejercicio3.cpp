//Que hace el siguiente codigo??

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int* f(int n) 
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "i " << i << ", " << "n " << n << endl;
        a[i] = i * n;
    }
    return a;

}

int main()
{

    int j, k;
    int* p;
    j = 12;
    p = f(j);
    for (k = 0; k < 10; k++) 
    {
        cout << p[k] << endl;
    }
    cout << endl;
}