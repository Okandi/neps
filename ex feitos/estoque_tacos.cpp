#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdConsultas;
    cin >> qtdConsultas;

    set<int> estoque;
    int totalFabricado = 0;
    for (int i=0; i<qtdConsultas; i++) {
        int comprimento;
        cin >> comprimento;
        if (estoque.find(comprimento) == estoque.end()) {
            totalFabricado += 2;
            estoque.insert(comprimento);
        } else estoque.erase(comprimento);
    }

    cout << totalFabricado << endl;
}
