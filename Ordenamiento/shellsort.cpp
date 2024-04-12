#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &lista) {
    int n = lista.size();
    int h = n / 2;
    cout << "h0 " << h << endl;

    while (h > 0) {
        for (int i = h; i < n; i++) {
            int temp = lista[i];
            int j = i;

            while (j >= h && lista[j - h] > temp) {
                lista[j] = lista[j - h];
                j -= h;
            }
            lista[j] = temp;
        }

        cout << "Lista: ";
        for (int num : lista) {
            cout << num << " ";
        }
        cout << endl;

        h /= 2;
        cout << " h " << h << endl;
    }
}

int main() {
    vector<int> lista = {56, 25, 12, 1};
    cout << "Lista inicial: ";
    for (int num : lista) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(lista);

    cout << "Lista final: ";
    for (int num : lista) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}