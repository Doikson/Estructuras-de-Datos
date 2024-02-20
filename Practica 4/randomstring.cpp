#include <iostream>
using namespace std;

string randomString(int len) 
{
    string str;
    for (int i = 0; i <= len; i++) 
    {
        char ch = 'A' + rand() % 26;
        str.push_back(ch);
    }
}
int main() {
  string nombre = randomString(20);
  cout << nombre;
}