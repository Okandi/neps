#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdNumeros;
    cin >> qtdNumeros;

    int numeros[qtdNumeros];

    for (int i=0; i<qtdNumeros; i++) cin >> numeros[i];

    for (int i=0; i<qtdNumeros; i++) {
        bool trocouNessaIteracao = false;
        for (int j=0; j<qtdNumeros-1; j++) {
            if (numeros[j] > numeros[j+1]) {
                trocouNessaIteracao = true;
                swap(numeros[j], numeros[j+1]);
            }
        }
        if (!trocouNessaIteracao) break;
    }

    for (int i=0; i<qtdNumeros; i++) cout << numeros[i] << " ";
    cout << endl;
}
