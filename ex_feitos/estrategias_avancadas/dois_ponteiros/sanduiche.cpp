#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdPedacos, tamanhoDesejado;
    cin >> qtdPedacos >> tamanhoDesejado;

    int sanduiche[qtdPedacos*2-1] = {};

    for (int i=0; i<qtdPedacos; i++) {
        cin >> sanduiche[i];
    }

    for (int i=0; i<qtdPedacos-1; i++) {
        sanduiche[qtdPedacos+i] = sanduiche[i];
    }

    int pontaInicial = 0, pontaFinal = 0;
    int somaAcc = 0;
    int qtdDePossibilidade = 0;

    while (true) {
        while (somaAcc < tamanhoDesejado && pontaFinal-qtdPedacos < pontaInicial && pontaFinal < qtdPedacos*2-1) {
            somaAcc += sanduiche[pontaFinal];
            pontaFinal++;
        }
        if (somaAcc == tamanhoDesejado) qtdDePossibilidade++;
        if (pontaInicial < qtdPedacos-1) {
            somaAcc -= sanduiche[pontaInicial];
            pontaInicial++;
        } else break;
    }

    cout << qtdDePossibilidade << endl;
}
