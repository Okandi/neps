#include <bits/stdc++.h>

using namespace std;


int main() { // O(3n²)
    int dimensaoTabuleiro;
    cin >> dimensaoTabuleiro;

    int tabuleiro[dimensaoTabuleiro][dimensaoTabuleiro];

    for (int i=0; i<dimensaoTabuleiro; i++) {
        for (int j=0; j<dimensaoTabuleiro; j++) {
            cin >> tabuleiro[i][j];
        }
    }

    int somaLinha[dimensaoTabuleiro] = {};
    int somaColuna[dimensaoTabuleiro] = {};

    for (int i=0; i<dimensaoTabuleiro; i++) {
        for (int j=0; j<dimensaoTabuleiro; j++) {
            somaLinha[i] += tabuleiro[i][j];
            somaColuna[i] += tabuleiro[j][i];
        }
    }

    int maiorSoma = 0;
    for (int i=0; i<dimensaoTabuleiro; i++) {
        for (int j=0; j<dimensaoTabuleiro; j++) {
            int somaAtual = somaLinha[i] + somaColuna[j] - 2*(tabuleiro[i][j]);
            if (somaAtual > maiorSoma) maiorSoma = somaAtual;
        }
    }

    cout << maiorSoma << endl;
}
