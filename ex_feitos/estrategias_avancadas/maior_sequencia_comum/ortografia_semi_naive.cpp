#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdDicionario, qtdTestes;
    cin >> qtdDicionario >> qtdTestes;

    vector<string> dicionario(qtdDicionario);

    vector<vector<string>> resultados(qtdTestes, vector<string>());

    for (int i=0; i<qtdDicionario; i++) cin >> dicionario[i];

    for (int ti=0; ti<qtdTestes; ti++) {
        string palavraErrada;
        cin >> palavraErrada;
        for (string palavraCerta : dicionario) {
            vector<vector<int>> dp(palavraCerta.size()+1, vector<int>(palavraErrada.size()+1, 0));

            for (int i=1; i<=palavraCerta.size(); i++) {
                for (int j=1; j<=palavraErrada.size(); j++) {
                    if (palavraCerta[i-1] == palavraErrada[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }

            int i=palavraCerta.size(), j=palavraErrada.size();
            int qtdMudanca = 0;
            while (i != 0 && j != 0) {
                if (palavraCerta[i-1] == palavraErrada[j-1]) {
                    i--; j--;
                    continue;
                }
                else if (dp[i][j-1] == dp[i-1][j]) {
                    if (i >= 2 && j >= 2 && palavraCerta[i-2] == palavraErrada[j-2]) {
                        i--; j--;
                    } else {
                        bool couldRemoveI = i >= 2 && palavraCerta[i-2] == palavraErrada[j-1];
                        bool couldRemoveJ = j >= 2 && palavraCerta[i-1] == palavraErrada[j-2];
                        if (couldRemoveI && couldRemoveJ) {
                            if (i>j) i--;
                            else j--;
                        }
                        else if (couldRemoveI) i--;
                        else if (couldRemoveJ) j--;
                        else {j--; i--;}
                    }
                }
                else if (dp[i][j-1] > dp[i-1][j]) j--;
                else i--;
                qtdMudanca++;
            }

            qtdMudanca += i + j;

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
