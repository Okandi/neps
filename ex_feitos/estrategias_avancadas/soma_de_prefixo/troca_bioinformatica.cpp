#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdCartas, qtdOperacoes;
    cin >> qtdCartas >> qtdOperacoes;

    int cartas[qtdCartas][2] = {};

    int trocaCartas[qtdCartas];
    fill(trocaCartas, trocaCartas+qtdCartas, 1);

    for (int i=0; i<2; i++) {
        for (int j=0; j<qtdCartas; j++) {
            cin >> cartas[j][i];
        }
    }

    int ordemComecoVirada, ordemFimVirada;
    int indexComecoVirada, indexFimVirada;
    for (int i=0; i<qtdOperacoes; i++) { // O(n)
        cin >> ordemComecoVirada >> ordemFimVirada;
        indexComecoVirada = ordemComecoVirada-1;
        indexFimVirada = ordemFimVirada-1;

        trocaCartas[indexComecoVirada] *= -1;
        if (indexFimVirada != qtdCartas-1) trocaCartas[indexFimVirada+1] *= -1;
    }

    int estado = 1;
    for (int i=0; i<qtdCartas; i++) {
        estado *= trocaCartas[i];
        if (estado > 0) cout << cartas[i][0] << " ";
        if (estado < 0) cout << cartas[i][1] << " ";
    }
    cout << endl;
}
