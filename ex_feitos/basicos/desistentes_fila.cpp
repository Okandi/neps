#include <bits/stdc++.h>

using namespace std;


auto findFirstOccurenceOfValue(vector<int> &vetor, int value) {
    for (int i=0; i<vetor.size(); i++) {
        if (vetor[i] == value) return vetor.begin()+i;
    }
    return vetor.end();
}


int main() {
    int qtdPessoas;
    cin >> qtdPessoas;

    vector<int> fila;
    for (int i=0; i<qtdPessoas; i++) {
        int identificador;
        cin >> identificador;
        fila.push_back(identificador);
    }

    int qtdDesistentes;
    cin >> qtdDesistentes;

    for (int i=0; i<qtdDesistentes; i++) {
        int identificador;
        cin >> identificador;
        fila.erase(findFirstOccurenceOfValue(fila, identificador));
    }

    while (!fila.empty()) {
        cout << fila[0] << " ";
        fila.erase(fila.begin());
    }
    cout << endl;
}
