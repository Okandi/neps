#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdBotas;
    cin >> qtdBotas;

    map<int, pair<int, int>> estoqueBotas;
    for (int i=0; i<qtdBotas; i++) {
        pair<int, char> bota;
        cin >> bota.first >> bota.second;

        if (estoqueBotas.find(bota.first) == estoqueBotas.end()) estoqueBotas[bota.first] = make_pair(0, 0);

        if (bota.second == 'E') estoqueBotas[bota.first].first++;
        else estoqueBotas[bota.first].second++;
    }

    int sobra = 0;
    for (auto parDeBota : estoqueBotas) {
        int diferenca = abs(parDeBota.second.first - parDeBota.second.second);
        sobra += diferenca;
    }

    cout << (qtdBotas-sobra)/2 << endl;
}
