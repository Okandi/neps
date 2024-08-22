#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> dpMudancas;
vector<vector<int>> dpErros;


int getDistanciaFrom(string &palavraCerta, string &palavraErrada, int i, int j) { // O(N) || O(3^N) (pior do pior do pior caso) N = palavraCerta.size() + palavraErrada.size()
    if (i == 0) return j;
    else if (j == 0) return i;
    else if (dpErros[i][j] != -1) return dpErros[i][j];
    else if (palavraCerta[i-1] == palavraErrada[j-1]) return dpErros[i][j] = getDistanciaFrom(palavraCerta, palavraErrada, i-1, j-1);
    else if (dpMudancas[i][j-1] > dpMudancas[i-1][j]) return dpErros[i][j] = getDistanciaFrom(palavraCerta, palavraErrada, i, j-1) + 1;
    else if (dpMudancas[i][j-1] < dpMudancas[i-1][j]) return dpErros[i][j] = getDistanciaFrom(palavraCerta, palavraErrada, i-1, j) + 1;
    else {
        return dpMudancas[i][j] = min(
            getDistanciaFrom(palavraCerta, palavraErrada, i-1, j-1),
            min(
                getDistanciaFrom(palavraCerta, palavraErrada, i-1, j),
                getDistanciaFrom(palavraCerta, palavraErrada, i, j-1)
            )
        ) + 1;
    }
}


int main() {
    int qtdDicionario, qtdTestes;
    cin >> qtdDicionario >> qtdTestes;

    vector<string> dicionario(qtdDicionario);

    vector<vector<string>> resultados(qtdTestes, vector<string>());

    for (int i=0; i<qtdDicionario; i++) cin >> dicionario[i];

    for (int ti=0; ti<qtdTestes; ti++) { // O(qtdTestes*qtdDicionario*(N || 3^N))
        string palavraErrada;
        cin >> palavraErrada;
        for (string palavraCerta : dicionario) {
            dpMudancas = vector<vector<int>>(palavraCerta.size()+1, vector<int>(palavraErrada.size()+1, 0));

            for (int i=1; i<=palavraCerta.size(); i++) {
                for (int j=1; j<=palavraErrada.size(); j++) {
                    if (palavraCerta[i-1] == palavraErrada[j-1]) dpMudancas[i][j] = dpMudancas[i-1][j-1] + 1;
                    else dpMudancas[i][j] = max(dpMudancas[i-1][j], dpMudancas[i][j-1]);
                }
            }

            int i=palavraCerta.size(), j=palavraErrada.size();
            dpErros = vector<vector<int>>(i+1, vector<int>(j+1, -1));
            int qtdMudanca = getDistanciaFrom(palavraCerta, palavraErrada, i, j); // O(N) || O(3^N) (pior do pior do pior caso)

            if (qtdMudanca > 2) resultados[ti].push_back("");
            else resultados[ti].push_back(palavraCerta);
        }
    }

    for (auto resultadosPorTeste : resultados) {
        for (auto palavra : resultadosPorTeste) {
            if (palavra != "") cout << palavra << " ";
        }
        cout << endl;
    }
}
