#include <bits/stdc++.h>

using namespace std;


int main() {
    int dimensao;
    cin >> dimensao;

    vector<vector<int>> quadrado;
    for (int i=0; i<dimensao; i++) {
        quadrado.push_back({});
        for (int j=0; j<dimensao; j++) {
            int valor;
            cin >> valor;
            quadrado[i].push_back(valor);
        }
    }

    const int valorSoma = accumulate(quadrado[0].begin(), quadrado[0].end(), 0);

    bool deuCerto = true;
    int somaDiagonalPrincipal = 0;
    int somaDiagonalSecundaria = 0;
    for (int i=0; i<dimensao; i++) {
        int somaLinha = 0;
        int somaColuna = 0;
        for (int j=0; j<dimensao; j++) {
            somaLinha += quadrado[i][j];
            somaColuna += quadrado[j][i];
        }
        somaDiagonalPrincipal += quadrado[i][i];
        somaDiagonalSecundaria += quadrado[i][dimensao-1-i];
        if (!((somaLinha == valorSoma) && (somaColuna == valorSoma))) {
            deuCerto = false;
            break;
        }
    }

    if (deuCerto && (somaDiagonalPrincipal == valorSoma) && (somaDiagonalSecundaria == valorSoma)) {
        cout << valorSoma << endl;
    } else {
        cout << -1 << endl;
    }
}
