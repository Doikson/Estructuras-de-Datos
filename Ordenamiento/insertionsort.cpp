#include <iostream>
#include <vector>

using namespace std;

void insercionSort(vector<int> &arr) {
    int ciclo = 1;
    for (int i = 1; i < arr.size(); i++) {
        cout << "ciclo : " << ciclo << endl;
        int elemento = arr[i];
        cout << "Llave : " << elemento << endl;

        int j = i - 1;
        while (j >= 0 && elemento < arr[j]) {
            cout << "**********************************************" << endl;
            cout << "Llave : " << elemento << endl;
            cout << "arr[j] : " << arr[j] << endl;
            arr[j + 1] = arr[j];
            j--;
        }
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        arr[j + 1] = elemento;
        ciclo++;
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> lista = {32, 355, 66, 7, 8, 89, 2, 1, 5, 88, 99, 6};
    insercionSort(lista);

    return 0;
}
