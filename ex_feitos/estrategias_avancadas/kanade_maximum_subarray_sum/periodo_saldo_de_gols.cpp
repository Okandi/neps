#include <bits/stdc++.h>

using namespace std;


#define INF 999999999;


int main() {
    vector<pair<int, pair<int, int>>> testes;
    while (true) { // O(3N)
        int qtdJogos;
        cin >> qtdJogos;

        if (qtdJogos == 0) break;

        int listaSaldoDeGol[qtdJogos];
        for (int i=0; i<qtdJogos; i++) {
            int golsAFavor, golsContra, saldoDeGols;
            cin >> golsAFavor >> golsContra;
            saldoDeGols = golsAFavor - golsContra;
            listaSaldoDeGol[i] = saldoDeGols;
        }

        int somaSaldoDeGols = -INF;
        int indiceInicialMaiorSequencia[qtdJogos] = {};
        int maiorSomaAteIndice[qtdJogos] = {};
        maiorSomaAteIndice[0] = listaSaldoDeGol[0];

        for (int i=1; i<qtdJogos; i++) { // O(N)
            if (maiorSomaAteIndice[i-1]+listaSaldoDeGol[i] >= listaSaldoDeGol[i]) {
                maiorSomaAteIndice[i] = maiorSomaAteIndice[i-1] + listaSaldoDeGol[i];
                indiceInicialMaiorSequencia[i] = indiceInicialMaiorSequencia[i-1];
            } else {
                maiorSomaAteIndice[i] = listaSaldoDeGol[i];
                indiceInicialMaiorSequencia[i] = i;
            }
        }

        int maiorSaldo = -INF;
        int maiorIndiceInicial = 0;
        int maiorIndiceFinal = 0;
        for (int i=1; i<qtdJogos; i++) { // O(N)
            if (maiorSomaAteIndice[i] >= maiorSaldo) {
                maiorSaldo = maiorSomaAteIndice[i];
                maiorIndiceInicial = indiceInicialMaiorSequencia[i];
                maiorIndiceFinal = i;
            }
        }

        testes.push_back({maiorSaldo, {maiorIndiceInicial, maiorIndiceFinal}});
    }

    for (int i=0; i<testes.size(); i++) {
        cout << "Teste " << i+1 << endl;
        if (testes[i].first <= 0) cout << "nenhum" << endl;
        else cout << testes[i].second.first+1 << " " << testes[i].second.second+1 << endl;
        cout << endl;
    }
}
