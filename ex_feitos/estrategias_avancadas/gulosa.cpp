#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> moedas = {1, 5, 10, 25, 50, 100};
    int valorARepresentar;
    cin >> valorARepresentar;

    int qtdMoedasUsadas = 0;
    for (int i=moedas.size()-1; i>=0; i--) {
        while (moedas[i] <= valorARepresentar) {
            valorARepresentar -= moedas[i];
            qtdMoedasUsadas++;
        }
    }

    cout << qtdMoedasUsadas << endl;
}
